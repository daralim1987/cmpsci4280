/*
 * William Moll
 * CS4280
 * 
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class CompilerException : public std::exception
{
protected:
    CompilerException() {type = "CompilerException";}
    CompilerException(std::string t) {type = t;}
    const char * what() const throw ()
    {
        std::string str = "--" + type + ": " + error;
        const char * c = str.c_str();
        return c;
    }
    std::string type;
    std::string error;
};


class TokenException : public CompilerException
{
public:
    TokenException(std::string err) : CompilerException("TokenException") {error = err;}
    TokenException(std::string err, std::string near) : CompilerException("TokenException") {error = err + "\n--Near: " + near;}
};

class ParserException : public CompilerException
{
public:
    ParserException(std::string err) : CompilerException("ParserException") {error = err;}
    ParserException(std::string err, std::string token, int loc) : CompilerException("ParserException") {error = err + " ( " + token + " )\nLocation: "+ std::to_string(loc);}
};

class StaticSemanticsException : public CompilerException
{
public:
    StaticSemanticsException(std::string err) : CompilerException("StaticSemanticsException") {error = err;}
    StaticSemanticsException(std::string err, int loc) : CompilerException("StaticSemanticsException") {error = err + " Location: "+ std::to_string(loc);}
};

class FileException : public CompilerException
{
public:
    FileException(std::string err) : CompilerException("FileException") {error = err;}
};

#endif /* EXCEPTIONS_H */

