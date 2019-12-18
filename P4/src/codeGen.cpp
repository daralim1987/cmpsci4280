/*
 * William Moll
 * CS4280
 * 
 */

#include "codeGen.h"
#include "parseTree.h"
#include "scope.h"

CodeGenerator::CodeGenerator(ParseTree *tree)
{
    parseTree = tree;
    tempCount = 0;
    labelCount = 0;
}

std::string CodeGenerator::getCode()
{
    return code.str();
}

std::string CodeGenerator::getNewTemp()
{
    tempCount++;
    return "T" + std::to_string(tempCount);
}

std::string CodeGenerator::getNewLabel()
{
    labelCount++;
    return "L" + std::to_string(labelCount);
}

void CodeGenerator::generate()
{
    genProgram(parseTree);
    
    code << std::endl;
    for(int i = 1; i <= tempCount; i++)
    {
        code << "T" << i << " 0" << std::endl;
    }
}

void CodeGenerator::genProgram(ParseTree *node)
{
    int scope_start_count = scope.getCount();
    
    if(node->child1 != NULL)
    {
        genVars(node->child1);
    }
    genBlock(node->child2);
    
    for(int i = scope.getCount() - 1; i >= scope_start_count; i--)
    {
        scope.pop();
        code << "POP" << std::endl;
    }
    
    code << "STOP" << std::endl;
}

void CodeGenerator::genBlock(ParseTree *node)
{
    int scope_start_count = scope.getCount();
    
    if(node->child1 != NULL)
    {
        genVars(node->child1);
    }
    
    genStats(node->child2);
    
    for(int i = scope.getCount() - 1; i >= scope_start_count; i--)
    {
        scope.pop();
        code << "POP" << std::endl;
    }
}

void CodeGenerator::genVars(ParseTree *node)
{
    scope.push(node->child1->token->getTokenInstance());
    code << "PUSH" << std::endl;
    
    if(node->child2 != NULL)
    {
        genMvars(node->child2);
    }
}

void CodeGenerator::genMvars(ParseTree *node)
{
    scope.push(node->child1->token->getTokenInstance());
    code << "PUSH" << std::endl;
    
    if(node->child2 != NULL)
    {
        genMvars(node->child2);
    }
}

void CodeGenerator::genExpr(ParseTree *node)
{
    if(node->token == NULL)
    {
        genM(node->child1);
    }
    else
    {
        genExpr(node->child2);
        std::string temp = getNewTemp();
        code << "STORE " << temp << std::endl;
        genM(node->child1);
        code << "MULT " << temp << std::endl;
    }
}

void CodeGenerator::genM(ParseTree *node)
{
    if(node->token == NULL)
    {
        genT(node->child1);
    }
    else
    {
        genM(node->child2);
        std::string temp = getNewTemp();
        code << "STORE " << temp << std::endl;
        genT(node->child1);
        code << "DIV " << temp << std::endl;
    }
}

// <T>         ->      <F> + <T> | <F> - <T> | <F>
void CodeGenerator::genT(ParseTree *node)
{
    if(node->token == NULL)
    {
        genF(node->child1);
    }
    else 
    {
        genT(node->child2);
        std::string temp = getNewTemp();
        code << "STORE " << temp << std::endl;
        genF(node->child1);
        
        if(node->token->getTokenSymbol() == TokenSymbol::plus_tk)
        {
            code << "ADD " << temp << std::endl;
        }
        else if(node->token->getTokenSymbol() == TokenSymbol::minus_tk)
        {
            code << "SUB " << temp << std::endl;
        }
    }
}

void CodeGenerator::genF(ParseTree *node)
{
    if(node->token == NULL)
    {
        genR(node->child1);
    }
    else if(node->token->getTokenSymbol() == TokenSymbol::amp_tk)
    {
        genF(node->child1);
        code << "MULT -1" << std::endl;
    }
}

void CodeGenerator::genR(ParseTree *node)
{
    if(node->child1->node_name == "expr")
    {
        genExpr(node->child1);
    }
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::id_tk)
    {
        // LOAD Identifier
        code << "STACKR " << scope.find(node->child1->token->getTokenInstance()) << std::endl;
    }
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::int_tk)
    {
        // LOAD Number
        code << "LOAD " << node->child1->token->getTokenInstance() << std::endl;
    }
}

void CodeGenerator::genStats(ParseTree *node)
{
    genStat(node->child1);
    genMstat(node->child2);
}

void CodeGenerator::genMstat(ParseTree *node)
{
    if(node != NULL)
    {
        genStat(node->child1);
        genMstat(node->child2);
    }
}

void CodeGenerator::genStat(ParseTree *node)
{
    if(node->child1->node_name == "in")
    {
        genIn(node->child1);
    }
    else if(node->child1->node_name == "out")
    {
        genOut(node->child1);
    }
    else if(node->child1->node_name == "block")
    {
        genBlock(node->child1);
    }
    else if(node->child1->node_name == "if")
    {
        genIf(node->child1);
    }
    else if(node->child1->node_name == "loop")
    {
        genLoop(node->child1);
    }
    else if(node->child1->node_name == "assign")
    {
        genAssign(node->child1);
    }
}

void CodeGenerator::genIn(ParseTree *node)
{
    std::string temp = getNewTemp();
    //code << "READ " << node->child1->token->getTokenInstance();
    code << "READ " << temp << std::endl;
    code << "LOAD " << temp << std::endl;
    code << "STACKW " << scope.find(node->child1->token->getTokenInstance()) << std::endl;
}

void CodeGenerator::genOut(ParseTree *node)
{
    genExpr(node->child1);
    std::string temp = getNewTemp();
    code << "STORE " << temp << std::endl;
    code << "WRITE " << temp << std::endl;
}

void CodeGenerator::genIf(ParseTree *node)
{
    genExpr(node->child3);
    std::string temp = getNewTemp();
    code << "STORE " << temp << std::endl;
    genExpr(node->child1);
    code << "SUB " << temp << std::endl;
    
    std::string label = getNewLabel();
    genRo(node->child2, label);
    
    genBlock(node->child4);
    
    code << label << ": NOOP" << std::endl;
}

void CodeGenerator::genLoop(ParseTree *node)
{
    std::string label1 = getNewLabel();
    code << label1 << ": NOOP" << std::endl;
    
    genExpr(node->child3);
    std::string temp = getNewTemp();
    code << "STORE " << temp << std::endl;
    genExpr(node->child1);
    code << "SUB " << temp << std::endl;
    
    std::string label2 = getNewLabel();
    genRo(node->child2, label2);
    
    genBlock(node->child4);
    
    code << "BR " << label1 << std::endl;
    
    code << label2 << ": NOOP" << std::endl;
}

void CodeGenerator::genAssign(ParseTree *node)
{
    genExpr(node->child2);
    code << "STACKW " << scope.find(node->child1->token->getTokenInstance()) << std::endl;
}

void CodeGenerator::genRo(ParseTree *node, std::string label)
{
    if(node->child1->token->getTokenSymbol() == TokenSymbol::dbllt_tk)
    {
        if(node->child2 != NULL && node->child2->token->getTokenSymbol() == TokenSymbol::eq_tk)
        {
            code << "BRPOS " << label << std::endl;
        }
        else
        {
            code << "BRZPOS " << label << std::endl;
        }
    }
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::dblgt_tk)
    {
        if(node->child2 != NULL && node->child2->token->getTokenSymbol() == TokenSymbol::eq_tk)
        {
            code << "BRNEG " << label << std::endl;
        }
        else
        {
            code << "BRZNEG " << label << std::endl;
        }
    }
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::dbleq_tk)
    {
        code << "BRPOS " << label << std::endl;
        code << "BRNEG " << label << std::endl;
    }
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::eqex_tk)
    {
        code << "BRZERO " << label << std::endl;
    }
}
