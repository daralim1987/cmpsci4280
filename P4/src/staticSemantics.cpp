/*
 * William Moll
 * CS4280
 * 
 */

#include <iostream>
#include <vector>
#include "staticSemantics.h"
#include "parseTree.h"
#include "exceptions.h"

int find(std::vector<std::string> varStack, std::string str)
{
    for(int i = varStack.size() - 1; i >= 0; i--)
    {
        if(varStack[i] == str)
        {
            return i;
        }
    }
    
    return -1;
}

void printStack(std::vector<std::string> varStack)
{
    std::cout << "Stack:" << std::endl;
    for(int i = varStack.size() - 1; i >= 0; i--)
    {
        std::cout << varStack[i] << std::endl;
    }
    std::cout << "End Stack" << std::endl;
}

StaticSemantics::StaticSemantics()
{
    tree = NULL;
}

StaticSemantics::StaticSemantics(ParseTree *root)
{
    loadTree(root);
}

void StaticSemantics::loadTree(ParseTree *root)
{
    tree = root;
}

void StaticSemantics::checkTree()
{
    std::vector <std::string> localStack;
    std::vector <std::string> globalStack;
    
    traverseNode(tree, localStack, globalStack);
}

void StaticSemantics::traverseNode(ParseTree* node, std::vector<std::string> &localStack, std::vector<std::string> &globalStack)
{
    if(node == NULL)
    {
        return;
    }
    
    if(node->node_name == "program")
    {
        StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    else if(node->node_name == "block")
    {
        std::vector<std::string> blockLocalStack;
        std::vector<std::string> blockGlobalStack = globalStack;
        for(int i = 0; i < localStack.size(); i++)
        {
            blockGlobalStack.push_back(localStack[i]);
        }
        
        StaticSemantics::traverseNode(node->child1, blockLocalStack, blockGlobalStack);
        StaticSemantics::traverseNode(node->child2, blockLocalStack, blockGlobalStack);
    }
    else if(node->node_name == "in")
    {
        std::string var = node->child1->token->getTokenInstance();
        if(find(localStack, var) < 0 && find(globalStack, var) < 0)
        {
            throw StaticSemanticsException("Var ("+var+") not defined.", node->child1->location);
        }
    }
    else if(node->node_name == "assign")
    {
        std::string var = node->child1->token->getTokenInstance();
        if(find(localStack, var) < 0 && find(globalStack, var) < 0)
        {
            throw StaticSemanticsException("Var ("+var+") not defined.", node->child1->location);
        }
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    else if(node->node_name == "r")
    {
        if(node->child1->node_name == "terminal")
        {
            if(node->child1->token->getTokenSymbol() == TokenSymbol::id_tk)
            {
                std::string var = node->child1->token->getTokenInstance();
                if(find(localStack, var) < 0 && find(globalStack, var) < 0)
                {
                    throw StaticSemanticsException("Var ("+var+") not defined.", node->child1->location);
                }
            }
        }
        else
        {
            StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        }
    }
    else if(node->node_name == "vars" || node->node_name == "mvars")
    {
        std::string var = node->child1->token->getTokenInstance();
        if(find(localStack, var) >= 0)
        {
            throw StaticSemanticsException("Var ("+var+") already defined.", node->child1->location);
        }
        localStack.push_back(var);
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    else
    {
        if(node->child1 != NULL) StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        if(node->child2 != NULL) StaticSemantics::traverseNode(node->child2, localStack, globalStack);
        if(node->child3 != NULL) StaticSemantics::traverseNode(node->child3, localStack, globalStack);
        if(node->child4 != NULL) StaticSemantics::traverseNode(node->child4, localStack, globalStack);
    }
}