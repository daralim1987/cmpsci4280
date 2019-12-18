/*Dara Lim */
/*Project 4 is the last project.*/
/*CS4280 */
#include <iostream>
#include <string>
#include "token.h"
using namespace std;

//Class token defintion
//Constructor with one string.
Token::Token(string s)
{
    //Assign the string return from the getTokenSymbol to token_symbol.
    token_symbol = TokenSymbol::getTokenSymbol(s);
    //Assign the string s to tokenInstance.
    tokenInstance = s;
}

//getTokenSymbol function definition
//This function just return the token symbol.
TokenSymbol Token::getTokenSymbol()
{
    return token_symbol; //return token symbol
}

//Function getTokenInstance function definition
//Return the tokenInstance.
string Token::getTokenInstance()
{
    //return the token instance.
    return tokenInstance;
}

//funciton token as type of class Token
//This function take two arguments.
Token::Token(TokenSymbol str, string j)
{
    //std::string str = "";
    //Assign the token symbol s to token_symbol.
    token_symbol = str;
    //Assing string i to tokenInstance.
    tokenInstance = j;
}




