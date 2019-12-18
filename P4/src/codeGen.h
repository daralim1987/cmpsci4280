/*
 * William Moll
 * CS4280
 * 
 */

#ifndef CODEGEN_H
#define CODEGEN_H

#include <sstream>
#include "parseTree.h"
#include "scope.h"

class CodeGenerator
{
public:
    CodeGenerator(ParseTree*);
    
    std::string getCode();
    void generate();

private:
    Scope scope;
    ParseTree *parseTree;
    std::ostringstream code;
    int tempCount;
    int labelCount;
    
    std::string getNewTemp();
    std::string getNewLabel();
    
    void genProgram(ParseTree*);
    void genBlock(ParseTree*);
    void genVars(ParseTree*);
    void genMvars(ParseTree*);
    void genExpr(ParseTree*);
    void genM(ParseTree*);
    void genT(ParseTree*);
    void genF(ParseTree*);
    void genR(ParseTree*);
    void genStats(ParseTree*);
    void genMstat(ParseTree*);
    void genStat(ParseTree*);
    void genIn(ParseTree*);
    void genOut(ParseTree*);
    void genIf(ParseTree*);
    void genLoop(ParseTree*);
    void genAssign(ParseTree*);
    void genRo(ParseTree*, std::string);
};

#endif /* CODEGEN_H */

