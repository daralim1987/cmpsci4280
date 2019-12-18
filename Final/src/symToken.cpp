/*Dara Lim */
/*Project 4 is the last project  */
/*CS4280 */
#include<iostream>
#include <string>
#include "symToken.h"
#include "exceptHandle.h"
using namespace std;

/*Get the token symbol string function definition */
//This function definition contain the switch statement, which
//return the key token whenever the token symbol type
//encounters the switch types.
//Otherwise, this function throw the exception of unidentifier token.
string TokenSymbol::getTokenSymbolString(TokenSymbol type)
{
    //Start of switch statement
    switch (type)
    {
        //Case Begin key token and return it.
        case Begin_key_token:
            return "Begin_key_token";
            break;
        //Casse of End key token and return it
        case End_key_token:
            return "End_key_token";
            break;
        //case of Loop key token and return it
        case Loop_key_token:
            return "Loop_key_token";
            break;
        //case of Void key token and return it
        case Void_key_token:
            return "Void_key_token";
            break;
        //case of Int key token and return it
        case INT_key_token:
            return "INT_key_token";
            break;
        //case of Return key token and then it is returned
        case Return_key_token:
            return "Return_key_token";
            break;
        //case of == key token and then it is returned
        case nEqual_token:
            return "nEqual_token";
            break;
        //case of Read key token and then return it
        case Read_key_token:
            return "Read_key_token";
            break;
        //Case of Output key token
        //and then it is returned.
        case Output_key_token:
            return "Output_key_token";
            break;
        //Case of Program key token, and then it is returned.
        case Program_key_token:
            return "Program_key_token";
            break;
        //Case of Iff key token and then it is returned
        case IFF_key_token:
            return "IFF_key_token";
            break;
        //case of Then key token and then it is returned.
        case Then_key_token:
            return "Then_key_token";
            break;
        //case of Let key token
        case Let_key_token:
            return "Let_key_token";
            break;
        //case of equal key token and return it
        case equal_token:
            return "equal_token";
            break;
        //case of less than key token and return it
        case lessThan_token:
            return "lessThan_token";
            break;
        //case of greater than key token and return it
        case greatThan_token:
            return "greatThan_token";
            break;
        //case of colon key token and return it
        case colon_token:
            return "colon_token";
            break;
        //case of plus key token and return it
        case plus_token:
            return "plus_token";
            break;
        //case of minus key token and then return it
        case minus_token:
            return "minus_token";
            break;
        //case of asterisk key token and then return it.
        case asterisk_token:
            return "asterisk_token";
            break;
        //case of slash key token
        case slash_token:
            return "slash_token";
            break;
        //case of mod key token and then return it
        case mod_token:
            return "mod_token";
            break;
        //case of dot key token
        case dot_token:
            return "dot_token";
            break;
        //case of left parentheses key token and return it
        case lparenth_token:
            return "lparenth_token";
            break;
        //case of right parentheses key token and then return it
        case rparenth_token:
            return "rparenth_token";
            break;
        //case of comma key token
        case comma_token:
            return "comma_token";
            break;
        //case of left bracket key token and return it
        case lbrace_token:
            return "lbrace_token";
            break;
        //case of right bracket key token and then return it
        case rbrace_token:
            return "rbrace_token";
            break;
        //case of semicolon key token and then return it
        case semicolon_token:
            return "semicolon_token";
            break;
        //case of left { key token and return it
        case lbracket_token:
            return "lbracket_token";
            break;
        //case of right } key token and return it
        case rbracket_token:
            return "rbracket_token";
            break;
        //case of identifier key token and return it
        case id_token:
            return "id_token";
            break;
        //case of integer key token and then return it
        case int_token:
            return "int_token";
            break;
        //case of comment key token and return it
        case comment_token:
            return "comment_token";
            break;
        //case of end of file key token and return it
        case eof_token:
            return "eof_token";
            break;
        //In case of default character
        //Throws an exception errors.
        default:
            throw ExceptionTok("Not know this token", "TokenSymbolFromTheString(......)");
            break;
    }
}

/*Function  get the token symbol from string defintion */
//This function if the input string meet the token in grammar
//then return it.
TokenSymbol TokenSymbol::getTokenSymbolFromString(string s)
{
    if (s == "Begin_key_token")             //Begin key token condition
    {
        return TokenSymbol::Begin_key_token;
    }
    else if (s == "End_key_token")          //End key token condition
    {
        return TokenSymbol::End_key_token;
    }
    else if (s == "Loop_key_token")         //Loop key token condition
    {
        return TokenSymbol::Loop_key_token;
    }
    else if (s == "Void_key_token")         //Void key token condition
    {
        return TokenSymbol::Void_key_token;
    }
    else if (s == "INT_key_token")          //Int key token condition
    {
        return TokenSymbol::INT_key_token;
    }
    else if (s == "Return_key_token")       //Return key token condition
    {
        return TokenSymbol::Return_key_token;
    }
    else if (s == "Read_key_token")         //Read key token condition
    {
        return TokenSymbol::Read_key_token;
    }
    else if (s == "Output_key_token")       //Out key token condition
    {
        return TokenSymbol::Output_key_token;
    }
    else if (s == "Program_key_token")      //Program key token condition
    {
        return TokenSymbol::Program_key_token;
    }
    else if (s == "IFF_key_token")          //Iff key token conditoin
    {
        return TokenSymbol::IFF_key_token;
    }
    else if (s == "nEqual_token")           //not equal token condition
    {
        return TokenSymbol::nEqual_token;
    }
    else if (s == "Then_key_token")         //Then key token condition
    {
        return TokenSymbol::Then_key_token;
    }
    else if (s == "Let_key_token"){         //Let key token condition
        return TokenSymbol::Let_key_token;
    }
    else if (s == "equal_token")            //Equal key token condition
    {
        return TokenSymbol::equal_token;
    }
    else if (s == "lessThan_token")         //less than key token condition and return
    {
        return TokenSymbol::lessThan_token;
    }
    else if (s == "greatThan_token")        //greater than key token condition and return
    {
        return TokenSymbol::greatThan_token;
    }
    else if (s == "colon_token")            //colon key token condition and return
    {
        return TokenSymbol::colon_token;
    }
    else if (s == "plus_token")            //plus key token condition and return
    {
        return TokenSymbol::plus_token;
    }
    else if (s == "minus_token")            //minus key token and return
    {
        return TokenSymbol::minus_token;
    }
    else if (s == "asterisk_token")         //asterisk key token and return it
    {
        return TokenSymbol::asterisk_token;
    }
    else if (s == "slash_token")            //slash key token and return it
    {
        return TokenSymbol::slash_token;
    }
    else if (s == "mod_token")              //mod key token and return it
    {
        return TokenSymbol::mod_token;
    }
    else if (s == "dot_token")              //dot key token and return it
    {
        return TokenSymbol::dot_token;
    }
    else if (s == "lparenth_token")         //left parenthese condition and return it
    {
        return TokenSymbol::lparenth_token;
    }
    else if (s == "rparenth_token")         //right parenthese condition and return it
    {
        return TokenSymbol::rparenth_token;
    }
    else if (s == "comma_token")            //comma key toke condition and return it
    {
        return TokenSymbol::comma_token;
    }
    else if (s == "lbrace_token")           //left { key token condition and return it
    {
        return TokenSymbol::lbrace_token;
    }
    else if (s == "rbrace_token")           //right } key token condition and return it
    {
        return TokenSymbol::rbrace_token;
    }
    else if (s == "semicolon_token")        //semicolon key token conditon and return it
    {
        return TokenSymbol::semicolon_token;
    }
    else if (s == "lbracket_token")         //Left bracket key token conditon and return it
    {
        return TokenSymbol::lbracket_token;
    }
    else if (s == "rbracket_token")         //Right bracket key token condition and return it
    {
        return TokenSymbol::rbracket_token;
    }
    else if (s == "id_token")               //Identifier key token condition and return it
    {
        return TokenSymbol::id_token;
    }
    else if(s == "int_token")               //Integer key token condition and return it
    {
        return TokenSymbol::int_token;
    }
    else if(s == "comment_token")           //comment key token condition and return it
    {
        return TokenSymbol::comment_token;
    }
    else if (s == "eof_token")              //End of file key token condition and return it
    {
        return TokenSymbol::eof_token;
    }
    
    //Other key token from the above the program BNF
    //program throws the exception condition.
    throw ExceptionTok("The type of token is invalid " + s, "TokenSymbolFromTheString(.......)");
}

/*Function definition to get token symbol */
TokenSymbol TokenSymbol::getTokenSymbol(string s)
{
    //Check if the alphabet is not met with the requirement
    //then throw the exception, that is the character wanted.
    if(!checkAlphabet(s))
    {
        throw ExceptionTok("That is a bad character", s);
    }
    //token Begin conditoin
    else if (s == "Begin")
    {
        return TokenSymbol::Begin_key_token;
    }
    //token End condition
    else if (s == "End")
    {
        return TokenSymbol::End_key_token;
    }
    //token Loop condition
    else if (s == "Loop")
    {
        return TokenSymbol::Loop_key_token;
    }
    //token Loop condition
    else if (s == "Void")
    {
        return TokenSymbol::Void_key_token;
    }
    //token Int condition
    else if (s == "INT")
    {
        return TokenSymbol::INT_key_token;
    }
    //token Return condition
    else if (s == "Return")
    {
        return TokenSymbol::Return_key_token;
    }
    //token Read condition
    else if (s == "Read")
    {
        return TokenSymbol::Read_key_token;
    }
    //token output condition
    else if (s == "Output")
    {
        return TokenSymbol::Output_key_token;
    }
    //token Program condition
    else if (s == "Program")
    {
        return TokenSymbol::Program_key_token;
    }
    //token Iff condition
    else if (s == "IFF")
    {
        return TokenSymbol::IFF_key_token;
    }
    //token Then condtion
    else if (s == "Then")
    {
        return TokenSymbol::Then_key_token;
    }
    //token let condition
    else if (s == "Let")
    {
        return TokenSymbol::Let_key_token;
    }
    //token = condtion
    else if (s == "=")
    {
        return TokenSymbol::equal_token;
    }
    //token < condtion
    else if (s == "<")
    {
        return TokenSymbol::lessThan_token;
    }
    //token > condition
    else if (s == ">")
    {
        return TokenSymbol::greatThan_token;
    }
    //token : condition
    else if (s == ":")
    {
        return TokenSymbol::colon_token;
    }
    //token plus condition
    else if (s == "+")
    {
        return TokenSymbol::plus_token;
    }
    //token minus condition
    else if (s == "-")
    {
        return TokenSymbol::minus_token;
    }
    //token * condition
    else if (s == "*")
    {
        return TokenSymbol::asterisk_token;
    }
    //token / condition
    else if (s == "/")
    {
        return TokenSymbol::slash_token;
    }
    //token modulus condition
    else if (s == "%")
    {
        return TokenSymbol::mod_token;
    }
    //token dot condition
    else if (s == ".")
    {
        return TokenSymbol::dot_token;
    }
    //token ( condition
    else if (s == "(")
    {
        return TokenSymbol::lparenth_token;
    }
    //token ) condition
    else if (s == ")")
    {
        return TokenSymbol::rparenth_token;
    }
    //token comma conditon
    else if (s == ",")
    {
        return TokenSymbol::comma_token;
    }
    //token { condition
    else if (s == "{")
    {
        return TokenSymbol::lbrace_token;
    }
    //token } condition
    else if (s == "}")
    {
        return TokenSymbol::rbrace_token;
    }
    else if (s == "= =")
    {
        return TokenSymbol::nEqual_token;
    }
    //token ; conditon
    else if (s == ";")
    {
        return TokenSymbol::semicolon_token;
    }
    //token [ condition
    else if (s == "[")
    {
        return TokenSymbol::lbracket_token;
    }
    //token ] condition
    else if (s == "]")
    {
        return TokenSymbol::rbracket_token;
    }
    //token identifier condition
    else if (isIdentifier(s))
    {
        return TokenSymbol::id_token;
    }
    //token integer condition
    else if(isInteger(s))
    {
        return TokenSymbol::int_token;
    }
    //token comment condition
    else if(isComment(s))
    {
        return TokenSymbol::comment_token;
    }
    //token end of file condition
    else if(s == "")
    {
        return TokenSymbol::eof_token;
    }
    
    //Other than above token
    //is not identified token.
    throw ExceptionTok("Unidentified token", s);
}

/*Function definition of check alphabet */
//This function check if the alphabet meets the requirement.
static bool checkAlphabet(string s)
{
    char ch; //Declaration of character ch
    
    //Go through the string as loop
    for(int j = 0; j < s.length(); j++)
    {
        ch = s[j];  //Get each of the character in string.
        
        //If the character is out of range as specified
        //return false
        if(ch > 125 || ch < 32)
        {
            return false;
        }
        
        //Switch case of character
        switch(ch)
        {
            //These are the characters that are not in
            //the required list
            case 34:
            case 36:
            case 94:
            case 95:
            case 96:
            case 124:
            case 39:
            case 63:
            case 64:
                //Return false if the program meets the any of the above characters
                return false;
                break;
            default:
                break;
        }
    }
    //Otherwise, return true.
    return true;
}

/*Function definition of check identifier */
//This function is to check the identifier
//The identifier can be any character from A to Z
//and the numbers.
//The identifier has to start with upper case letter.
static bool isIdentifier(string s)
{
    //Check if the length is out of range as required
    //and then return false.
    if(s.length() < 1 || s.length() > 8)
        return false;
    
    char ch;  //Declaration of character ch
    
    //Loop to all the way end of string
    for(int j = 0; j < s.length(); j++)
    {
        //Get each element of string
        ch = s[j];
        //If the character is in the range of A and Z
        //return true.
        if(ch >= 'A' && ch <= 'Z'){
            return true;
        }
    }
    //Otherwise, return false.
    return false;
}

/*Function check integer identifier definition */
//In this grammar, the length of the string is maximum 8
//This function return true or false depend on the condition
static bool isInteger(string s)
{
    //If the lenght of string is out of
    //range, then return false.
    if(s.length() > 8 || s.length() < 1)
        return false;
    
    char ch;  //declare the character variable ch
    
    //loop to entire of the string length
    //If the character is out of range then return false
    for(int j = 0; j < s.length(); j++)
    {
        //Get each character from the string
        ch = s[j];
        //Check if the character is not between 0 and 9.
        if(ch <= '9' && ch >= '0')
        {
            return true;
        }
    }
    //return false if the condition is not met.
    return false;
}

/*Function definition of check comment */
//The comment in this grammar is the symbol \
//If the token start with backward slash, the program ignore the rest of the line.
static bool isComment(string s)
{
    //if the starting token is backward slash
    //then the rest is ignore and
    //return true
    if(s[0] == '\\')
    {
        return true;
    }
    //Otherwise, return false.
    else
    {
        return false;
    }
}

/*Function to string defintion */
string TokenSymbol::toString()
{
    //return the string type.
    return TokenSymbol::getTokenSymbolString(t_);
}

