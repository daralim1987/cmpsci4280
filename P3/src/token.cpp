/*
 * William Moll
 * CS4280
 * Project P2
 * 
 */

#include <string>
#include "token.h"

Token::Token(TokenSymbol s, std::string i)
{
    //std::string str = "";
    token_symbol = s;
    token_instance = i;
}

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