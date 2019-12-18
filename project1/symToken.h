/*Dara Lim */
/*Project 1 */
/* CS4280 */

#ifndef TOKENSYMBOL_H
#define TOKENSYMBOL_H

#include <string>
using namespace std;

class TokenSymbol
{
public:
    enum Type
    {
        Begin_key_token,
        End_key_token,
        Loop_key_token,
        Void_key_token,
        INT_key_token,
        Return_key_token,
        Read_key_token,
        Output_key_token,
        Program_key_token,
        IFF_key_token,
        Then_key_token,
        Let_key_token,
        equal_token,
        lessThan_token,
        greatThan_token,
        colon_token,
        plus_token,
        minus_token,
        asterisk_token,
        slash_token,
        mod_token,
        dot_token,
        lparenth_token,
        rparenth_token,
        comma_token,
        lbrace_token,
        rbrace_token,
        semicolon_token,
        lbracket_token,
        rbracket_token,
        id_token,
        int_token,
        comment_token,
        eof_token
    };
    Type t_;
    TokenSymbol(Type t) : t_(t) {}
    operator Type () const {return t_;}
    static TokenSymbol getTokenSymbolFromString(string s);
    static TokenSymbol getTokenSymbol(string s);
    static string getTokenSymbolString(TokenSymbol type);
    
    string toString();
};

static bool checkAlphabet(string);
static bool isComment(string);
static bool isIdentifier(string);
static bool isInteger(string);



#endif


