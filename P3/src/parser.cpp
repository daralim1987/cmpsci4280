/*
 * William Moll
 * CS4280
 * Project P2
 * 
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>
#include "inputHandler.h"
#include "token.h"
#include "scanner.h"
#include "parser.h"
#include "parseTree.h"


ParseTree *parser(int argc, char** argv)
{
    FILE* fp = get_file_pointer(argc, argv);
    std::string str;
    
    std::vector<Token> tokenList;
    
    while(!feof(fp))
    {
        try
        {
            str = get_next_string(fp);
            Token token = scanner(str);
            if(token.getTokenSymbol() == TokenSymbol::comment_tk) continue;
            
            tokenList.push_back(token);
            
            //std::cout << std::setw(18) << std::left << token.getTokenSymbol().toString() << token.getTokenInstance() << std::endl;
        }
        catch(const std::exception &e)
        {
            close_file(fp);
            throw;
        }
    }
    
    ParseTree *root = ParseTree::cfg_program(tokenList);
    
    //printTree(root, 0);
    
    return root;
}

void printTree(ParseTree *node, int tab_level)
{
    int i = 0;
    while(i <= tab_level - 1)
    {
        std::cout << "--";
        i++;
    }
    if(node->node_name == "terminal")
    {
        if(node->token->getTokenSymbol() == TokenSymbol::id_tk)
        {
            std::cout << "Identifier: " << node->token->getTokenInstance() << std::endl;
        }
        else if(node->token->getTokenSymbol() == TokenSymbol::int_tk)
        {
            std::cout << "Number: " << node->token->getTokenInstance() << std::endl;
        }
        else
        {
            std::cout << "<" << node->node_name << ">" << std::endl;
        }
    }
    else
    {
        std::cout << "<" << node->node_name << ">" << std::endl;
    }
    
    tab_level++;
    if(node->child1 != NULL) printTree(node->child1, tab_level);
    if(node->child2 != NULL) printTree(node->child2, tab_level);
    if(node->child3 != NULL) printTree(node->child3, tab_level);
    if(node->child4 != NULL) printTree(node->child4, tab_level);
}