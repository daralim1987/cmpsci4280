/*
 * William Moll
 * CS4280
 * Project P2
 * 
 */

#ifndef PARSETREE_H
#define PARSETREE_H

#include <vector>
#include "token.h"

class ParseTree
{
public:
    ParseTree();
    Token *token;
    int location;
    std::string node_name;
    ParseTree *child1;
    ParseTree *child2;
    ParseTree *child3;
    ParseTree *child4;
    static void define_node(ParseTree*, std::vector<Token> &);
    static ParseTree* cfg_program(std::vector<Token> &);
    static ParseTree* cfg_block(std::vector<Token> &);
    static ParseTree* cfg_vars(std::vector<Token> &);
    static ParseTree* cfg_mvars(std::vector<Token> &);
    static ParseTree* cfg_expr(std::vector<Token> &);
    static ParseTree* cfg_m(std::vector<Token> &);
    static ParseTree* cfg_t(std::vector<Token> &);
    static ParseTree* cfg_f(std::vector<Token> &);
    static ParseTree* cfg_r(std::vector<Token> &);
    static ParseTree* cfg_stats(std::vector<Token> &);
    static ParseTree* cfg_mstat(std::vector<Token> &);
    static ParseTree* cfg_stat(std::vector<Token> &);
    static ParseTree* cfg_in(std::vector<Token> &);
    static ParseTree* cfg_out(std::vector<Token> &);
    static ParseTree* cfg_if(std::vector<Token> &);
    static ParseTree* cfg_loop(std::vector<Token> &);
    static ParseTree* cfg_assign(std::vector<Token> &);
    static ParseTree* cfg_ro(std::vector<Token> &);
    static ParseTree* cfg_terminal(std::vector<Token> &);
private:
    static void check_eof(std::vector<Token>);

};

#endif /* PARSETREE_H */

