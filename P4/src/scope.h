/*
 * William Moll
 * CS4280
 * 
 */

#ifndef SCOPE_H
#define SCOPE_H

#include <vector>

class Scope
{
public:
    Scope();
    void push(std::string);
    void pop();
    int find(std::string);
    int getCount();
private:
    std::vector<std::string> scope;

};

#endif /* SCOPE_H */

