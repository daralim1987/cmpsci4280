/*
 * William Moll
 * CS4280
 * Project P2
 * 
 */

#ifndef TOKENSYMBOL_H
#define TOKENSYMBOL_H

#include <string>

class TokenSymbol
{
public:
    enum Type
    {
        start_key_tk,       // start
        stop_key_tk,        // stop
        decision_key_tk,    // decision
        while_key_tk,       // while
        void_key_tk,        // void
        int_key_tk,         // int
        return_key_tk,      // return
        read_key_tk,        // read
        print_key_tk,       // print
        program_key_tk,     // program
        eq_tk,              // =
        dbllt_tk,           // <<
        dblgt_tk,           // >>
        eqex_tk,            // =!
        dbleq_tk,           // ==
        colon_tk,           // :
        plus_tk,            // +
        minus_tk,           // -
        asterisk_tk,        // *
        slash_tk,           // /
        amp_tk,             // &
        pct_tk,             // %
        dot_tk,             // .
        lpar_tk,            // (
        rpar_tk,            // )
        comma_tk,           // ,
        lbrace_tk,          // {
        rbrace_tk,          // }
        semicln_tk,         // ;
        lbkt_tk,            // [
        rbkt_tk,            // ]
        id_tk,              // (identifier)
        int_tk,             // (integer)
        comment_tk,          // (comment)
        eof_tk              // (end of file)
    };
    Type t_;
    TokenSymbol(Type t) : t_(t) {}
    operator Type () const {return t_;}
    static std::string getTokenSymbolString(TokenSymbol type);
    static TokenSymbol getTokenSymbolFromString(std::string str);
    static TokenSymbol getTokenSymbol(std::string str);
    std::string toString();
};

static bool check_alphabet(std::string);
static bool is_identifier(std::string);
static bool is_integer(std::string);
static bool is_comment(std::string);

#endif /* TOKENSYMBOL_H */

