//Dara Lim
// cs 4280
//Project 4 is the last project

#include<iostream>
#include <string>
#include "scope.h"
using namespace std;

//Source file of class Scope
//Define default constructor.
Scope::Scope()
{
}

//definition function pop of the vector containerScope
void Scope::pop()
{
    //release the element from the vector.
    containerScope.pop_back();
}

//definition of function push of the vector containerScope
void Scope::push(string s)
{
    //push the element to the vector container.
    containerScope.push_back(s);
}

//definiton function of getSize() of vector
int Scope::getSize()
{
    //This function just return the size of vector.
    return containerScope.size();
}

//definition of function find
//the function just return integer
int Scope::find(string s)
{
    //loop backward through the vector
    for(int j = containerScope.size() - 1; j >= 0; j--)
    {
        //Check the element in the vector
        //then return the integer.
        if(containerScope[j] == s)
        {
            return containerScope.size() - j - 1;
        }
    }
    //return -1.
    return -1;
}

