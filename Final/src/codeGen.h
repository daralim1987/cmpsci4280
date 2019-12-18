//Dara Lim
//cs4280
//project4 is the last project.

//This is the code generate header file
#ifndef CODEGEN_H
#define CODEGEN_H

#include <sstream>
#include <iostream>
#include "testTree.h"
#include "scope.h"
using namespace std;

//declare the class CodeGenerator.
class CodeGenerator
{
public:
    //constructor take pointer to parse tree class
    CodeGenerator(ParseTree*);
    //function void generate declaration
    void generate();
    //funciton getCode type string.
    string getCode();
    
    
private:
    Scope scope;    //object of class Scope
    //declare the code string stream
    ostringstream code;
    //declare the variable labelCount integer.
    int labelCount;
    //Declare the pointer to parse tree
    ParseTree *parseTree;
    //declare the variable tempCount.
    int tempCount;
   //Declare function get new temp
    string getNewTemp();
    //declare the function get new label.
    string getNewLabel();
    //declare funciton generate Assign
    void genAssign(ParseTree*);
    //declare function generate ro
    void genRo(ParseTree*, std::string);
    //declare function generate program
    void genProgram(ParseTree*);
    //declare function generate block
    void genBlock(ParseTree*);
    //declare function generate loop
    void genLoop(ParseTree*);
    //declare function generate stats
    void genStats(ParseTree*);
    //declare function generate mstats
    void genMstat(ParseTree*);
    //declare function generate vars
    void genVars(ParseTree*);
    //declare function generate A
    void genA(ParseTree*);
    //declare function generate N
    void genN(ParseTree*);
    //declare funciton generate stat
    void genStat(ParseTree*);
    //declare function generate In
    void genIn(ParseTree*);
    //declare function generate express
    void genExpr(ParseTree*);
    //declare function generate out
    void genOut(ParseTree*);
    //delcare function generate If
    void genIf(ParseTree*);
    //declare funciton generate M
    void genM(ParseTree*);
    //declare funciton generate R
    void genR(ParseTree*);
    
};
//end of header file.
#endif /* CODEGEN_H */


