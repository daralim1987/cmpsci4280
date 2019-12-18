/*
 * William Moll
 * CS4280
 * Project P1
 * 
 */

#include <iostream>
#include <string>
#include <exception>
#include "globals.h"
#include "testScanner.h"

using namespace std;

string file_extension = ".4280E01";

int main(int argc, char** argv)
{
    try
    {
        testScanner(argc, argv);
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    
    return 0;
}

