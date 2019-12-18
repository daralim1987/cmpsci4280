/*Dara Lim */
/*Project 1 */
/*CS4280 */
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "handleInput.h"
#include "token.h"
#include "scanner.h"
using namespace std;

/*Test scanner function definition */
void testScanner(int argc, char** argv)
{
    FILE* fptr = getFilePointer(argc, argv);
    string s;
    
    while(!feof(fptr))
    {
        try
        {
            s = getNextString(fptr);
            Token token = scanner(s);
            if(token.getTokenSymbol() == TokenSymbol::comment_token) continue;
            cout << setw(20) << left << token.getTokenSymbol().toString() << token.getTokenInstance() << endl;
        }
        catch(const exception &e)
        {
            closeFile(fptr);
            throw;
        }
    }
}

