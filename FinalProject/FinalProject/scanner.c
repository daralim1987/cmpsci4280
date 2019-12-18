//  scanner.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alphab.h"
#include "scanner.h"
#include "createToken.h"
#include "testTree.h"
#include <ctype.h>
#include <memory.h>

#define SIZE 9
#define NUM_STATES 21
#define NUM_CHAR 23  

typedef enum {
    ERROR = -1,
    s1 = 0, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17, s18, s19, s20, s21,
    FINAL = 100
} position;

int finiteStateAtomaticTable[21][23] = {
    
    // a-z    A-Z    0-9     WS      =      <      >      :      +      -      *      /      %      .      (      )      ,      {      }      :      [      ]    EOF   //
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------
    {  ERROR,   s2,    s3,    s1,    s4,    s5,    s6,    s7,    s8,    s9,   s10,   s11,   s12,   s13,   s14,   s15,   s16,   s17,   s18,   s19,   s20,   s21, FINAL}, // s1
    {s2,    s2,    s2, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s2
    {FINAL, FINAL,    s3, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s3
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s4
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s5
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s6
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s7
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s8
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s9
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s10
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s11
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s12
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s13
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s14
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s15
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s16
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s17
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s18
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s19
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}, // s20
    {FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL, FINAL}  // s21
};

static char *reservedWords[] = {
    "Begin", "End", "Loop", "Void", "INT", "Return", "Read", "Output", "Program", "IFF", "Then", "Let"
};

static const int reservedWordNum = 12;  // number of keywords in langugage
static const int SIZEOFTK = 8;  // maximum length of a token instance
static alphab nextToken;
static int numLine = 1;


void aheadOfChar(FILE *inputFile) {
    nextToken = completor(inputFile);
}

token scanner(FILE *inputFile) {
    return driverTable(inputFile);
}

token driverTable(FILE *inputFile) {
    position curPos = s1;
    position nextPos;
    token otherToken;
    char str[9] = "";
    
    while (curPos != FINAL) {
        nextPos = finiteStateAtomaticTable[curPos][nextToken.numTCol];
        
        if (nextPos == ERROR) {
            printf("\nScanner Error: There is no token begin with '%c' (line %d)", nextToken.ch, nextToken.numOfLine);
            exit(ERROR);
        }
        if (nextPos == FINAL) {
            otherToken.kindOf = curPos + reservedWordNum;
            strcpy(otherToken.ofType, str);
            otherToken.numOfLine = nextToken.numOfLine;
            
            if (curPos == s2) {
                int j;
                for (j = 0; j < reservedWordNum; j++) {
                    if (strcmp(reservedWords[j], otherToken.ofType) == 0) {
                        otherToken.kindOf = j;
                    }
                }
            }
            return otherToken;
        }
        else {
            
            if (nextToken.numTCol != ws_char) {
                str[strlen(str)] = nextToken.ch;
                str[strlen(str)+1] = '\0';
            }
            
            curPos = nextPos;
            nextToken = completor(inputFile);
            
            if (strlen(str) == SIZEOFTK) {
                otherToken.kindOf = curPos + reservedWordNum;
                strcpy(otherToken.ofType, str);
                otherToken.numOfLine = nextToken.numOfLine;
                return otherToken;
            }
        }
    }
    return otherToken;
}

alphab completor(FILE *inputFile) {
    alphab input;
    char ch = fgetc(inputFile);
    int numOfColum = numColonTab(ch);
    
    
    
    while (numOfColum == comm_char) {
        do {
            ch = fgetc(inputFile);
            if (ch == '\n') {
                numLine++;
            }
        } while ( ! ( ch==92 || ch=='\n' ));
        //} while (x != 92 );
        ch = fgetc(inputFile);
        numOfColum = numColonTab(ch);
    }
    
    
    
    
    
    if (numOfColum >= low_char && numOfColum <= eof_char) {
        input.ch = ch;
        input.numTCol = numOfColum;
        input.numOfLine = numLine;
        if (ch == '\n') {
            numLine++;
        }
        return input;
    }
    else {
        printf("\nScanner Error: The character is '%c' not in alphabet (line %d)", ch, numLine);
        exit(numOfColum);
    }
    return input;
}

int numColonTab(char x) {
    if (islower(x)) {
        return low_char;
    }
    if (isupper(x)) {
        return up_char;
    }
    if (isdigit(x)) {
        return int_char;
    }
    if (isspace(x)) {
        return ws_char;
    }
    if (x == '=') {
        return eq_char;
    }
    if (x == '<') {
        return les_char;
    }
    if (x == '>') {
        return greater_char;
    }
    if (x == ':') {
        return colon_char;
    }
    if (x == '+') {
        return add_char;
    }
    if (x == '-') {
        return sub_char;
    }
    if (x == '*') {
        return time_char;
    }
    if (x == '/') {
        return divide_char;
    }
    if (x == '%') {
        return mod_char;
    }
    if (x == '.') {
        return dot_char;
    }
    if (x == '(') {
        return lpar_char;
    }
    if (x == ')') {
        return rpar_char;
    }
    if (x == ',') {
        return com_char;
    }
    if (x == '{') {
        return lbrac_char;
    }
    if (x == '}') {
        return rbrac_char;
    }
    if (x == ';') {
        return semi_char;
    }
    if (x == '[') {
        return lbrack_char;
    }
    if (x == ']') {
        return rbrack_char;
    }
    if (x == EOF) { // for EOFtk token
        return eof_char;
    }
    if (x == 92) {
        return comm_char;
    }
    return ( -1 );
}

void tokenOutput(token t) {
    if (t.kindOf == Eof_token) {
        printf("%s\n", nameTK[t.kindOf]);
    }
    else {
        printf("%s %s %d\n", nameTK[t.kindOf], t.ofType, t.numOfLine);
    }
}
