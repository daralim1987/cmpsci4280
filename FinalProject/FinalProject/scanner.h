//  scanner.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef scanner_h
#define scanner_h

#include <stdio.h>
#include "createToken.h"
#include "alphab.h"

void aheadOfChar(FILE *);
token scanner(FILE *);
token driverTable(FILE *);
int numColonTab(char);
void tokenOutput(token t);
alphab completor(FILE *);

#endif /* scanner_h */
