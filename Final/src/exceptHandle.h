/* Dara Lim */
/* CS4280 */
/* project 4 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

/*Class Exceptions */
/*This class play role as parent class or super class */
class Exceptions : public std::exception
{
protected:
    Exceptions() {type = "Compiler Exception";}
    Exceptions(string t) {type = t;}
    const char * what() const throw ()
    {
        string s = type + ": " + error1;
        const char * ch = s.c_str();
        return ch;
    }
    string type;
    string error1;
};

// Class token exception
//This class throws an exception whenever
//the program encounters the token scanning issue.
class ExceptionTok : public Exceptions
{
public:
    ExceptionTok(string err) : Exceptions("Token Exception") {error1 = err;}
    ExceptionTok(string err, string n) :Exceptions("Token Exception") {error1 = err + "\n--Close: " + n;}
};

/*Class File exception */
/*This class throws an error whenever */
/*the program could not open the file to read */
class FileEx : public Exceptions
{
public:
    FileEx(string err) : Exceptions("File Exception") {error1 = err;}
};

//Classs Parser Exception
//This class throws the error whenever
//the program encounters the parser issue
class ParserException : public Exceptions
{
public:
    ParserException(string err) : Exceptions("Parser Exception") {error1 = err;}
    ParserException(string err, string token, int pos) : Exceptions("Parser Exception") {error1 = err + " ( " + token + " )\nLocation: "+ to_string(pos);}
};

//Class static semantic exception
//This class throws an error whenever
//the program meets the static semantic exception
class StaticSemanticsException : public Exceptions
{
public:
    StaticSemanticsException(string err) : Exceptions("Static Semantics Exception") {error1 = err;}
    StaticSemanticsException(string err, int pos) : Exceptions("Static Semantics Exception") {error1 = err + " Location: "+ to_string(pos);}
};


#endif


