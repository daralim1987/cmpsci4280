/*
 * William Moll
 * CS4280
 * Project P3
 * 
 */

#include <iostream>
#include <string>
#include <exception>
#include "globals.h"
#include "parser.h"
#include "parseTree.h"
#include "staticSemantics.h"

using namespace std;

string file_extension = ".4280E01";

int main(int argc, char** argv)
{
    try
    {
        ParseTree *root = parser(argc, argv);
        StaticSemantics statsem(root);
        statsem.checkTree();
        
        //if no exceptions have been thrown, it is safe to assume the static semantics are good.
        cout << "Static Semantics Good." << endl;
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    
    return 0;
}

