//  generator.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef generator_h
#define generator_h

#include <stdio.h>
#include "createNode.h"

void generateRec(node *, int *, FILE *);
void generator(node *, FILE *);
void semState(node *, int *, FILE *);
int nodeCheck(node *, int *, FILE *);

#endif /* generator_h */
