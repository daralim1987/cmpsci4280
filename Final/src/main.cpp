/* Dara Lim */
/* CS4280 */
/* Project 4 is the last project */

//This the main file of the entire project files
#include <iostream>
#include <string>
#include <exception>
#include "globalVar.h"
#include "testTree.h"
#include "staticSemantics.h"
#include "codeGen.h"
#include "fstream"
#include "parser.h"
using namespace std;

//Declare and initialize the string extension file name.
string extension = ".input1";
//function prototype
void printOutputToFile(string, int, char**);

//start the main function
int main(int argc, char** argv)
{
    //try block
    try
    {
        //assign the root
        ParseTree *root = parser(argc, argv);
        //static semantics object
        StaticSemantics statSem(root);
        //call the function checkTree through object
        statSem.checkTree();
        //create the object codeGen of class CodeGenerator
        CodeGenerator codeGen(root);
        //call the funciton generate
        codeGen.generate();
        //declare the variable string code.
        string code = codeGen.getCode();
        //call function to print to output.
        printOutputToFile(code, argc, argv);
        
    }
    //catch block
    catch(const exception &e)
    {
        //error.
        cout << e.what() << endl;
        //return 1
        return 1;
    }
    
    return 0;
}

//function definition
void printOutputToFile(string code, int argc, char** argv)
{
    //declare string variable for the output file from the keyboard
    string filename = "out.asm";
   
    //input from the input file
    if(argc == 2)
    {
        //fileName is the name from the command line argument.
        filename = argv[1];
        //check the file name
        if(filename.find_last_of("/") != string::npos)
        {
            //assign the file name to the first input file name
            //without the extension
            filename = filename.substr(filename.find_last_of("/") + 1);
        }
        //concate the file name
        filename += ".asm";
    }
    
    //declare fstream file
    fstream f;
    //open the file for writing
    f.open(filename, ios::out);
    //put file to the code
    f << code;
    //close the file
    f.close();
    //output the file name
    cout << "File '" << filename << " ' generated." << endl;
}

