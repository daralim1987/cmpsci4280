/* Dara Lim */
/* CS4280 */
/* Project 1 */
#include<iostream>
#include <string>
#include <cstdio>
#include "globalVar.h"
#include "handleInput.h"
#include "exceptHandle.h"
using namespace std;

/*Function check argurment definition */
bool checkArgurment(int argc)
{
    if(argc != 1 && argc != 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*Function get the next String from file */
string getNextString(FILE* fp)
{
    char buff[255];
    string sBuff;
    
    if(fscanf(fp, "%s", buff) < 1)
    {
        return "";
    }
    else
    {
        sBuff = buff;
        return sBuff;
    }
}

/*Function get Full file name definition */
string getFullFilename(char* fileName)
{
    string ex = extension;
    string sFilename = fileName;
    string fullFilename;
    
    fullFilename = sFilename + ex;
    
    return fullFilename;
}

/*Function get the file pointer definition */
FILE* getFilePointer(int argc, char* argv[])
{
    FILE* file;
    
    if(argc == 1)
    {
        file = stdin;
    }
    else if(argc == 2)
    {
        string fileName = getFullFilename(argv[1]);
        
        file = fopen(fileName.c_str(), "r");
        if(!file)
        {
            cout << "File not found" <<endl;
        }
        else
        {
            fseek(file, 0, SEEK_END);
            unsigned long len = (unsigned long)ftell(file);
            if (len > 0)
            {
                rewind(file);
            }
            else
            {
                cout << "File is empty" << endl;
            }
        }
    }
    
    return file;
}

/*function close file */
void closeFile(FILE* fp)
{
    if(fclose(fp) != 0){
        throw FileEx("Error closing file");
    }
    
}



