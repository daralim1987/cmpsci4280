/*
 * William Moll
 * CS4280
 * 
 */

#ifndef STATICSEMANTICS_H
#define STATICSEMANTICS_H

#include <vector>
#include "parseTree.h"

class StaticSemantics
{
public:
    StaticSemantics();
    StaticSemantics(ParseTree*);
    void loadTree(ParseTree*);
    void checkTree();
    
private:
    ParseTree *tree;
    void traverseNode(ParseTree*, std::vector<std::string> &, std::vector<std::string> &);
};

#endif /* STATICSEMANTICS_H */

