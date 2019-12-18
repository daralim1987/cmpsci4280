/*
 * William Moll
 * CS4280
 * 
 */

#include <vector>
#include <iostream>
#include "token.h"
#include "exceptions.h"
#include "parseTree.h"

int loc_counter = 1;
ParseTree *nul = new ParseTree;

ParseTree::ParseTree()
{
    token = NULL;
    location = 0;
    node_name = "root";
    child1 = NULL;
    child2 = NULL;
    child3 = NULL;
    child4 = NULL;
}

ParseTree* ParseTree::cfg_terminal(std::vector<Token> &tokenList)
{
    if(tokenList.size() <= 0) throw ParserException("Unexpected end of file.");
    if(tokenList.front().getTokenSymbol() == TokenSymbol::eof_tk) throw ParserException("Unexpected end of file.");
    ParseTree *node = new ParseTree;
    node->node_name = "terminal";
    Token *token = new Token(tokenList.front().getTokenSymbol(), tokenList.front().getTokenInstance());
    node->token = token;
    node->location = loc_counter;
    tokenList.erase(tokenList.begin());
    loc_counter++;
    return node;
}

void ParseTree::define_node(ParseTree *node, std::vector<Token> &tokenList)
{
    node->location = loc_counter;
    Token *token = new Token(tokenList.front().getTokenSymbol(), tokenList.front().getTokenInstance());
    node->token = token;
    loc_counter++;
    tokenList.erase(tokenList.begin());
}

ParseTree* ParseTree::cfg_program(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "program";
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::program_key_tk)
    {
        //throw error (this function was called but required token not found)!!
        throw ParserException("Unexpected token in <program>.", tokenList.front().getTokenInstance(), loc_counter);
    }
    
    ParseTree::define_node(node, tokenList);
    
    node->child1 = ParseTree::cfg_vars(tokenList);
    node->child2 = ParseTree::cfg_block(tokenList);
    return node;
}

ParseTree* ParseTree::cfg_block(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "block";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::start_key_tk)
    {
        ParseTree::define_node(node, tokenList);
        node->child1 = ParseTree::cfg_vars(tokenList);
        node->child2 = ParseTree::cfg_stats(tokenList);
        if(tokenList.front().getTokenSymbol() == TokenSymbol::stop_key_tk)
        {
            ParseTree::define_node(nul, tokenList);
            return node;
        }
        else
        {
            throw ParserException("Unexpected token in <block>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <block>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_vars(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "vars";
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::int_key_tk)
    {
        // not an error, because its allowed to be empty
        return NULL;
    }
    
    ParseTree::define_node(node, tokenList);
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::id_tk)
    {
        throw ParserException("Expected identifier token", tokenList.front().getTokenInstance(), loc_counter);
        return NULL;
    }
    
    node->child1 = ParseTree::cfg_terminal(tokenList);
    
    node->child2 = ParseTree::cfg_mvars(tokenList);
    
    return node;
}

ParseTree* ParseTree::cfg_mvars(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "mvars";
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::colon_tk)
    {
        // not an error, because its allowed to be empty
        return NULL;
    }
    
    ParseTree::define_node(node, tokenList);
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::id_tk)
    {
        throw ParserException("Expected identifier token", tokenList.front().getTokenInstance(), loc_counter);
        return NULL;
    }
    
    node->child1 = ParseTree::cfg_terminal(tokenList);
    
    node->child2 = ParseTree::cfg_mvars(tokenList);
    
    return node;
}

ParseTree* ParseTree::cfg_expr(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "expr";
    
    node->child1 = ParseTree::cfg_m(tokenList);
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::asterisk_tk)
    {
        return node;
    }
    
    ParseTree::define_node(node, tokenList);
    node->child2 = ParseTree::cfg_expr(tokenList);
    
    return node;
}

ParseTree* ParseTree::cfg_m(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "m";
    
    node->child1 = ParseTree::cfg_t(tokenList);
    
    if(tokenList.front().getTokenSymbol() != TokenSymbol::slash_tk)
    {
        return node;
    }
    
    ParseTree::define_node(node, tokenList);
    node->child2 = ParseTree::cfg_m(tokenList);
    
    return node;
}

ParseTree* ParseTree::cfg_t(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "t";
    
    node->child1 = ParseTree::cfg_f(tokenList);
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::plus_tk || tokenList.front().getTokenSymbol() == TokenSymbol::minus_tk)
    {
        ParseTree::define_node(node, tokenList);
        node->child2 = ParseTree::cfg_t(tokenList);
        return node;
    }
    else
    {
        return node;
    }
}

ParseTree* ParseTree::cfg_f(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "f";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::amp_tk)
    {
        ParseTree::define_node(node, tokenList);
        node->child1 = ParseTree::cfg_f(tokenList);
        return node;
    }
    else
    {
        node->child1 = ParseTree::cfg_r(tokenList);
        return node;
    }
}

ParseTree* ParseTree::cfg_r(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "r";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::lpar_tk)
    {
        ParseTree::define_node(node, tokenList);
        node->child1 = ParseTree::cfg_expr(tokenList);
        if(tokenList.front().getTokenSymbol() != TokenSymbol::rpar_tk) throw ParserException("Expected closing parenthesis.", tokenList.front().getTokenInstance(), loc_counter);
        ParseTree::define_node(nul, tokenList);
        return node;
    }
    else if(tokenList.front().getTokenSymbol() == TokenSymbol::id_tk)
    {
        node->child1 = ParseTree::cfg_terminal(tokenList);
        return node;
    }
    else if(tokenList.front().getTokenSymbol() == TokenSymbol::int_tk)
    {
        node->child1 = ParseTree::cfg_terminal(tokenList);
        return node;
    }
    else
    {
        throw ParserException("Unexpected token in <r>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_stats(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "stats";
    
    node->child1 = ParseTree::cfg_stat(tokenList);
    node->child2 = ParseTree::cfg_mstat(tokenList);
    
    return node;
}

ParseTree* ParseTree::cfg_mstat(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "mstat";
    
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::read_key_tk:
        case TokenSymbol::print_key_tk:
        case TokenSymbol::start_key_tk:
        case TokenSymbol::decision_key_tk:
        case TokenSymbol::while_key_tk:
        case TokenSymbol::id_tk:
            node->child1 = ParseTree::cfg_stat(tokenList);
            node->child2 = ParseTree::cfg_mstat(tokenList);
            break;
        default:
            return NULL;
            break;
    }
    
    return node;
}

ParseTree* ParseTree::cfg_stat(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "stat";
    
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::read_key_tk:
            node->child1 = ParseTree::cfg_in(tokenList);
            break;
        case TokenSymbol::print_key_tk:
            node->child1 = ParseTree::cfg_out(tokenList);
            break;
        case TokenSymbol::start_key_tk:
            node->child1 = ParseTree::cfg_block(tokenList);
            break;
        case TokenSymbol::decision_key_tk:
            node->child1 = ParseTree::cfg_if(tokenList);
            break;
        case TokenSymbol::while_key_tk:
            node->child1 = ParseTree::cfg_loop(tokenList);
            break;
        case TokenSymbol::id_tk:
            node->child1 = ParseTree::cfg_assign(tokenList);
            break;
        default:
            throw ParserException("Unexpected token in <stat>.", tokenList.front().getTokenInstance(), loc_counter);
            break;
    }
    
    return node;
}

ParseTree* ParseTree::cfg_in(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "in";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::read_key_tk)
    {
        ParseTree::define_node(node, tokenList);
        
        if(tokenList.front().getTokenSymbol() == TokenSymbol::dblgt_tk)
        {
            ParseTree::define_node(nul, tokenList);
            
            if(tokenList.front().getTokenSymbol() == TokenSymbol::id_tk)
            {
                node->child1 = ParseTree::cfg_terminal(tokenList);
                
                if(tokenList.front().getTokenSymbol() == TokenSymbol::semicln_tk)
                {
                    ParseTree::define_node(nul, tokenList);
                    return node;
                }
                else
                {
                    throw ParserException("Unexpecrted token in <in>.", tokenList.front().getTokenInstance(), loc_counter);
                }
            }
            else
            {
                throw ParserException("Unexpecrted token in <in>.", tokenList.front().getTokenInstance(), loc_counter);
            }
        }
        else
        {
            throw ParserException("Unexpected token in <in>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <in>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_out(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "out";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::print_key_tk)
    {
        ParseTree::define_node(node, tokenList);
        
        if(tokenList.front().getTokenSymbol() == TokenSymbol::dbllt_tk)
        {
            ParseTree::define_node(nul, tokenList);
            
            node->child1 = ParseTree::cfg_expr(tokenList);
            
            return node;
        }
        else
        {
            throw ParserException("Unexpected token in <out>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <out>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_if(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "if";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::decision_key_tk)
    {
        ParseTree::define_node(node, tokenList);
        
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lpar_tk)
        {
            ParseTree::define_node(nul, tokenList);
            node->child1 = ParseTree::cfg_expr(tokenList);
            node->child2 = ParseTree::cfg_ro(tokenList);
            node->child3 = ParseTree::cfg_expr(tokenList);
            
            if(tokenList.front().getTokenSymbol() == TokenSymbol::rpar_tk)
            {
                ParseTree::define_node(nul, tokenList);
                node->child4 = ParseTree::cfg_block(tokenList);
                
                return node;
            }
            else
            {
                throw ParserException("Unexpected token in <if>.", tokenList.front().getTokenInstance(), loc_counter);
            }
            
        }
        else
        {
            throw ParserException("Unexpected token in <if>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <if>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_loop(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "loop";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::while_key_tk)
    {
        ParseTree::define_node(node, tokenList);
        
        if(tokenList.front().getTokenSymbol() == TokenSymbol::lpar_tk)
        {
            ParseTree::define_node(nul, tokenList);
            node->child1 = ParseTree::cfg_expr(tokenList);
            node->child2 = ParseTree::cfg_ro(tokenList);
            node->child3 = ParseTree::cfg_expr(tokenList);
            
            if(tokenList.front().getTokenSymbol() == TokenSymbol::rpar_tk)
            {
                ParseTree::define_node(nul, tokenList);
                
                node->child4 = ParseTree::cfg_block(tokenList);
                
                return node;
            }
            else
            {
                throw ParserException("Unexpected token in <loop>.", tokenList.front().getTokenInstance(), loc_counter);
            }
            
        }
        else
        {
            throw ParserException("Unexpected token in <loop>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <loop>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

ParseTree* ParseTree::cfg_assign(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "assign";
    
    if(tokenList.front().getTokenSymbol() == TokenSymbol::id_tk)
    {
        node->child1 = ParseTree::cfg_terminal(tokenList);
        
        if(tokenList.front().getTokenSymbol() == TokenSymbol::eq_tk)
        {
            ParseTree::define_node(node, tokenList);
            node->child2 = ParseTree::cfg_expr(tokenList);
            
            if(tokenList.front().getTokenSymbol() == TokenSymbol::semicln_tk)
            {
                ParseTree::define_node(nul, tokenList);
                
                return node;
            }
            else
            {
                throw ParserException("Unexpected token in <assign>.", tokenList.front().getTokenInstance(), loc_counter);
            }
        }
        else
        {
            throw ParserException("Unexpected token in <assign>.", tokenList.front().getTokenInstance(), loc_counter);
        }
    }
    else
    {
        throw ParserException("Unexpected token in <assign>.", tokenList.front().getTokenInstance(), loc_counter);
    }
}

// <RO>        ->      << | << = | >> | >> = | == | =!
ParseTree* ParseTree::cfg_ro(std::vector<Token> &tokenList)
{
    ParseTree *node = new ParseTree;
    node->node_name = "ro";
    
    switch(tokenList.front().getTokenSymbol())
    {
        case TokenSymbol::dbllt_tk:
        case TokenSymbol::dblgt_tk:
            node->child1 = ParseTree::cfg_terminal(tokenList);
            if(tokenList.front().getTokenSymbol() == TokenSymbol::eq_tk)
            {
                node->child2 = ParseTree::cfg_terminal(tokenList);
            }
            return node;
            break;
        case TokenSymbol::dbleq_tk:
        case TokenSymbol::eqex_tk:
            node->child1 = ParseTree::cfg_terminal(tokenList);
            return node;
            break;
        default:
            throw ParserException("Unexpected token in <ro>.", tokenList.front().getTokenInstance(), loc_counter);
            break;
    }
}

void ParseTree::check_eof(std::vector<Token> tokenList)
{
    if(tokenList.front().getTokenSymbol() == TokenSymbol::eof_tk)
        throw ParserException("Unexpected end of file");
}
