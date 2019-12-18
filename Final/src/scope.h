/*Dara Lim
 *cs4280
 *project4 is the last project.
 *
 *
 */

//This is the scope header file.
#ifndef SCOPE_H
#define SCOPE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Class Scope declaration
//The class has one constructor
//with four functions and one vector of string
class Scope
{
public:
    //default constructor
    Scope();
    //declaration of getCount funciton
    int getSize();
    //declaration of push function
    void pop();
    //declaration of find function
    int find(string);
    void push(string);
    //declaration of pop function
private:
    //declare a vector scope
    vector<string> containerScope;
    
};

#endif /* SCOPE_H */
