/*
 * Dara Lim
 * CS4280
 * Project P4 is the last project.
 *
 */
#include <iostream>
#include <vector>
#include "token.h"
#include "exceptHandle.h"
#include "testTree.h"
using namespace std;

//The testTree source file start from here.
//Declare nul as pointer to ParseTree.
ParseTree * nul = new ParseTree;
//Declare integer variable locationCounter with initialize value to 1.
int locationCounter = 1;
//ParseTree constructor
ParseTree::ParseTree()
{
    //Assign token to null
    token = NULL;
    //Assign location to initial value 0
    location = 0;
    //Assign node name to root string.
    nodeName = "root";
    //Initial child1 to null
    child1 = NULL;
    //initialize child2 to null
    child2 = NULL;
    //Initialize child3 to null
    child3 = NULL;
    //Initialize child4 to null
    child4 = NULL;
}

//Fucntion terminal bnf definition.
//This function check if the grammar is terminal token
ParseTree* ParseTree::bnf_terminal(vector<Token> &tokenList)
{
    //There is an error if the vector size is 0 or below.
    if(tokenList.size() <= 0) throw ParserException("That is the end of file.");
    //There is also error of end of file if the end of file token in the front of vector.
    if(tokenList.front().getTokenSymbol() == TokenSymbol::eof_token) throw ParserException("That is the end of file unexpected.");
    //Create node of parse tree.
    ParseTree *node = new ParseTree;
    //node name is assigned to terminal
    node->nodeName = "terminal";
    //reinitialize the token
    Token *token = new Token(tokenList.front().getTokenSymbol(), tokenList.front().getTokenInstance());
    //assign token to node token
    node->token = token;
    //Counter location to location
    node->location = locationCounter;
    //Delete the begin element of vector
    tokenList.erase(tokenList.begin());
    locationCounter++;
    return node;        //return node of parse tree.
}

//Funciton definition of program bnf.
ParseTree* ParseTree::bnf_program(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->nodeName = "program";

    //Define the node funciton called here
    ParseTree::define_node(node, tokenList);
    //Assign child 1 to vars bnf
    node->child1 = ParseTree::bnf_vars(tokenList);
    //Assign child 2 to block bnf
    node->child2 = ParseTree::bnf_block(tokenList);
    return node;    //return node treee.
}

//Function defintion of expression bnf.
ParseTree* ParseTree::bnf_expr(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;    //Reinitialize new node of tree.
    node->nodeName = "expr";        //assign node name to string expr
    //Assign child1 of tree to a bnf.
    node->child1 = ParseTree::bnf_a(tokenList);
    
    //Check if the front of the container is not plus token and minus token
    //and return node of tree.
    if(tokenList.front().getTokenSymbol() == TokenSymbol::plus_token || tokenList.front().getTokenSymbol() == TokenSymbol::minus_token)
    {
        ParseTree::define_node(node, tokenList);
        node->child2 = ParseTree::bnf_expr(tokenList);
        return node;    //return node
    }
    else{
        return node;
    }
}

//Function definition of block bnf
ParseTree* ParseTree::bnf_block(vector<Token> &tokenList)
{
    //Reinitialize the node of tree.
    ParseTree *node = new ParseTree;
    //Assign the node name to block string
    node->nodeName = "block";
    
    //Check if the front of the vector container is Begin key token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::Begin_key_token)
    {
        //Call the define node function here.
        ParseTree::define_node(node, tokenList);
        //Assign child1 of tree to vars bnf
        node->child1 = ParseTree::bnf_vars(tokenList);
        //Assign the child2 of tree to stats bnf
        node->child2 = ParseTree::bnf_stats(tokenList);
        //Check the front of container is End key token
        if(tokenList.front().getTokenSymbol() == TokenSymbol::End_key_token)
        {
            ParseTree::define_node(nul, tokenList); //Call define node funciton here
            return node;        //return node of the tree.
        }
        //Otherwise, no token expected to be in the block bnf.
        else{
            throw ParserException("Token error in <block>", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //Otherwise, no expected the token in here.
    else{
        cout << "Unexpected token in block" << endl;
    }
//    else
//    {
//        throw ParserException("There is an Unexpected token in <block>.", tokenList.front().getTokenInstance(), locationCounter);
//    }
}

//Defintion of function define node.
void ParseTree::define_node(ParseTree *node, vector<Token> &tokenList)
{
    //assign the location counter to location
    node->location = locationCounter;
    //Create the token of type class Token
    Token *token = new Token(tokenList.front().getTokenSymbol(), tokenList.front().getTokenInstance());
    //Assign token to node token
    node->token = token;
    //increment the location counter
    locationCounter++;
    //Delete the first element of vector.
    tokenList.erase(tokenList.begin());
}

//Definition of function vars bnf
ParseTree* ParseTree::bnf_vars(vector<Token> &tokenList)
{
    //Reinitialize the node of parse tree
    ParseTree *node = new ParseTree;
    //Assign the node name to string vars
    node->nodeName = "vars";
    //Check if the front of the container is Integer type token or not
    if(tokenList.front().getTokenSymbol() != TokenSymbol::INT_key_token)
    {
        //Can be empty allowed.
        return NULL;        //return nothing
    }
    //call the define node function here.
    ParseTree::define_node(node, tokenList);
    //Check again if the front of the vector is not identifier
    //then throw an error.
    if(tokenList.front().getTokenSymbol() != TokenSymbol::id_token)
    {
        throw ParserException("There is an identifier token expected", tokenList.front().getTokenInstance(), locationCounter);
        return NULL;
    }
    //Check the front of container is not integer token
    //then throw error
    if(tokenList.front().getTokenSymbol() != TokenSymbol::int_token)
    {
        throw ParserException("Expected integer token", tokenList.front().getTokenInstance(), locationCounter);
        return NULL;
    }
    //Assign the child1 of tree to terminal bnf
    node->child1 = ParseTree::bnf_terminal(tokenList);
    //Assign child2 of tree to vars bnf
    node->child2 = ParseTree::bnf_vars(tokenList);
    
    return node;    //return node
}

//definition of funciton non terminal a
ParseTree* ParseTree::bnf_a(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;    //Reinitialize the node
    //Assign the node name to character A
    node->nodeName = "A";
    //Child1 is now n bnf
    node->child1 = ParseTree::bnf_n(tokenList);
    //Check if the front of the container is not * token
    if(tokenList.front().getTokenSymbol() != TokenSymbol::asterisk_token)
    {
        return node;    //return node
    }
    //call the define node here
    ParseTree::define_node(node, tokenList);
    //assign the child2 to a bnf
    node->child2 = ParseTree::bnf_a(tokenList);
    
    return node;    //return node
}

//Definition of function mstat
ParseTree* ParseTree::bnf_mstat(vector<Token> &tokenList)
{
    //Reinitialize the node of tree
    ParseTree *node = new ParseTree;
    //node name is now mstat
    node->nodeName = "mstat";
    //Start the switch statement.
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::Read_key_token:   //case Read key token
        case TokenSymbol::Output_key_token:     //Case Output key token
        case TokenSymbol::Begin_key_token:  //case begin key token
        case TokenSymbol::IFF_key_token:        //case iff key token
        case TokenSymbol::Loop_key_token:       //case loop key token
        case TokenSymbol::id_token:         //case identifier key token
            node->child1 = ParseTree::bnf_stat(tokenList);      //assign the child1 to stat bnf function
//            if(tokenList.front().getTokenSymbol() != TokenSymbol::colon_token){
//                throw ParserException("There is unexpected token in <mstats>.",
//                                      tokenList.front().getTokenInstance(), locationCounter);
//            }
            node->child2 = ParseTree::bnf_mstat(tokenList);     //Assign the child2 to mstat bnf function
            break;
        default:
            return NULL;    //return null in condition of default
            break;
    }
    //Return the node
    return node;
}

//Definition of function n bnf
ParseTree* ParseTree::bnf_n(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;    //Reinitialize the node
    //assign the node name to character N
    node->nodeName = "N";
    //Assign childe1 to function m bnf
    node->child1 = ParseTree::bnf_m(tokenList);
    //check if the front of vector is slash token
    if(tokenList.front().getTokenSymbol() != TokenSymbol::slash_token)
    {
        return node;
    }
    //Otherwise
    ParseTree::define_node(node, tokenList);
    node->child2 = ParseTree::bnf_n(tokenList);
    return node;
}

//definition of function m bnf
ParseTree* ParseTree::bnf_m(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;    //reinitialize the node of tree
    //Now the node name is M
    node->nodeName = "M";
    //Check if the front of vector is minus token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::minus_token)
    {
        ParseTree::define_node(node, tokenList);    //call the define node function here
        //assign child1 of tree to function m bnf
        node->child1 = ParseTree::bnf_m(tokenList);
        return node;    //return node
    }
    //Otherwise, assign child1 to r bnf function
    else
    {
        node->child1 = ParseTree::bnf_r(tokenList); //assignment
        //return node of tree
        return node;
    }
}

//definition of bnf r function
ParseTree* ParseTree::bnf_r(vector<Token> &tokenList)
{
    //reinitialize the node here
    ParseTree *node = new ParseTree;
    //now the node name is R
    node->nodeName = "R";
    //check the front of vector is [ token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::lbracket_token)
    {
        //call the define node
        ParseTree::define_node(node, tokenList);
        //assign child1 to bnf expression function
        node->child1 = ParseTree::bnf_expr(tokenList);
        //check the front of vector again
        //then throw error base on the condition
        if(tokenList.front().getTokenSymbol() != TokenSymbol::rbracket_token) throw ParserException("There should be an closing bracket.", tokenList.front().getTokenInstance(), locationCounter);
        //call the define node function
        ParseTree::define_node(nul, tokenList);
        return node;    //return node
    }
    //check the front container if it is the identifier token
    else if(tokenList.front().getTokenSymbol() == TokenSymbol::id_token)
    {
        node->child1 = ParseTree::bnf_terminal(tokenList);  //assign the child1 to bnf terminal function
        return node;    //return node
    }
    //check if the front of container vector is integer token
    else if(tokenList.front().getTokenSymbol() == TokenSymbol::int_token)
    {
        node->child1 = ParseTree::bnf_terminal(tokenList);  //assign the child1 of tree to terminal bnf fucntion
        return node;    //return node.
    }
    //Otherwise, throw an error.
    else
    {
        throw ParserException("There is an unexpected token in <R>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}

//definition of function stat bnf
ParseTree* ParseTree::bnf_stats(vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;    //reinitialize the node of tree
    node->nodeName = "stats";       //now the node name is stats
    
    node->child1 = ParseTree::bnf_stat(tokenList);  //assign child1 to stat bnf function
    //check if the front of container is colon token
    //then throw an error base on condition
    if(tokenList.front().getTokenSymbol() != TokenSymbol::colon_token){
//        throw ParserException("Expected colon token", tokenList.front().getTokenInstance(), locationCounter);
        return node;
    }
    ParseTree::define_node(node, tokenList);
    //assign child2 to mstat bnf function
    node->child2 = ParseTree::bnf_mstat(tokenList);
    
    return node;    //return node.
}

//definiton of function stat bnf
ParseTree* ParseTree::bnf_stat(vector<Token> &tokenList)
{
    /** <stat>      ->      <in> | <out> | <block> | <if> | <loop> | <assign> **/
    ParseTree *node = new ParseTree;
    node->nodeName = "stat";    //node name now is stat
    
    //switch statement start here
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::Read_key_token:   //case Read key token
            node->child1 = ParseTree::bnf_in(tokenList);    //assign child1
            break;
        case TokenSymbol::Output_key_token: //case output key token
            node->child1 = ParseTree::bnf_out(tokenList);   //assign child1
            break;
        case TokenSymbol::Begin_key_token:  //case begin key token
            node->child1 = ParseTree::bnf_block(tokenList);     //assign child 1
            break;
        case TokenSymbol::IFF_key_token:    //case Iff key token
            node->child1 = ParseTree::bnf_if(tokenList);    //assign child1
            break;
        case TokenSymbol::Loop_key_token:   //case loop key token
            node->child1 = ParseTree::bnf_loop(tokenList);  //assign child1
            break;
        case TokenSymbol::id_token:     //case id token
            node->child1 = ParseTree::bnf_assign(tokenList);    //assign child1
            break;
        //default case and throw an error.
        default:
            throw ParserException("There is an unexpected token in <stat>.", tokenList.front().getTokenInstance(), locationCounter);
            break;
    }
    //return node of tree
    return node;
}

//definition of function out bnf
ParseTree* ParseTree::bnf_out(vector<Token> &tokenList)
{
    //<out> -> Output [<expr>]
    ParseTree *node = new ParseTree;
    //The node name now is out.
    node->nodeName = "out";
    //check if the front of vector token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::Output_key_token)
    {
        //call the function define node here
        ParseTree::define_node(node, tokenList);
        //check the front of the vector token
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lbracket_token)
        {
            ParseTree::define_node(nul, tokenList); //call the define node here.
            //assign the child1
            node->child1 = ParseTree::bnf_expr(tokenList);
            //check the front of vector token
            if(tokenList.front().getTokenSymbol() == TokenSymbol::rbracket_token){
                //call the define node function here
                ParseTree::define_node(nul, tokenList);
                return node;    //return the node of the tree
            }
            //return node;
        }
        //throw an error otherwise
        else
        {
            throw ParserException("There is an unexpected token in <out>.", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //otherwise, throw error.
    else
    {
        throw ParserException("There is an unexpected token in <out>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}

//definition of function if bnf
ParseTree* ParseTree::bnf_if(vector<Token> &tokenList)
{
    /** <if>        ->    IFF [ <expr> <RO> <expr> ] <stat> **/
    ParseTree *node = new ParseTree;
    node->nodeName = "if";  //node name now is if
    //check the front of the vector token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::IFF_key_token)
    {
        //Call the define node functoin here.
        ParseTree::define_node(node, tokenList);
        //check the front of the vector token
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lbracket_token)
        {
            ParseTree::define_node(nul, tokenList); //call the define node function
            //assign the child1
            node->child1 = ParseTree::bnf_expr(tokenList);
            //assign the child2
            node->child2 = ParseTree::bnf_ro(tokenList);
            //assign the child3
            node->child3 = ParseTree::bnf_expr(tokenList);
            //check the front of vector token
            if(tokenList.front().getTokenSymbol() == TokenSymbol::rbracket_token)
            {
                ParseTree::define_node(nul, tokenList); //call the define node function
                node->child4 = ParseTree::bnf_stat(tokenList);  //assign child4
                return node;    //return node of the tree
            }
            //otherwise, throw an error
            else
            {
                throw ParserException("Ther is an unexpected token in <if>.", tokenList.front().getTokenInstance(), locationCounter);
            }
            
        }
        //otherwise, throw an error
        else
        {
            throw ParserException("There is an unexpected token in <if>.", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //otherwise, throw an error
    else
    {
        throw ParserException("There is an unexpected token in <if>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}

//definition of loop bnf function
ParseTree* ParseTree::bnf_loop(vector<Token> &tokenList)
{
    
    ParseTree *node = new ParseTree;
    node->nodeName = "loop";    //node name now is loop
    
    //check the front of the vector token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::Loop_key_token)
    {
        ParseTree::define_node(node, tokenList);    //call the define node function
        
        //check the front of vector token
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lbracket_token)
        {
            ParseTree::define_node(nul, tokenList);
            //assign child1
            node->child1 = ParseTree::bnf_expr(tokenList);
            //assign child2
            node->child2 = ParseTree::bnf_ro(tokenList);
            //assign child3
            node->child3 = ParseTree::bnf_expr(tokenList);
            //check the front of vector token
            if(tokenList.front().getTokenSymbol() == TokenSymbol::rbracket_token)
            {
                ParseTree::define_node(nul, tokenList); //call the define node function
                node->child4 = ParseTree::bnf_stat(tokenList);  //child4 is now stat bnf function
                return node;    //return node
            }
            //throw error otherwise
            else
            {
                throw ParserException("There is an unexpected token in <loop>.", tokenList.front().getTokenInstance(), locationCounter);
            }
            
        }
        //throw error otherwise
        else
        {
            throw ParserException("There is an unexpected token in <loop>.", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //throw error otherwise
    else
    {
        throw ParserException("There is an unexpected token in <loop>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}

//definition of function check the end of file
void ParseTree::check_eof(vector<Token> tokenList)
{
    //check the front token in vector.
    //then throw error if met
    if(tokenList.front().getTokenSymbol() == TokenSymbol::eof_token)
        throw ParserException("There is an unexpected end of file");
}

//definition of in bnf function
ParseTree* ParseTree::bnf_in(vector<Token> &tokenList)
{
    /** <in>        ->      read [Identifier]  **/
    ParseTree *node = new ParseTree;
    node->nodeName = "in";  //node name now is in
    //check the front of container.
    if(tokenList.front().getTokenSymbol() == TokenSymbol::Read_key_token)
    {
        //node->child1 = ParseTree::bnf_terminal(tokenList);
        ParseTree::define_node(node, tokenList);
        
        //check the front of vector.
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lbracket_token)
        {
            ParseTree::define_node(nul, tokenList); //call the define node function
            //check the front of vector is id token
            if(tokenList.front().getTokenSymbol() == TokenSymbol::id_token)
            {
                node->child1 = ParseTree::bnf_terminal(tokenList);  //assign child1
                
                //check if the front of vector is ] token
                if(tokenList.front().getTokenSymbol() == TokenSymbol::rbracket_token)
                {
                    ParseTree::define_node(nul, tokenList); //call the function define node
                    return node;
                }
                //throw an error otherwise
                else
                {
                    throw ParserException("There is an unexpecrted token in <in>.", tokenList.front().getTokenInstance(), locationCounter);
                }
            }
            //throw an error otherwise
            else
            {
                throw ParserException("There is an unexpecrted token in <in>.", tokenList.front().getTokenInstance(), locationCounter);
            }
        }
        //throw an error otherwise
        else
        {
            throw ParserException("There is an unexpected token in <in>.", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //Throw error otherwise.
    else
    {
        throw ParserException("There is an unexpected token in <in>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}

//defintion of ro bnf
ParseTree* ParseTree::bnf_ro(vector<Token> &tokenList)
{
    //<RO> -> <| = < | > | = > | = = | =
    ParseTree *node = new ParseTree;
    node->nodeName = "RO";  //node name now is RO
    //start the switch statements
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::equal_token:
            node->child1 = ParseTree::bnf_terminal(tokenList);
            if(tokenList.front().getTokenSymbol() == TokenSymbol::lessThan_token){
                node->child2 = ParseTree::bnf_terminal(tokenList);
            }
            if(tokenList.front().getTokenSymbol() == TokenSymbol::greatThan_token){
                node->child3 = ParseTree::bnf_terminal(tokenList);
            }
            return node;
            break;
        case TokenSymbol::lessThan_token:
        case TokenSymbol::greatThan_token:
        case TokenSymbol::nEqual_token:
            node->child1 = ParseTree::bnf_terminal(tokenList);
            return node;
            break;
        default:
            throw ParserException("There is unexpected token in <RO>", tokenList.front().getTokenInstance(), locationCounter);
            break;
    }
}

//definition of assign bnf function
ParseTree* ParseTree::bnf_assign(vector<Token> &tokenList)
{
    /** <assign>    ->      Identifier = <expr> ; **/
    ParseTree *node = new ParseTree;
    node->nodeName = "assign";  //node name now is assign
    //check if the front token is identifier token
    if(tokenList.front().getTokenSymbol() == TokenSymbol::id_token)
    {
        node->child1 = ParseTree::bnf_terminal(tokenList);  //assign child1 to terminal bnf function
        //check if the front of vector is equal token
        if(tokenList.front().getTokenSymbol() == TokenSymbol::equal_token)
        {
            ParseTree::define_node(node, tokenList);    //call the define node function here
            node->child2 = ParseTree::bnf_expr(tokenList);  //assign child2 of node tree to express bnf function
            
//            if(tokenList.front().getTokenSymbol() == TokenSymbol::semicolon_token){
//                ParseTree::define_node(nul, tokenList);
//                return node;
//            }
//            else{
//                throw ParserException("Unexpected token in <assign>.", tokenList.front().getTokenInstance(), locationCounter);
//            }
            
        }
        //otherwise, there is an token error.
        else
        {
            throw ParserException("There is an unexpected token in <assign>.", tokenList.front().getTokenInstance(), locationCounter);
        }
    }
    //Otherwise, throw an error base on the condition
    else
    {
        throw ParserException("There is an unexpected token in <assign>.", tokenList.front().getTokenInstance(), locationCounter);
    }
}





