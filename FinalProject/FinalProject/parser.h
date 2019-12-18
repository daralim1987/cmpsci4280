//  parser.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef parser_h
#define parser_h

#include <stdio.h>
#include "createNode.h"

node * parser(FILE *);
node * Program_bnf();
node * Block_bnf();
node * Vars_bnf();
node * Expr_bnf();
node * A_bnf();
node * N_bnf();
node * M_bnf();
node * R_bnf();
node * Stats_bnf();
node * MStat_bnf();
node * Stat_bnf();
node * In_bnf();
node * Out_bnf();
node * If_bnf();
node * Loop_bnf();
node * Assign_bnf();
node * RO_bnf();
void error();
void error2();

#endif /* parser_h */
