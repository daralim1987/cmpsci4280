/*Dara Lim */
/*cs4280 */
/*Project 4 is the last project */

#ifndef STATICSEMANTICS_H
#define STATICSEMANTICS_H

//This is the header file for static semantic
//There is a class StaticSemantics with three functions declaration
#include <vector>
#include <string>
#include "testTree.h"
using namespace std;

//Class StaticSemantics
//This class has two contructors
//One constructor take pointer to the ParseTree class
//The other is a default constructor.
class StaticSemantics
{
public:
    StaticSemantics();                  //Default constructor
    StaticSemantics(ParseTree*);        //Constructor takes pointer to parseTree
    void loadTree(ParseTree*);          //Function declaration loadtree
    void checkTree();                   //Function check the tree.
    
private:
    //Variable tree point to ParseTree
    ParseTree *tree;
    //function traverse to the node of treee.
    void traverseNode(ParseTree*, vector<string> &, vector<string> &);
};

#endif /* STATICSEMANTICS_H */


