/*Dara Lim */
/*Project 1 */
/*CS4280 */
#include<iostream>
#include <string>
#include "symToken.h"
#include "exceptHandle.h"
using namespace std;

/*Get the token symbol string function definition */
string TokenSymbol::getTokenSymbolString(TokenSymbol type)
{
    switch (type)
    {
        case Begin_key_token:
            return "Begin_key_token";
            break;
        case End_key_token:
            return "End_key_token";
            break;
        case Loop_key_token:
            return "Loop_key_token";
            break;
        case Void_key_token:
            return "Void_key_token";
            break;
        case INT_key_token:
            return "INT_key_token";
            break;
        case Return_key_token:
            return "Return_key_token";
            break;
        case Read_key_token:
            return "Read_key_token";
            break;
        case Output_key_token:
            return "Output_key_token";
            break;
        case Program_key_token:
            return "Program_key_token";
            break;
        case IFF_key_token:
            return "IFF_key_token";
            break;
        case Then_key_token:
            return "Then_key_token";
            break;
        case Let_key_token:
            return "Let_key_token";
            break;
        case equal_token:
            return "equal_token";
            break;
        case lessThan_token:
            return "lessThan_token";
            break;
        case greatThan_token:
            return "greatThan_token";
            break;
        case colon_token:
            return "colon_token";
            break;
        case plus_token:
            return "plus_token";
            break;
        case minus_token:
            return "minus_token";
            break;
        case asterisk_token:
            return "asterisk_token";
            break;
        case slash_token:
            return "slash_token";
            break;
        case mod_token:
            return "mod_token";
            break;
        case dot_token:
            return "dot_token";
            break;
        case lparenth_token:
            return "lparenth_token";
            break;
        case rparenth_token:
            return "rparenth_token";
            break;
        case comma_token:
            return "comma_token";
            break;
        case lbrace_token:
            return "lbrace_token";
            break;
        case rbrace_token:
            return "rbrace_token";
            break;
        case semicolon_token:
            return "semicolon_token";
            break;
        case lbracket_token:
            return "lbracket_token";
            break;
        case rbracket_token:
            return "rbracket_token";
            break;
        case id_token:
            return "id_token";
            break;
        case int_token:
            return "int_token";
            break;
        case comment_token:
            return "comment_token";
            break;
        case eof_token:
            return "eof_token";
            break;
        default:
            throw ExceptionTok("Unrecognized token", "TokenSymbolFromTheString(......)");
            break;
    }
}

/*Function  get the token from string defintion */
TokenSymbol TokenSymbol::getTokenSymbolFromString(string s)
{
    if (s == "Begin_key_token")
    {
        return TokenSymbol::Begin_key_token;
    }
    else if (s == "End_key_token")
    {
        return TokenSymbol::End_key_token;
    }
    else if (s == "Loop_key_token")
    {
        return TokenSymbol::Loop_key_token;
    }
    else if (s == "Void_key_token")
    {
        return TokenSymbol::Void_key_token;
    }
    else if (s == "INT_key_token")
    {
        return TokenSymbol::INT_key_token;
    }
    else if (s == "Return_key_token")
    {
        return TokenSymbol::Return_key_token;
    }
    else if (s == "Read_key_token")
    {
        return TokenSymbol::Read_key_token;
    }
    else if (s == "Output_key_token")
    {
        return TokenSymbol::Output_key_token;
    }
    else if (s == "Program_key_token")
    {
        return TokenSymbol::Program_key_token;
    }
    else if (s == "IFF_key_token")
    {
        return TokenSymbol::IFF_key_token;
    }
    else if (s == "Then_key_token")
    {
        return TokenSymbol::Then_key_token;
    }
    else if (s == "Let_key_token"){
        return TokenSymbol::Let_key_token;
    }
    else if (s == "equal_token")
    {
        return TokenSymbol::equal_token;
    }
    else if (s == "lessThan_token")
    {
        return TokenSymbol::lessThan_token;
    }
    else if (s == "greatThan_token")
    {
        return TokenSymbol::greatThan_token;
    }
    else if (s == "colon_token")
    {
        return TokenSymbol::colon_token;
    }
    else if (s == "plus_token")
    {
        return TokenSymbol::plus_token;
    }
    else if (s == "minus_token")
    {
        return TokenSymbol::minus_token;
    }
    else if (s == "asterisk_token")
    {
        return TokenSymbol::asterisk_token;
    }
    else if (s == "slash_token")
    {
        return TokenSymbol::slash_token;
    }
    else if (s == "mod_token")
    {
        return TokenSymbol::mod_token;
    }
    else if (s == "dot_token")
    {
        return TokenSymbol::dot_token;
    }
    else if (s == "lparenth_token")
    {
        return TokenSymbol::lparenth_token;
    }
    else if (s == "rparenth_token")
    {
        return TokenSymbol::rparenth_token;
    }
    else if (s == "comma_token")
    {
        return TokenSymbol::comma_token;
    }
    else if (s == "lbrace_token")
    {
        return TokenSymbol::lbrace_token;
    }
    else if (s == "rbrace_token")
    {
        return TokenSymbol::rbrace_token;
    }
    else if (s == "semicolon_token")
    {
        return TokenSymbol::semicolon_token;
    }
    else if (s == "lbracket_token")
    {
        return TokenSymbol::lbracket_token;
    }
    else if (s == "rbracket_token")
    {
        return TokenSymbol::rbracket_token;
    }
    else if (s == "id_token")
    {
        return TokenSymbol::id_token;
    }
    else if(s == "int_token")
    {
        return TokenSymbol::int_token;
    }
    else if(s == "comment_token")
    {
        return TokenSymbol::comment_token;
    }
    else if (s == "eof_token")
    {
        return TokenSymbol::eof_token;
    }
    
    throw ExceptionTok("Invalid token type " + s, "TokenSymbolFromTheString(.......)");
}

/*Function definition of get token symbol */
TokenSymbol TokenSymbol::getTokenSymbol(string s)
{
    if(!checkAlphabet(s))
    {
        throw ExceptionTok("That is a character", s);
    }
    else if (s == "Begin")
    {
        return TokenSymbol::Begin_key_token;
    }
    else if (s == "End")
    {
        return TokenSymbol::End_key_token;
    }
    else if (s == "Loop")
    {
        return TokenSymbol::Loop_key_token;
    }
    else if (s == "Void")
    {
        return TokenSymbol::Void_key_token;
    }
    else if (s == "INT")
    {
        return TokenSymbol::INT_key_token;
    }
    else if (s == "Return")
    {
        return TokenSymbol::Return_key_token;
    }
    else if (s == "Read")
    {
        return TokenSymbol::Read_key_token;
    }
    else if (s == "Output")
    {
        return TokenSymbol::Output_key_token;
    }
    else if (s == "Program")
    {
        return TokenSymbol::Program_key_token;
    }
    else if (s == "IFF")
    {
        return TokenSymbol::IFF_key_token;
    }
    else if (s == "Then")
    {
        return TokenSymbol::Then_key_token;
    }
    else if (s == "Let")
    {
        return TokenSymbol::Let_key_token;
    }
    else if (s == "=")
    {
        return TokenSymbol::equal_token;
    }
    else if (s == "<")
    {
        return TokenSymbol::lessThan_token;
    }
    else if (s == ">")
    {
        return TokenSymbol::greatThan_token;
    }
    
    else if (s == ":")
    {
        return TokenSymbol::colon_token;
    }
    else if (s == "+")
    {
        return TokenSymbol::plus_token;
    }
    else if (s == "-")
    {
        return TokenSymbol::minus_token;
    }
    else if (s == "*")
    {
        return TokenSymbol::asterisk_token;
    }
    else if (s == "/")
    {
        return TokenSymbol::slash_token;
    }
    else if (s == "%")
    {
        return TokenSymbol::mod_token;
    }
    else if (s == ".")
    {
        return TokenSymbol::dot_token;
    }
    else if (s == "(")
    {
        return TokenSymbol::lparenth_token;
    }
    else if (s == ")")
    {
        return TokenSymbol::rparenth_token;
    }
    else if (s == ",")
    {
        return TokenSymbol::comma_token;
    }
    else if (s == "{")
    {
        return TokenSymbol::lbrace_token;
    }
    else if (s == "}")
    {
        return TokenSymbol::rbrace_token;
    }
    else if (s == ";")
    {
        return TokenSymbol::semicolon_token;
    }
    else if (s == "[")
    {
        return TokenSymbol::lbracket_token;
    }
    else if (s == "]")
    {
        return TokenSymbol::rbracket_token;
    }
    else if (isIdentifier(s))
    {
        return TokenSymbol::id_token;
    }
    else if(isInteger(s))
    {
        return TokenSymbol::int_token;
    }
    else if(isComment(s))
    {
        return TokenSymbol::comment_token;
    }
    else if(s == "")
    {
        return TokenSymbol::eof_token;
    }
    
    throw ExceptionTok("Unidentified token", s);
}

/*Function definition of check alphabet */
static bool checkAlphabet(string s)
{
    char ch;
    
    for(int j = 0; j < s.length(); j++)
    {
        ch = s[j];
        
        if(ch > 125 || ch < 32)
        {
            return false;
        }
        
        switch(ch)
        {
            case 34:
            case 36:
            case 94:
            case 95:
            case 96:
            case 124:
            case 39:
            case 63:
            case 64:
            
                return false;
                break;
            default:
                break;
        }
    }
    
    return true;
}

/*Function definition of check identifier */
static bool isIdentifier(string s)
{
    if(s.length() < 1 || s.length() > 8)
        return false;
    
    char ch;
    
    for(int j = 0; j < s.length(); j++)
    {
        ch = s[j];
        if(ch >= 'A' && ch <= 'Z'){
            return true;
        }
    }
    
    return false;
}

/*Function check integer identifier definition */
static bool isInteger(string s)
{
    if(s.length() > 8 || s.length() < 1)
        return false;
    
    char ch;
    
    for(int j = 0; j < s.length(); j++)
    {
        ch = s[j];
        if(ch <= '9' && ch >= '0')
        {
            return true;
        }
    }
    
    return false;
}

/*Function definition of check comment */
static bool isComment(string s)
{
    if(s[0] == '\\')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*Function to string defintion */
string TokenSymbol::toString()
{
    return TokenSymbol::getTokenSymbolString(t_);
}

