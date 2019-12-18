/*
 * William Moll
 * CS4280
 * Project P1
 * 
 */

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "tokenSymbol.h"

class Token
{
public:
    Token(std::string);
    TokenSymbol getTokenSymbol();
    std::string getTokenInstance();
private:
    TokenSymbol token_symbol = TokenSymbol::getTokenSymbol("");
    std::string token_instance;
};

#endif /* TOKEN_H */

