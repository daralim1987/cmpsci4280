/*Dara Lim */
/*cs4280 */
/*Project 4 is the last project*/

#include <iostream>
#include <vector>
#include <string>
#include "staticSemantics.h"
#include "testTree.h"
#include "exceptHandle.h"
using namespace std;

//Function find definiton
//This function loop through the vecotor varStack backward
//If the element in the vector the same as the string s
//Return the element index, otherwise return -1.
int find(vector<string> stackVar, string s)
{
    //Loop to the vector backward
    for(int j = stackVar.size() - 1; j >= 0; j--)
    {
        //Check the element of vector if it equal to the string s
        //and then return index of element.
        if(stackVar[j] == s)
        {
            return j;
        }
    }
    //Return negative 1 otherwis.
    return -1;
}

//This is the function definition PrintStack
//The function print element string off the vector varStack.
void printStack(vector<string> stackVar)
{
    //output the stack word.
    cout << " Start the Stack:" << endl;
    //Iterate through the vector from
    //the end back to the begining.
    for(int j = stackVar.size() - 1; j >= 0; j--)
    {
        cout << stackVar[j] << endl;   //output the string element of vector.
    }
    cout << "End the Stack" << endl;      //output the end stack words.
}

//Define the constructor of the class StaticSemantics
//This constructor just initialize the tree to null
StaticSemantics::StaticSemantics()
{
    tree = NULL;        //Set tree to null value.
}

//Define the constructor of class StaticSemantics
//This constructor just to set the loadTree with root poiinter.
StaticSemantics::StaticSemantics(ParseTree *root)
{
    loadTree(root);  //pass the root pointer to the loadTree function.
}

//This is the definiton of function loadTree
//This function take root as pointer to parseTree.
void StaticSemantics::loadTree(ParseTree *root)
{
    //Assign root to tree.
    tree = root;
}

//The definition of function checkTree.
//There are two vectors in the fucntion
//vector localStack and globalStack.
void StaticSemantics::checkTree()
{
    //Declare the local stack vector of type string
    vector <string> localStack;
    //Declare the global stack vector of type string
    vector <string> globalStack;
    //Calling the traversal node functon here, which pass the above two vectors
    //and the tree.
    traverseNode(tree, localStack, globalStack);
}

//Function traverse node definition
//Fucntion take node of parse tree and
//local vector and global vector.
void StaticSemantics::traverseNode(ParseTree* node, vector<string> &localStack, vector<string> &globalStack)
{
    //Check if node is null and then return .
    if(node == NULL)
    {
        return;
    }
    //Check if nood name is the word  "program"
    if(node->nodeName == "program")
    {
        //Traverse to the child1 of the node tree
        StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        //Traverse to the child2 of the node tree.
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    //Check the node name is block word.
    else if(node->nodeName == "block")
    {
        //Declare the vector blockLocalStack.
        vector<string> blockLocalStack;
        //Assign the globalStack vector to the vector blockGlobalStack.
        vector<string> blockGlobalStack = globalStack;
        //Loop through the localStack entirely.
        for(int j = 0; j < localStack.size(); j++)
        {
            //push the element of localStack to the blockGlobalStack.
            blockGlobalStack.push_back(localStack[j]);
        }
        //Recursive calling itself function traverseNode child 1.
        StaticSemantics::traverseNode(node->child1, blockLocalStack, blockGlobalStack);
        //Recursive calling itself fucntion traversNode child 2.
        StaticSemantics::traverseNode(node->child2, blockLocalStack, blockGlobalStack);
    }
    //check if the node name is in word token.
    else if(node->nodeName == "in")
    {
        //declare and initialize the string var with token of node child 1.
        string var = node->child1->token->getTokenInstance();
        //Check if the function find called with return value
        //less than 0, there is not defined variables in local stack and global
        //stack.
        if(find(localStack, var) < 0 && find(globalStack, var) < 0)
        {
            //Throw an error.
            throw StaticSemanticsException("This Var ("+var+") not defined.", node->child1->location);
        }
    }
    //Check if the node name is assign word.
    else if(node->nodeName == "assign")
    {
        //declare and initialize the string var with node child1 token
        string var = node->child1->token->getTokenInstance();
        //Check if the funcion find called here return value less than 0.
        //Then throw the error that the variables is not defined yet.
        if(find(localStack, var) < 0 && find(globalStack, var) < 0)
        {
            //Error throw exception not defined variables.
            throw StaticSemanticsException("Var ("+var+") not defined.", node->child1->location);
        }
        //Otherwise, call itself again with different child node.
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    //Check if the node name is R token word.
    else if(node->nodeName == "R")
    {
        //check if the child node name is terminal .
        if(node->child1->nodeName == "terminal")
        {
            //check if the child 1 token is identifier.
            if(node->child1->token->getTokenSymbol() == TokenSymbol::id_token)
            {
                //Declare and initialize the string var to the instance of token.
                string var = node->child1->token->getTokenInstance();
                //if the find function called here return value less than 0
                //The variable is not defined yet.
                if(find(localStack, var) < 0 && find(globalStack, var) < 0)
                {
                    //Throw error here.
                    throw StaticSemanticsException("Var ("+var+") not defined.", node->child1->location);
                }
            }
        }
        //Otherwise, call itself again
        //with other childe node.
        else
        {
            StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        }
    }
    //check if the node name is vars word.
    else if(node->nodeName == "vars")
    {
        //declare and initialize the string var with the token instance.
        string var = node->child1->token->getTokenInstance();
        //check if the find function called here is return value greater than 0
        //This meant the variable already defined.
        if(find(localStack, var) >= 0)
        {
            //Throw the message that variable is already created.
            throw StaticSemanticsException("Var ("+var+") already defined.", node->child1->location);
        }
        //push the var back to the local stack.
        localStack.push_back(var);
        //call itself function traverse node with
        //node child2.
        StaticSemantics::traverseNode(node->child2, localStack, globalStack);
    }
    //Otherwise, all the child are not null values.
    else
    {
        //If the node child 1 not null
        //Call itself recursively with child1.
        if(node->child1 != NULL) StaticSemantics::traverseNode(node->child1, localStack, globalStack);
        //If the node child2 not null
        //Call itself recursively with childe2.
        if(node->child2 != NULL) StaticSemantics::traverseNode(node->child2, localStack, globalStack);
        //If node child3 not null
        //call itself recursively with its nodes
        if(node->child3 != NULL) StaticSemantics::traverseNode(node->child3, localStack, globalStack);
        //If node child4 not null
        //Call itself recursively with its node child4.
        if(node->child4 != NULL) StaticSemantics::traverseNode(node->child4, localStack, globalStack);
    }
}

