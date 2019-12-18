/*Dara Lim */
/*Project 1 */
/*CS4280 */

#include <string>
#include "token.h"
using namespace std;

Token::Token(string s)
{
    token_symbol = TokenSymbol::getTokenSymbol(s);
    tokenInstance = s;
}

TokenSymbol Token::getTokenSymbol()
{
    return token_symbol;
}

string Token::getTokenInstance()
{
    return tokenInstance;
}

Token::Token(TokenSymbol s, std::string i)
{
    //std::string str = "";
    token_symbol = s;
    tokenInstance = i;
}




