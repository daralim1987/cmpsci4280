//  generator.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#include "codeCreator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testTree.h"
#include "createToken.h"
#include "createNode.h"
#include "staticSemanticStack.h"
#define LENGTH 5

static int labelCount = 0;
static int tempVarCount = 0;
static char name[LENGTH];

typedef enum {
    varName,  //For unique  Variables
    MARK //For nodeType Label
} TYPEOFNAME;


static char *otherName(TYPEOFNAME kind) {
    if (kind == varName) {
        sprintf(name, "V%d", tempVarCount++);
    }
    else if (kind == MARK) {
        sprintf(name, "L%d", labelCount++);
    }
    return name;
}

void generateRec(node *n, int *varCount, FILE *outFilePtr) {
    
    int between;
    char label2[LENGTH];
    char arg[LENGTH];
    char label[LENGTH];
    
    between = nodeCheck(n, varCount, outFilePtr);
    
    switch (n->mark) {
            
        case Exnd:   if (n->firstToken.kindOf != Ntk) {
            semState(n->secondCh, varCount, outFilePtr);
            strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "STORE %s\n", arg);
            
            semState(n->firstCh, varCount, outFilePtr);
            if (n->firstToken.kindOf == Plus_token) {
                fprintf(outFilePtr, "ADD %s\n", arg);
            }
            else if (n->firstToken.kindOf == Minus_token) {
                fprintf(outFilePtr, "SUB %s\n", arg);
            }
        }
        else {
            semState(n->firstCh, varCount, outFilePtr);
        }
            break;
            
        case ANode:      if (n->firstToken.kindOf != Ntk) {
            semState(n->secondCh, varCount, outFilePtr);
            strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "STORE %s\n", arg);
            
            semState(n->firstCh, varCount, outFilePtr);
            if (n->firstToken.kindOf == Mul_token) {
                fprintf(outFilePtr, "MULT %s\n", arg);
            }
        }
        else {
            semState(n->firstCh, varCount, outFilePtr);
        }
            break;
            
        case NodeN:
            if (n->firstToken.kindOf != Ntk) {
                semState(n->secondCh, varCount, outFilePtr);
                strcpy(arg, otherName(varName));
                
                fprintf(outFilePtr, "STORE %s\n", arg);
                semState(n->firstCh, varCount, outFilePtr);
                if (n->firstToken.kindOf == Di_token) {
                    fprintf(outFilePtr, "DIV %s\n", arg);
                }
            }
            else {
                semState(n->firstCh, varCount, outFilePtr);
            }
            break;
            
            // <M>              ->     - <M> |  <R>
        case NodeM:      semState(n->firstCh, varCount, outFilePtr);
            if (n->firstCh->mark == NodeM ) {
                fprintf(outFilePtr, "MULT -1\n");
            }
            break;
            
        case NodeR:      if (n->firstCh == NULL) {
            if (n->firstToken.kindOf == Id_token) {
                fprintf(outFilePtr, "STACKR %d\n", between);
            }
            else if (n->firstToken.kindOf == Integer_token) {//CHANGED THIS
                fprintf(outFilePtr, "LOAD %s\n", n->firstToken.ofType);
            }
        }
        else {
            semState(n->firstCh, varCount, outFilePtr);
        }
            break;
            
        case NodeIn:     strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "READ %s\n", arg);
            fprintf(outFilePtr, "LOAD %s\n", arg);
            fprintf(outFilePtr, "STACKW %d\n", findTokenInContainer(n->firstToken, 2));
            break;
            
            // <out>            ->      Output [ <expr> ]
        case NodeOut:   semState(n->firstCh, varCount, outFilePtr);
            strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "STORE %s\n", arg);
            fprintf(outFilePtr, "WRITE %s\n", arg);
            break;
            
            // <if>               ->      IFF [ <expr> <RO> <expr> ] <stat>
        case NodeIf:     semState(n->thirdCh, varCount, outFilePtr);
            strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "STORE %s\n", arg);
            
            semState(n->firstCh, varCount, outFilePtr);
            fprintf(outFilePtr, "SUB %s\n", arg);
            strcpy(label, otherName(MARK));
            
            // Setup switch statement for Relational Operator Tokens
            switch (n->secondCh->firstToken.kindOf) {
                case Greater_token: n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRNEG %s\n", label) : fprintf(outFilePtr, "BRZNEG %s\n", label);
                    break;
                case Less_token:    n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRPOS %s\n", label) : fprintf(outFilePtr, "BRZPOS %s\n", label);
                    break;
                case Eq_token:      n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRZERO %s\n", label) : fprintf(outFilePtr, "BRNEG %s\nBRPOS %s\n", label, label);
                    break;
                default:        n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRZERO %s\n", label) : fprintf(outFilePtr, "BRNEG %s\nBRPOS %s\n", label, label);
                    break;
            }
            semState(n->fourthCh, varCount, outFilePtr);
            fprintf(outFilePtr, "%s: NOOP\n", label);
            break;
            
            // <loop>          ->      Loop [ <expr> <RO> <expr> ] <stat>
        case NodeLoop:   strcpy(label, otherName(MARK));
            fprintf(outFilePtr, "%s: NOOP\n", label);
            semState(n->thirdCh, varCount, outFilePtr);
            strcpy(arg, otherName(varName));
            fprintf(outFilePtr, "STORE %s\n", arg);
            
            semState(n->firstCh, varCount, outFilePtr);
            fprintf(outFilePtr, "SUB %s\n", arg);
            strcpy(label2, otherName(MARK));
            
            // Setup switch statement for Relational Operator Tokens
            switch (n->secondCh->firstToken.kindOf) {
                case Greater_token: n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRNEG %s\n", label2) : fprintf(outFilePtr, "BRZNEG %s\n", label2);
                    break;
                case Less_token:    n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRPOS %s\n", label2) : fprintf(outFilePtr, "BRZPOS %s\n", label2);
                    break;
                case Eq_token:      n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRZERO %s\n", label2) : fprintf(outFilePtr, "BRNEG %s\nBRPOS %s\n", label2, label2);
                    break;
                default:        n->secondCh->secondToken.kindOf == Eq_token ? fprintf(outFilePtr, "BRZERO %s\n", label2) : fprintf(outFilePtr, "BRNEG %s\nBRPOS %s\n", label2, label2);
                    break;
            }
            semState(n->fourthCh, varCount, outFilePtr);
            fprintf(outFilePtr, "BR %s\n", label);
            fprintf(outFilePtr, "%s: NOOP\n", label2);
            break;
            
            // <assign>       ->      Identifier  = <expr>
        case NodeAssign: semState(n->firstCh, varCount, outFilePtr);
            fprintf(outFilePtr, "STACKW %d\n", between);
            break;
            
        default:       semState(n->firstCh, varCount, outFilePtr);
            semState(n->secondCh, varCount, outFilePtr);
            semState(n->thirdCh, varCount, outFilePtr);
            semState(n->fourthCh, varCount, outFilePtr);
            break;
    }
}

void generator(node *program, FILE *outFilePtr) {
    
    if (program == NULL || program->mark != Prond) {
        printf("Generator Error: Invalid parse tree received\n");
        exit(program->mark);
    }
    
    semState(program, NULL, outFilePtr); //If program exists, call this function to proceed//
    
    fprintf(outFilePtr, "STOP\n"); //Return after staticSemantics fxn processed
    int j;
    for (j = 0; j < tempVarCount; j++) {
        fprintf(outFilePtr, "V%d 0\n", j);
    }
}

void semState(node *n, int *varCount, FILE *outFilePtr) {
    if (n != NULL) { //If not empty, proceed
        if (n->mark == Bnd || n->mark == Prond) { //PROGRAM or BLOCK
            int *varCount = (int *) malloc(sizeof(int));
            *varCount = 0;
            
            generateRec(n, varCount, outFilePtr); //Call main recGen fxn above
            int i;
            for (i = 0; i < *varCount; i++) {
                popContainer();    // Print POP to target file upon calling pop()
                fprintf(outFilePtr, "POP\n");
            }
            free(varCount); //Free allocated memory
        }
        else {
            generateRec(n, varCount, outFilePtr);
        }
    }
}

int nodeCheck(node *n, int *varCount, FILE *outFilePtr) {
    
    int distance = (-1);
    if (n->mark == Varnd) {
        if (n->firstToken.kindOf == Id_token) {
            if (*varCount > 0) {
                distance = findTokenInContainer(n->firstToken, 1);  // set error reporting to type 1
            }
            pushContainer(n->firstToken);     // Print PUSH to target file upon calling push()
            fprintf(outFilePtr, "PUSH\n");
            (*varCount)++;
            return distance;
        }
    }
    else if (n->mark == NodeR || n->mark == NodeIn || n->mark == NodeAssign) {
        if (n->firstToken.kindOf == Id_token) {
            distance = findTokenInContainer(n->firstToken, 2);  // set error reporting to type 2
            return distance;
        }
    }
    return distance;
}
