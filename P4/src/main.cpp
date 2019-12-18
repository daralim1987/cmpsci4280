/*
 * William Moll
 * CS4280
 * 
 */

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "globals.h"
#include "parser.h"
#include "parseTree.h"
#include "staticSemantics.h"
#include "codeGen.h"

using namespace std;

string file_extension = ".4280E01";

void print_to_file(string, int, char**);

int main(int argc, char** argv)
{
    try
    {
        ParseTree *root = parser(argc, argv);
        StaticSemantics statsem(root);
        statsem.checkTree();
        
        CodeGenerator codeGen(root);
        codeGen.generate();
        
        string code = codeGen.getCode();
        
        print_to_file(code, argc, argv);
    }
    catch(const exception &e)
    {
        cout << e.what() << endl;
        return 1;
    }
    
    return 0;
}

void print_to_file(string code, int argc, char** argv)
{
    string filename = "out.asm";
    if(argc == 2)
    {
        filename = argv[1];
        if(filename.find_last_of("/") != string::npos)
        {
            filename = filename.substr(filename.find_last_of("/") + 1);
        }
        filename += ".asm";
    }

    fstream file;
    file.open(filename, ios::out);
    file << code;
    file.close();
    
    cout << "File '" << filename << " ' generated." << endl;
}