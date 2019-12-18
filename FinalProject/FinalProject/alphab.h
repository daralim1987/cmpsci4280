//  character.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef character_h
#define character_h

typedef struct {
    char ch;
    int numTCol;
    int numOfLine;
} alphab;


typedef enum {
    low_char, up_char, int_char, ws_char, eq_char, les_char, greater_char, colon_char, add_char, sub_char, time_char, divide_char, mod_char, dot_char, lpar_char,
    rpar_char, com_char, lbrac_char, rbrac_char, semi_char, lbrack_char, rbrack_char, eof_char, comm_char
} instanceChar;

#endif /* character_h */
