/*Dara Lim*/
/*Project 1*/
/*CS4280 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "symToken.h"
using namespace std;

class Token
{
public:
    Token(string);
    Token(TokenSymbol, string);
    string getTokenInstance();
    TokenSymbol getTokenSymbol();
    
private:
    string tokenInstance;
    TokenSymbol token_symbol = TokenSymbol::getTokenSymbol("");
};

#endif

