/*
 * William Moll
 * CS4280
 * 
 */

#include <string>
#include "scope.h"

Scope::Scope()
{
}

void Scope::push(std::string str)
{
    scope.push_back(str);
}

void Scope::pop()
{
    scope.pop_back();
}

int Scope::find(std::string str)
{
    for(int i = scope.size() - 1; i >= 0; i--)
    {
        if(scope[i] == str)
        {
            return scope.size() - i - 1;
        }
    }
    
    return -1;
}

int Scope::getCount()
{
    return scope.size();
}