/*
 * William Moll
 * CS4280
 * 
 */

#include <string>
#include "tokenSymbol.h"
#include "exceptions.h"


std::string TokenSymbol::getTokenSymbolString(TokenSymbol type)
{
    switch (type)
    {
        case start_key_tk:
            return "start_key_tk";
            break;
        case stop_key_tk:
            return "stop_key_tk";
            break;
        case decision_key_tk:
            return "decision_key_tk";
            break;
        case while_key_tk:
            return "while_key_tk";
            break;
        case void_key_tk:
            return "void_key_tk";
            break;
        case int_key_tk:
            return "int_key_tk";
            break;
        case return_key_tk:
            return "return_key_tk";
            break;
        case read_key_tk:
            return "read_key_tk";
            break;
        case print_key_tk:
            return "print_key_tk";
            break;
        case program_key_tk:
            return "program_key_tk";
            break;
        case eq_tk:
            return "eq_tk";
            break;
        case dbllt_tk:
            return "dbllt_tk";
            break;
        case dblgt_tk:
            return "dblgt_tk";
            break;
        case eqex_tk:
            return "eqex_tk";
            break;
        case dbleq_tk:
            return "dbleq_tk";
            break;
        case colon_tk:
            return "colon_tk";
            break;
        case plus_tk:
            return "plus_tk";
            break;
        case minus_tk:
            return "minus_tk";
            break;
        case asterisk_tk:
            return "asterisk_tk";
            break;
        case slash_tk:
            return "slash_tk";
            break;
        case amp_tk:
            return "amp_tk";
            break;
        case pct_tk:
            return "pct_tk";
            break;
        case dot_tk:
            return "dot_tk";
            break;
        case lpar_tk:
            return "lpar_tk";
            break;
        case rpar_tk:
            return "rpar_tk";
            break;
        case comma_tk:
            return "comma_tk";
            break;
        case lbrace_tk:
            return "lbrace_tk";
            break;
        case rbrace_tk:
            return "rbrace_tk";
            break;
        case semicln_tk:
            return "semicln_tk";
            break;
        case lbkt_tk:
            return "lbkt_tk";
            break;
        case rbkt_tk:
            return "rbkt_tk";
            break;
        case id_tk:
            return "id_tk";
            break;
        case int_tk:
            return "int_tk";
            break;
        case comment_tk:
            return "comment_tk";
            break;
        case eof_tk:
            return "eof_tk";
            break;
        default:
            throw TokenException("Unrecognized token", "getTokenSymbolFromString(...)");
            break;
    }
}

TokenSymbol TokenSymbol::getTokenSymbolFromString(std::string str)
{
    if (str == "start_key_tk")
    {
        return TokenSymbol::start_key_tk;
    }
    else if (str == "stop_key_tk")
    {
        return TokenSymbol::stop_key_tk;
    }
    else if (str == "decision_key_tk")
    {
        return TokenSymbol::decision_key_tk;
    }
    else if (str == "while_key_tk")
    {
        return TokenSymbol::while_key_tk;
    }
    else if (str == "void_key_tk")
    {
        return TokenSymbol::void_key_tk;
    }
    else if (str == "int_key_tk")
    {
        return TokenSymbol::int_key_tk;
    }
    else if (str == "return_key_tk")
    {
        return TokenSymbol::return_key_tk;
    }
    else if (str == "read_key_tk")
    {
        return TokenSymbol::read_key_tk;
    }
    else if (str == "print_key_tk")
    {
        return TokenSymbol::print_key_tk;
    }
    else if (str == "program_key_tk")
    {
        return TokenSymbol::program_key_tk;
    }
    else if (str == "eq_tk")
    {
        return TokenSymbol::eq_tk;
    }
    else if (str == "dbllt_tk")
    {
        return TokenSymbol::dbllt_tk;
    }
    else if (str == "dblgt_tk")
    {
        return TokenSymbol::dblgt_tk;
    }
    else if (str == "eqex_tk")
    {
        return TokenSymbol::eqex_tk;
    }
    else if (str == "dbleq_tk")
    {
        return TokenSymbol::dbleq_tk;
    }
    else if (str == "colon_tk")
    {
        return TokenSymbol::colon_tk;
    }
    else if (str == "plus_tk")
    {
        return TokenSymbol::plus_tk;
    }
    else if (str == "minus_tk")
    {
        return TokenSymbol::minus_tk;
    }
    else if (str == "asterisk_tk")
    {
        return TokenSymbol::asterisk_tk;
    }
    else if (str == "slash_tk")
    {
        return TokenSymbol::slash_tk;
    }
    else if (str == "amp_tk")
    {
        return TokenSymbol::amp_tk;
    }
    else if (str == "pct_tk")
    {
        return TokenSymbol::pct_tk;
    }
    else if (str == "dot_tk")
    {
        return TokenSymbol::dot_tk;
    }
    else if (str == "lpar_tk")
    {
        return TokenSymbol::lpar_tk;
    }
    else if (str == "rpar_tk")
    {
        return TokenSymbol::rpar_tk;
    }
    else if (str == "comma_tk")
    {
        return TokenSymbol::comma_tk;
    }
    else if (str == "lbrace_tk")
    {
        return TokenSymbol::lbrace_tk;
    }
    else if (str == "rbrace_tk")
    {
        return TokenSymbol::rbrace_tk;
    }
    else if (str == "semicln_tk")
    {
        return TokenSymbol::semicln_tk;
    }
    else if (str == "lbkt_tk")
    {
        return TokenSymbol::lbkt_tk;
    }
    else if (str == "rbkt_tk")
    {
        return TokenSymbol::rbkt_tk;
    }
    else if (str == "id_tk")
    {
        return TokenSymbol::id_tk;
    }
    else if(str == "int_tk")
    {
        return TokenSymbol::int_tk;
    }
    else if(str == "comment_tk")
    {
        return TokenSymbol::comment_tk;
    }
    else if (str == "eof_tk")
    {
        return TokenSymbol::eof_tk;
    }
    
    throw TokenException("Invalid token type " + str, "getTokenSymbolFromString(...)");
}

TokenSymbol TokenSymbol::getTokenSymbol(std::string str)
{
    if(!check_alphabet(str))
    {
        throw TokenException("Bad character", str);
    }
    else if (str == "start")
    {
        return TokenSymbol::start_key_tk;
    }
    else if (str == "stop")
    {
        return TokenSymbol::stop_key_tk;
    }
    else if (str == "decision")
    {
        return TokenSymbol::decision_key_tk;
    }
    else if (str == "while")
    {
        return TokenSymbol::while_key_tk;
    }
    else if (str == "void")
    {
        return TokenSymbol::void_key_tk;
    }
    else if (str == "int")
    {
        return TokenSymbol::int_key_tk;
    }
    else if (str == "return")
    {
        return TokenSymbol::return_key_tk;
    }
    else if (str == "read")
    {
        return TokenSymbol::read_key_tk;
    }
    else if (str == "print")
    {
        return TokenSymbol::print_key_tk;
    }
    else if (str == "program")
    {
        return TokenSymbol::program_key_tk;
    }
    else if (str == "=")
    {
        return TokenSymbol::eq_tk;
    }
    else if (str == "<<")
    {
        return TokenSymbol::dbllt_tk;
    }
    else if (str == ">>")
    {
        return TokenSymbol::dblgt_tk;
    }
    else if (str == "=!")
    {
        return TokenSymbol::eqex_tk;
    }
    else if (str == "==")
    {
        return TokenSymbol::dbleq_tk;
    }
    else if (str == ":")
    {
        return TokenSymbol::colon_tk;
    }
    else if (str == "+")
    {
        return TokenSymbol::plus_tk;
    }
    else if (str == "-")
    {
        return TokenSymbol::minus_tk;
    }
    else if (str == "*")
    {
        return TokenSymbol::asterisk_tk;
    }
    else if (str == "/")
    {
        return TokenSymbol::slash_tk;
    }
    else if (str == "&")
    {
        return TokenSymbol::amp_tk;
    }
    else if (str == "%")
    {
        return TokenSymbol::pct_tk;
    }
    else if (str == ".")
    {
        return TokenSymbol::dot_tk;
    }
    else if (str == "(")
    {
        return TokenSymbol::lpar_tk;
    }
    else if (str == ")")
    {
        return TokenSymbol::rpar_tk;
    }
    else if (str == ",")
    {
        return TokenSymbol::comma_tk;
    }
    else if (str == "{")
    {
        return TokenSymbol::lbrace_tk;
    }
    else if (str == "}")
    {
        return TokenSymbol::rbrace_tk;
    }
    else if (str == ";")
    {
        return TokenSymbol::semicln_tk;
    }
    else if (str == "[")
    {
        return TokenSymbol::lbkt_tk;
    }
    else if (str == "]")
    {
        return TokenSymbol::rbkt_tk;
    }
    else if (is_identifier(str)) // check if string matches rules for identifier
    {
        return TokenSymbol::id_tk;
    }
    else if(is_integer(str)) // check if string matches rules for integer
    {
        return TokenSymbol::int_tk;
    }
    else if(is_comment(str))
    {
        return TokenSymbol::comment_tk;
    }
    else if(str == "") // check for EOF
    {
        return TokenSymbol::eof_tk;
    }
    
    // if the above conditional hasnt returned a token, the string is unknown and therefore erroneous.
    throw TokenException("Unknown token", str);
}

static bool check_alphabet(std::string str)
{
    char c;
    
    for(int i = 0; i < str.length(); i++)
    {
        c = str[i];
        
        if(c < 32 || c > 125) // chars outside of this range are not allowed
        {
            return false;
        }
        
        switch(c) //check for unallowed characters
        {
            case 34:
            case 36:
            case 39:
            case 63:
            case 64:
            case 92:
            case 94:
            case 95:
            case 96:
            case 124:
                return false;
                break;
            default:
                break;
        }
    }
    
    return true;
}

static bool is_identifier(std::string str)
{
    if(str.length() < 1 || str.length() > 8)
        return false;
    
    char c;
    
    for(int i = 0; i < str.length(); i++)
    {
        c = str[i];
        if(!(c <= 'z' && c >= 'a'))
        {
            return false;
        }
    }
    
    return true;
}

static bool is_integer(std::string str)
{
    if(str.length() < 1 || str.length() > 8)
        return false;
    
    char c;
    
    for(int i = 0; i < str.length(); i++)
    {
        c = str[i];
        if(!(c <= '9' && c >= '0'))
        {
            return false;
        }
    }
    
    return true;
}

static bool is_comment(std::string str)
{
    if(str[0] == '#')
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string TokenSymbol::toString()
{
    return TokenSymbol::getTokenSymbolString(t_);
}