/*
 * William Moll
 * CS4280
 * Project P1
 * 
 */

#include <string>
#include "token.h"


Token::Token(std::string str)
{
    token_symbol = TokenSymbol::getTokenSymbol(str);
    token_instance = str;
}

TokenSymbol Token::getTokenSymbol()
{
    return token_symbol;
}

std::string Token::getTokenInstance()
{
    return token_instance;
}