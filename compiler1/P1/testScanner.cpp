/*
 * William Moll
 * CS4280
 * Project P1
 * 
 */

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "inputHandler.h"
#include "token.h"
#include "scanner.h"

void testScanner(int argc, char** argv)
{
    FILE* fp = get_file_pointer(argc, argv);
    std::string str;
    
    while(!feof(fp))
    {
        try
        {
            str = get_next_string(fp);
            Token token = scanner(str);
            if(token.getTokenSymbol() == TokenSymbol::comment_tk) continue;
            std::cout << std::setw(18) << std::left << token.getTokenSymbol().toString() << token.getTokenInstance() << std::endl;
        }
        catch(const std::exception &e)
        {
            close_file(fp);
            throw;
        }
    }
}