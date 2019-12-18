/*
 * Dara Lim
 * CS4280
 * Project 4 is the last project.
 *
 */

//This is the header file of parser
//There are two function declarations.
#ifndef PARSER_H
#define PARSER_H
#include "testTree.h"
#include <iostream>

//Parser function declaration
//which is the pointer to ParseTree
ParseTree *parser(int, char**);

//Function declaration print tree as type void.
void printTree(ParseTree *, int);

#endif /* PARSER_H */


