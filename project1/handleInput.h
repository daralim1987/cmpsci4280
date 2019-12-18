/* Dara Lim */
/* CS4280 */
/* Project 1 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
using namespace std;

bool checkArgurment(int);
string getFullFilename(char*);
void closeFile(FILE*);
string getNextString(FILE*);
FILE* getFilePointer(int, char**);


#endif


