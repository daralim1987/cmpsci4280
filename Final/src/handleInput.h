/* Dara Lim */
/* CS4280 */
/* Project 4 */

//This header file holding only the function declaration
//These functions all related to work with file.
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include<iostream>
#include <string>
using namespace std;

//Declaration of function to check the feeding arguments.
bool checkArgurment(int);
//Declaration of function to close file.
void closeFile(FILE*);
//Declaration of function to get the next string from file input.
string getNextString(FILE*);
//Declaration of function to get the file pointer.
FILE* getFilePointer(int, char**);
//Declaration of function to get the full name of file.
string getFullFilename(char*);

#endif


