/*Dara Lim*/
/*Project 4 is the last project.*/
/*CS4280 */

#ifndef TOKEN_H
#define TOKEN_H

//This is the header file token
//The token defined as a class
//And has the two functions.
#include <string>
#include "symToken.h"
using namespace std;

//class token with two constructors
//and two function declarations.
class Token
{
public:
    Token(string); //Constructor take one string.
    Token(TokenSymbol, string); //constructor take token symbol and string
    string getTokenInstance();  //function declaration getTokenInstance.
    TokenSymbol getTokenSymbol(); //declaration of funciton getTokenSymbol.
    
private:
    //String tokenInstance declaration
    string tokenInstance;
    //Assign the token symbol with get token symbol function return string.
    TokenSymbol token_symbol = TokenSymbol::getTokenSymbol("");
};

#endif

