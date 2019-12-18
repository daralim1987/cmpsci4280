/*
 * William Moll
 * CS4280
 * 
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>

bool check_args(int);
std::string get_full_filename(char*);

FILE* get_file_pointer(int, char**);
void close_file(FILE*);
std::string get_next_string(FILE*);

#endif /* INPUTHANDLER_H */

