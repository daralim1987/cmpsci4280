/*Dara Lim */
/*Project 4 is the last project. */
/* CS4280 */

#ifndef TOKENSYMBOL_H
#define TOKENSYMBOL_H

#include <string>
#include <iostream>

using namespace std;

//Class token symbol
//This class contain all the variable, keyword
//reserved words for the grammar language.
//The class contain enumerate type.
class TokenSymbol
{
public:
    enum Type
    {
        Begin_key_token,       //Begin key token
        End_key_token,         //End key token
        Loop_key_token,        //Loop key token
        Void_key_token,         //Void key token
        INT_key_token,          //Int key token
        Return_key_token,       //Return key token
        Read_key_token,         //Read key token
        Output_key_token,       //Output key token
        Program_key_token,      //Program key token
        IFF_key_token,          //Iff key token
        Then_key_token,         //Then key token
        Let_key_token,          //Let key token
        equal_token,            //Equal key token
        lessThan_token,         //less than key token
        greatThan_token,        //greater than key token
        colon_token,            //colon key token
        plus_token,             //plus key token
        minus_token,            //minus key token
        asterisk_token,         //Asterisk key token
        slash_token,            //slash key token
        mod_token,              //mod key token
        dot_token,              //dot key token
        lparenth_token,         //less parentheses key token
        rparenth_token,         //right parenthese key token
        comma_token,            //comma key token
        lbrace_token,           //left { key token
        rbrace_token,           //right } key token
        semicolon_token,        //semicolon key token
        lbracket_token,         //Left bracket key token
        rbracket_token,         //Right bracket key token
        id_token,               //Identifier key token
        int_token,              //Int key token
        nEqual_token,           //Not equal token
        comment_token,          //Comment key token
        eof_token               //End of file key token
    };
    //Declare variable t_ as enumerate type
    Type t_;
    //Constructor 
    TokenSymbol(Type t) : t_(t) {}
    //operator type to return the enumerate type element.
    operator Type () const {return t_;}
    //static function getTokenSymbol from the string declaration.
    static TokenSymbol getTokenSymbolFromString(string s);
    //declaration of function to get the token symbol as static.
    static TokenSymbol getTokenSymbol(string s);
    //Declaration of function get the token string symboll as static type.
    static string getTokenSymbolString(TokenSymbol type);
    //Declaration of function toString as type string.
    string toString();
};

//declaratino of function check alphabet.
static bool checkAlphabet(string);
//Declaretion of function to check comment
static bool isComment(string);
//Declaration of function to check the identifier.
static bool isIdentifier(string);
//Declaration of function to check the integer.
static bool isInteger(string);



#endif


