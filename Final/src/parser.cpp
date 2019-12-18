/*
 * Dara Lim
 * CS4280
 * Project 4 is the last project.
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <vector>
#include "handleInput.h"
#include "token.h"
#include "scanner.h"
#include "parser.h"
#include "testTree.h"
using namespace std;

//Function definition parser point to ParserTree
//This function return root of the pare treee.
ParseTree *parser(int argc, char** argv)
{
    //Assign the file pointer from the
    //function getFilePointer to the fp file pointer.
    FILE* fp = getFilePointer(argc, argv);
    //Declare vecotr tokenList as Token type.
    vector<Token> tokenList;
    //Declare the str string.
    string str;
    
    //While not the file is end of file
    //Perform the operations.
    while(!feof(fp))
    {
        //Try block
        try
        {
            //Assign the string from the getNextString function to string str
            str = getNextString(fp);
            //Assign the string return from the scanner function to the token.
            Token token = scanner(str);
            //Check if the symbol token return is the comment token
            //then continue the program.
            if(token.getTokenSymbol() == TokenSymbol::comment_token) continue;
            
            //Otherwise, push the token to the vector tokenList.
            tokenList.push_back(token);
            
            //std::cout << std::setw(18) << std::left << token.getTokenSymbol().toString() << token.getTokenInstance() << std::endl;
        }
        //Catch block
        catch(const exception &e)
        {
            //Close the file after it was opened.
            closeFile(fp);
            throw;
        }
    }
    //Assign the bnf_program to the
    //root of the parseTree.
    ParseTree *root = ParseTree::bnf_program(tokenList);
    
    //printTree(root, 0);
    //Return the root of the tree.
    return root;
}

//Definiton of printTree function.
//This function is type void, it just print the grammar
//language as tree shape.
void printTree(ParseTree *node, int level)
{
    int j = 0; //Declare variable integer j as a loop controller.
    //While the value j less then tab - 1 , then
    //increment the value of j variable.
    while(j <= level - 1)
    {
        cout << "--";
        j++;
    }
    //Check if the node name is terminal.
    //then perform the operations.
    if(node->nodeName == "terminal")
    {
        //if the token is identifier token
        //then output the identifier token instance.
        if(node->token->getTokenSymbol() == TokenSymbol::id_token)
        {
            cout << "The Identifier: " << node->token->getTokenInstance() << endl;
        }
        //Otherwise, if the token is integer token
        //then output the number token instance.
        else if(node->token->getTokenSymbol() == TokenSymbol::int_token)
        {
            cout << "The Number: " << node->token->getTokenInstance() << endl;
        }
        //output the other node name as speficied in the BNF
        //language.
        else
        {
            cout << "<" << node->nodeName << ">" << endl;
        }
    }
    //Otherwise cout another node name from the BNF
    //language.
    else
    {
        cout << "<" << node->nodeName << ">" << endl;
    }
    
    level++; //Increment the level variable.
    //if the child1 of the node tree not null
    //print the child1.
    if(node->child1 != NULL) printTree(node->child1, level);
    //if the child2 of the node tree is not null
    //then print it out.
    if(node->child2 != NULL) printTree(node->child2, level);
    //If the child3 of node tree is not null
    //Then print if off
    if(node->child3 != NULL) printTree(node->child3, level);
    //If the child 4 of the tree is not null
    //then print it out. 
    if(node->child4 != NULL) printTree(node->child4, level);
}

