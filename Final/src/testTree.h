/*
 * Dara Lim
 * CS4280
 * Project P4 is the last project.
 *
 */

#ifndef PARSETREE_H
#define PARSETREE_H

#include <vector>
#include "token.h"
using namespace std;

//This is the header file of test tree
//with class ParseTree.
//This class has one constructor with four child
//and one node name, one pointer, and variable location.
class ParseTree
{
public:
    //Constructor with default parameter value
    ParseTree();
    //token pointer to Token class.
    Token *token;
    //Declare string node name variable.
    string nodeName;
    //Child1 of Parse tree
    ParseTree *child1;
    //Child2 of parse tree
    ParseTree *child2;
    //Childe3 declare of parse tree
    ParseTree *child3;
    //child4 declare of parse tree
    ParseTree *child4;
    //declare integer variable location.
    int location;
    
    //Function declarations static types for all
    //So that they are only visible in their header file and source file, not entire project.
    //declare of function program bnf of type class parse tree with static keyword.
    static ParseTree* bnf_program(vector<Token> &);
    //Declare function define the node of the tree with type static void.
    static void define_node(ParseTree*, vector<Token> &);
    //declare function mstat bnf of type class parse tree with static keyword
    static ParseTree* bnf_mstat(vector<Token> &);
    //declare function stat bnf of type class parse tree.
    static ParseTree* bnf_stat(vector<Token> &);
    //declare function block bnf of type class parse tree.
    static ParseTree* bnf_block(vector<Token> &);
    //declare function ro bnf of type class parse tree.
    static ParseTree* bnf_ro(vector<Token> &);
    //declare fucntion terminal of type class parse tree.
    static ParseTree* bnf_terminal(vector<Token> &);
    //declare function vars bnf with type class parse tree
    static ParseTree* bnf_vars(vector<Token> &);
    //declare function out bnf with type class parse treee
    static ParseTree* bnf_out(vector<Token> &);
    //declare function if bnf of type class parse tree
    static ParseTree* bnf_if(vector<Token> &);
    //declare function expr bnf with type class parse tree.
    static ParseTree* bnf_expr(vector<Token> &);
    //declare function a bnf with type class parse tree
    static ParseTree* bnf_a(vector<Token> &);
    //declare fucntion n bnf with type class parse tree.
    static ParseTree* bnf_n(vector<Token> &);
    //declare function m bnf with type class parse tree.
    static ParseTree* bnf_m(vector<Token> &);
    //declare function r bnf with type class parse tree.
    static ParseTree* bnf_r(vector<Token> &);
    //declare function stats bnf with type class parse tree.
    static ParseTree* bnf_stats(vector<Token> &);
    //declare function in bnf with type class parse tree.
    static ParseTree* bnf_in(vector<Token> &);
    //declare function loop bnf with type class pares tree.
    static ParseTree* bnf_loop(vector<Token> &);
    //declare function assign bnf with type class parse tree.
    static ParseTree* bnf_assign(vector<Token> &);
//Declare the private statice function to check the end of file.
private:
    static void check_eof(vector<Token>);           //function declaration.
    
};
//End of the header file.
#endif /* PARSETREE_H */


