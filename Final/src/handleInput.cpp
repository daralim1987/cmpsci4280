/* Dara Lim */
/* CS4280 */
/* Project 4 */
#include<iostream>
#include <string>
#include <cstdio>
#include "globalVar.h"
#include "handleInput.h"
#include "exceptHandle.h"
using namespace std;

/*Definition of function check argurment */
//The function check to see if the program running
//with more 2 arguments given, if the arguments is not 1 and 2
//there is an error.
bool checkArgurment(int argc)
{
    //Return false if the given arguments not 1 and 2.
    if(argc != 1 && argc != 2)
    {
        return false;
    }
    //Otherwise return true.
    else
    {
        return true;
    }
}

/*Function get the next String from file defintion */
//The input taken from and then put in the string sBuff.
string getNextString(FILE* fp)
{
    //Declare the variable sBuff as string type.
    string sBuff;
    //Declare the character array buff of size 255.
    char buff[255];
    //Check if the functon fscanf return the value less than 1
    //Then return the empty string.
    if(fscanf(fp, "%s", buff) < 1)
    {
        return "";
    }
    //Otherwise, assign the buff string to sBuff string
    //and then return from the function.
    else
    {
        sBuff = buff;
        return sBuff;
    }
}

/*Function to get full file name definition */
//This function concatenate the implicit extension of file extendsion.
string getFullFilename(char* fileName)
{
    string ex = extension;  // Declare the extendsion of file.
    //Declare string full name file.
    string fullFilename;
    //Declare the string file name.
    string sFilename = fileName;
    
    //Concatenate the two strings file name and
    //the extension of file name and return from the function.
    fullFilename = sFilename + ex;
    
    return fullFilename;
}

/*Function get the file pointer definition */
//This function either take the input from standard input or
//from file input.
FILE* getFilePointer(int argc, char* argv[])
{
    FILE* fp;   //Declare the file pointer to file
    
    //Check if the argument equal 1
    //This mean the input is taken from
    //standard input
    if(argc == 1)
    {
        fp = stdin; //input is from the standard keyboard.
    }
    
    //Otherwise, if the arguments is equal 2
    //This mean the input is taken from the file input
    else if(argc == 2)
    {
        //Assign the full name of file to fileName as string
        string fileName = getFullFilename(argv[1]);
        
        //Open the file to read from and assign to file pointer fp
        fp = fopen(fileName.c_str(), "r");
        //If file pointer is not exist
        //There is an error.
        if(!fp)
        {
            cout << "File not found" <<endl;
        }
        //Otherwise, the file open successfully and perform the operations
        else
        {
            fseek(fp, 0, SEEK_END);
            unsigned long len = (unsigned long)ftell(fp);
            //If the length greater than zero then operate the rewind function
            if (len > 0)
            {
                rewind(fp);
            }
            //File is empty.
            else
            {
                throw FileEx("File is empty");
            }
        }
    }
    
    //return the file pointer from the function.
    return fp;
}

/*function close file definition */
//This function to close the file after opening
//to be a good person, close the door after open it.
void closeFile(FILE* fp)
{
    //If the file pointer is not equal to zero then throws the error.
    if(fclose(fp) != 0){
        throw FileEx("There is an issue to close the file");
    }
    
}



