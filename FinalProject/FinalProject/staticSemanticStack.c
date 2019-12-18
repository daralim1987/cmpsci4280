//  identifierStack.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.


#include "staticSemanticStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int SIZEOFSTACK = 100; 
static stackIden container = { .capacity = 0, .onTop = NULL };

void pushContainer(token tk) {
    if (container.capacity == SIZEOFSTACK) {
        printf("Error: Overflow in the stack\n");
        exit(container.capacity);
    }
    
    tokenIdentifier *otherIdenElem = (tokenIdentifier *) malloc(sizeof(tokenIdentifier));
    otherIdenElem->tk_type.kindOf = tk.kindOf;
    strcpy(otherIdenElem->tk_type.ofType, tk.ofType);
    otherIdenElem->tk_type.numOfLine = tk.numOfLine;
    
    otherIdenElem->adjecent = container.onTop;
    container.onTop = otherIdenElem;
    container.capacity++;
}

void popContainer() {
    if (container.capacity > 0) {
        tokenIdentifier *temporay = container.onTop;
        container.onTop = temporay->adjecent;
        free(temporay);
        container.capacity--;
    }
    else {
        printf("Error: The stack is Empty\n");
        exit(container.capacity);
    }
}

int findTokenInContainer(token tk, int error) {
    int between; 
    tokenIdentifier *idenElemCurrent = container.onTop;
    
    for (between = 0; between < container.capacity; between++) {
        if (strcmp(tk.ofType, idenElemCurrent->tk_type.ofType) == 0) {
            if (error == 1) {
                printf("Error: variable '%s' already defined on line %d (line %d)\n", tk.ofType, idenElemCurrent->tk_type.numOfLine, tk.numOfLine);
                exit(idenElemCurrent->tk_type.numOfLine);
            }
            if (error == 2) {
                return between;
            }
        }
        
        idenElemCurrent = idenElemCurrent->adjecent;
    }
    if (error == 2) {
        printf("Error: Variable '%s' need to define before use (line %d)\n", tk.ofType, tk.numOfLine);
        exit(tk.numOfLine);
    }
    return -1;  // variable not found in stack
}

void outputContainer() {
    int between;
    tokenIdentifier *idenElemCurrent = container.onTop;
    
    printf("STACK\n");
    
    for (between = 0; between < container.capacity; between++) {
        printf("%s %d\n", idenElemCurrent->tk_type.ofType, between);
        
        idenElemCurrent = idenElemCurrent->adjecent;
    }
}
