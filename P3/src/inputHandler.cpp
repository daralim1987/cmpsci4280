/*
 * William Moll
 * CS4280
 * Project P2
 * 
 */

#include <string>
#include <cstdio>
#include "globals.h"
#include "inputHandler.h"
#include "exceptions.h"

bool check_args(int argc)
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

std::string get_full_filename(char* filename)
{
    std::string ext = file_extension;
    std::string s_filename = filename;
    std::string full_filename;
    
    full_filename = s_filename + ext;
    
    return full_filename;
}

FILE* get_file_pointer(int argc, char* argv[])
{
    FILE* file;
    
    if(argc == 1)
    {
        file = stdin;
    }
    else if(argc == 2)
    {
        std::string filename = get_full_filename(argv[1]);
        
        file = fopen(filename.c_str(), "r");
        if(!file)
        {
            throw FileException("Error opening file");
        }
        else
        {
            fseek(file, 0, SEEK_END);
            unsigned long len = (unsigned long)ftell(file);
            if (len > 0)  //check if the file is empty or not.
            {
                rewind(file);
            }
            else
            {
                throw FileException("Empty file");
            }
        }
    }
    
    return file;
}

void close_file(FILE* fp)
{
    if(fclose(fp) != 0) throw FileException("Error closing file");
}

std::string get_next_string(FILE* fp)
{
    char buffer[255];
    std::string sBuffer;
    
    if(fscanf(fp, "%s", buffer) < 1)
    {
        return "";
    }
    else
    {
        sBuffer = buffer;
        return sBuffer;
    }
}