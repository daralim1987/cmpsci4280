//  identifierStack.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef identifierStack_h
#define identifierStack_h

#include <stdio.h>
#include "createToken.h"

#define SIZE 9

typedef struct tokenIdentifier {
    token tk_type;
    struct tokenIdentifier *adjecent;
} tokenIdentifier;

typedef struct {
    int capacity;
    tokenIdentifier *onTop;
} stackIden;

void pushContainer(token);
void popContainer();
int findTokenInContainer(token, int);
void outputContainer();

#endif /* identifierStack_h */
