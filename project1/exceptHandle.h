/* Dara Lim */
/* CS4280 */
/* project 1 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

/*Class Exceptions */
class Exceptions : public std::exception
{
protected:
    Exceptions() {type = "Exception for compiling";}
    Exceptions(string t) {type = t;}
    const char * isWhat() const throw ()
    {
        string s = type + ": " + error1;
        const char * ch = s.c_str();
        return ch;
    }
    string type;
    string error1;
};

/*Class ExceptionTok */
class ExceptionTok : public Exceptions
{
public:
    ExceptionTok(string err) : Exceptions("Exception Token") {error1 = err;}
    ExceptionTok(string err, string n) :Exceptions("Exception Token") {error1 = err + "\n--Close: " + n;}
};

/*Class FileEx */
class FileEx : public Exceptions
{
public:
    FileEx(string err) : Exceptions("Exception for filing") {error1 = err;}
};

#endif


