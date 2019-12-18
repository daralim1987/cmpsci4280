//Dara Lim
//cs4280
//Project4 is the last project
//source file of code generation
#include "codeGen.h"
#include "testTree.h"
#include "scope.h"
using namespace std;

//define the constructor
CodeGenerator::CodeGenerator(ParseTree *tree)
{
    //declare and initialize label count to 0
    labelCount = 0;
    //initialize the parseTree to tree.
    parseTree = tree;
    //delcare and initialize the tempcount to 0
    tempCount = 0;
    
}

//definition of funciton getNewTemp
string CodeGenerator::getNewTemp()
{
    tempCount++; //increment variable tempCount
    //return the string
    return "T" + to_string(tempCount);
}

//definiton of functoin getCode
string CodeGenerator::getCode()
{
    //return the code string
    return code.str();
}

//definition of function generate.
void CodeGenerator::generate()
{
    //call the function genProgram with passing parseTree as argument.
    genProgram(parseTree);
    //newline
    code << endl;
    //loop to the tempCount variable.
    for(int j = 1; j <= tempCount; j++)
    {
        //cout the output
        code << "T" << j << " 0" << endl;
    }
}

//definition of funciton generate program
void CodeGenerator::genProgram(ParseTree *node)
{
    //declare and initialize the variable scopStartCount to funciton getSize
    int scopeStartCount = scope.getSize();
    //check if the child is not Null
    if(node->child1 != NULL)
    {
        //call the function generate vars
        genVars(node->child1);
    }
    //call the function generate block.
    genBlock(node->child2);
    
    //loop to the size of container.
    for(int j = scope.getSize() - 1; j >= scopeStartCount; j--)
    {
        //call the pop funciton with object scope
        scope.pop();
        //cout the POP.
        code << "POP" << endl;
    }
    //cout the Stop
    code << "STOP" << endl;
}

//definition of funciton getNewLabel.
string CodeGenerator::getNewLabel()
{
    //increment the variable labelCount;
    labelCount++;
    //return the string
    return "L" + to_string(labelCount);
}

//definition of function generate block
void CodeGenerator::genBlock(ParseTree *node)
{
    //declare and initialize the variable scopeStartCount to function getSize
    int scopeStartCount = scope.getSize();
    //check if the node child1
    if(node->child1 != NULL)
    {
        //call the function generate the vars
        genVars(node->child1);
    }
    //call the function generate the stats
    genStats(node->child2);
    //loop through the size of vector backward.
    for(int j = scope.getSize() - 1; j >= scopeStartCount; j--)
    {
        //call the pop function
        scope.pop();
        //cout the POP
        code << "POP" << endl;
    }
}

//definiton of funciton generate the mvars
//void CodeGenerator::genMvars(ParseTree *node)
//{
//    scope.push(node->child1->token->getTokenInstance());
//    code << "PUSH" << std::endl;
//
//    if(node->child2 != NULL)
//    {
//        genMvars(node->child2);
//    }
//}

//definition of function generate the Expression
void CodeGenerator::genExpr(ParseTree *node)
{
    //check the node token
    if(node->token == NULL)
    {
        //call the function generate M.
        genA(node->child1);
    }
    //otherwise, call functoin with different node child.
    else
    {
        //call the generate expression function with child2
        genExpr(node->child2);
        //declare string tmp variable and assign to getNew temp
        string tmp = getNewTemp();
        //cout the STORE word
        code << "STORE " << tmp << endl;
        //call teh generate A function with child1
        genA(node->child1);
        //check if the node token is plus symbol token
        //then cout the ADD word
        if(node->token->getTokenSymbol() == TokenSymbol::plus_token){
            code << "ADD " << tmp << endl;
        }
        //Check if the node token is minus token
        //then cout the word SUB
        else if(node->token->getTokenSymbol() == TokenSymbol::minus_token){
            code << "SUB " << tmp << endl;
        }
    }
}

//definiton of funciton generate Vars.
void CodeGenerator::genVars(ParseTree *node)
{
    //call the push function with token instance()
    scope.push(node->child1->token->getTokenInstance());
    //cout the PUSH word.
    code << "PUSH" << endl;
    //check if the child2 is not null
    if(node->child2 != NULL)
    {
        //call recursively itself
        genVars(node->child2);
    }
}

//definiton function generate M
void CodeGenerator::genM(ParseTree *node)
{
    //check if the node token is NULL
    if(node->token == NULL)
    {
        //call the funciton
        genR(node->child1);
    }
    //check if the node token is minus token
    else if(node->token->getTokenSymbol() == TokenSymbol::minus_token)
    {
        //call the function itself with child1
        genM(node->child1);
        //cout the word MULT -1.
        code << "MULT -1" << endl;
    }
//    else
//    {
//        genM(node->child2);
//        std::string temp = getNewTemp();
//        code << "STORE " << temp << std::endl;
//        genT(node->child1);
//        code << "DIV " << temp << std::endl;
//    }
}

//definition of function gener
void CodeGenerator::genA(ParseTree *node)
{
    //check if the node token is null
    if(node->token == NULL)
    {
        //call function generate n
        genN(node->child1);
    }
    //otherwise,
    else
    {
        //call function generate A
        genA(node->child2);
        //declare string variable tmp
        string tmp = getNewTemp();
        //put integer to argument
        code << "STORE " << tmp << endl;
        //call function generate N
        genN(node->child1);
        //Multiply the argument.
        code << "MULT " << tmp << endl;
    }
}

//definition of function generate R
void CodeGenerator::genR(ParseTree *node)
{
    //check if the node name is express
    if(node->child1->nodeName == "expr")
    {
        //call the generate expression function with child 1
        genExpr(node->child1);
    }
    //check if the node token is identifier token
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::id_token)
    {
        // LOAD Identifier
        code << "STACKR " << scope.find(node->child1->token->getTokenInstance()) << endl;
    }
    //check if the node token is integer token
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::int_token)
    {
        // LOAD Number
        code << "LOAD " << node->child1->token->getTokenInstance() << endl;
    }
}

//definition of function generate N
void CodeGenerator::genN(ParseTree *node)
{
    //check if node token is null
    if(node->token == NULL)
    {
        //call the generate function M
        genM(node->child1);
    }
    //otherwise
    else
    {
        //call function N
        genN(node->child2);
        //declare string variable tmp
        string tmp = getNewTemp();
        //store in integer in argument
        code << "STORE " << tmp << endl;
        //call function generate m
        genM(node->child1);
        //divide the arguments
        code << "DIV " << tmp << endl;
    }
}

//definition of function generate stats
void CodeGenerator::genStats(ParseTree *node)
{
    //check if the node child1 is not null
        genStat(node->child1);   //call teh generate stat function
    //check if the node child2 is not null
        genMstat(node->child2); //call the function generate mState
    
}

//definition of function generate mstat.
void CodeGenerator::genMstat(ParseTree *node)
{
    //check if node not null
    if(node != NULL)
    {
        //call the function genStat with child1
        genStat(node->child1);
        //call the token
        //scope.push(node->child2->token->getTokenInstance());
        //cout the PUSH word
        //code << "PUSH" << endl;
        //call teh generate mstat function
        genMstat(node->child2);
    }
}

//definition function generate RO
void CodeGenerator::genRo(ParseTree *node, string label)
{
    //check if the child token is < token
    if(node->child1->token->getTokenSymbol() == TokenSymbol::lessThan_token)
    {
        //check if the node child2 not null and the token is equal token
        if(node->child2 != NULL && node->child2->token->getTokenSymbol() == TokenSymbol::equal_token)
        {
            //cout teh branch on positive
            code << "BRPOS " << label << endl;
        }
        //otherwise
        else
        {
            //branch on zero and positive
            code << "BRZPOS " << label << endl;
        }
    }
    //check if teh node child token is greater than token
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::greatThan_token)
    {
        //if the node token key is equal token
        if(node->child2 != NULL && node->child2->token->getTokenSymbol() == TokenSymbol::equal_token)
        {
            //cout the branch negative.
            code << "BRNEG " << label << endl;
        }
        //otherwise, branch on zero and negative
        else
        {
            code << "BRZNEG " << label << endl;
        }
    }
    //check if the node child is equal key token
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::equal_token)
    {
        //cout the branch positive
        code << "BRPOS " << label << endl;
        //cout the branch and negative
        code << "BRNEG " << label << endl;
    }
    //check if the child node is = = token key
    else if(node->child1->token->getTokenSymbol() == TokenSymbol::nEqual_token)
    {
        //cout the branch and zero
        code << "BRZERO " << label << endl;
    }
}

//definition function generate the statement.
void CodeGenerator::genStat(ParseTree *node)
{
    //check if the node name is "in"
    if(node->child1->nodeName == "in")
    {
        //call the function generate in with child 1
        genIn(node->child1);
    }
    //check if the node name is "out"
    else if(node->child1->nodeName == "out")
    {
        //call the function generate out
        genOut(node->child1);
    }
    //check if the node name is "block"
    else if(node->child1->nodeName == "block")
    {
        //call the function generate block
        genBlock(node->child1);
    }
    //check if the node name is "if"
    else if(node->child1->nodeName == "if")
    {
        //call the function generate if
        genIf(node->child1);
    }
    //check if the node name is "loop"
    else if(node->child1->nodeName == "loop")
    {
        //call the function generate loop
        genLoop(node->child1);
    }
    //check if the node name is "assign"
    else if(node->child1->nodeName == "assign")
    {
        //call the function generate assign
        genAssign(node->child1);
    }
}

//definition of function generate in
void CodeGenerator::genIn(ParseTree *node)
{
    //declare and initialize the string tmp.
    string tmp = getNewTemp();
    //code << "READ " << node->child1->token->getTokenInstance();
    //read the input integer.
    code << "READ " << tmp << endl;
    //load the argument to accumulator
    code << "LOAD " << tmp << endl;
    //call the find function through the object
    code << "STACKW " << scope.find(node->child1->token->getTokenInstance()) << endl;
}

//definition of function generate if
void CodeGenerator::genIf(ParseTree *node)
{
    //call the function generate expression
    genExpr(node->child3);
    //declare string tmp and initialize to new temp
    string tmp = getNewTemp();
    //Put the accumulator to argument
    code << "STORE " << tmp << endl;
    //call the generate express function
    genExpr(node->child1);
    //sub the temp
    code << "SUB " << tmp << endl;
    //declare the label string
    string label = getNewLabel();
    //call teh generate Ro function
    genRo(node->child2, label);
    //call teh generate stat function
    genStat(node->child4);
    //The label NOOP.
    code << label << ": NOOP" << endl;
}

//definiton of function generate loop
void CodeGenerator::genLoop(ParseTree *node)
{
    //declare string label1
    string label1 = getNewLabel();
    //label1 noop
    code << label1 << ": NOOP" << endl;
    //call generate expression function
    genExpr(node->child3);
    //delcare string variable temp
    string tmp = getNewTemp();
    //put accumulator to argument
    code << "STORE " << tmp << endl;
    //call the generate funciton expression
    genExpr(node->child1);
    //Sub the tmp variable
    code << "SUB " << tmp << endl;
    //delcare string variable and initialize
    string label2 = getNewLabel();
    //call the function Ro
    genRo(node->child2, label2);
    //call the function generate Stat
    genStat(node->child4);
    //branch to label1
    code << "BR " << label1 << endl;
    //cout the label 2.
    code << label2 << ": NOOP" << endl;
}

//definiton of funciton generate out
void CodeGenerator::genOut(ParseTree *node)
{
    //call the function generate expression
    genExpr(node->child1);
    //declare the string variable tmp
    string tmp = getNewTemp();
    //put the accumulator back to argument
    code << "STORE " << tmp << endl;
    //print out the argument.
    code << "WRITE " << tmp << endl;
}

//defintion of function generate assign
void CodeGenerator::genAssign(ParseTree *node)
{
    //call the function generate expression
    genExpr(node->child2);
    //call the find functon on to find element in the stack.
    code << "STACKW " << scope.find(node->child1->token->getTokenInstance()) << endl;
}


