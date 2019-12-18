//  parser.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.


#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createToken.h"
#include "parser.h"
#include "testTree.h"
#include "scanner.h"
#include "createNode.h"

static token tk;
extern char *nameTK[];
static FILE *inputFilePtr;

node * parser(FILE *inputFile) {
    inputFilePtr = inputFile;
    node *treeRoot;
    
    aheadOfChar(inputFilePtr);
    
    tk = scanner(inputFilePtr);
    treeRoot = Program_bnf();
    
    if (tk.kindOf != Eof_token) {
        error2();
    }
    // printf("Parser Success\n");    // TEST
    return treeRoot;
}

node * Program_bnf() {
    node *node = buildNode(Prond);
    
    node->firstCh = Vars_bnf();
    node->secondCh = Block_bnf();
    return node;
}

node * Block_bnf() {
    
    if (tk.kindOf == Begin_token) {
        node *node = buildNode(Bnd);
        tk = scanner(inputFilePtr);
        
        node->firstCh = Vars_bnf();
        node->secondCh = Stats_bnf();
        
        if (tk.kindOf == End_token) {
            tk = scanner(inputFilePtr);
            return node;
        }
        error();
    }
    error();
    return NULL;
}

node * Vars_bnf() {
    node *node = buildNode(Varnd);
    
    if (tk.kindOf == Int_token) {
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Id_token) {
            node->firstToken = tk;
            tk = scanner(inputFilePtr);
            
            if (tk.kindOf == Integer_token) {
                node->secondToken = tk;
                tk = scanner(inputFilePtr);
                
                node->firstCh = Vars_bnf();
                return node;
            }
            error();
        }
        error();
    }
    return node;
}




node * Expr_bnf() {
    node *node = buildNode(Exnd);
    
    node->firstCh = A_bnf();
    
    if (tk.kindOf == Plus_token || tk.kindOf == Minus_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        node->secondCh = Expr_bnf();
    }
    
    return node;
}

node * A_bnf() {
    node *node = buildNode(ANode);
    
    node->firstCh = N_bnf();
    
    if (tk.kindOf == Mul_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        node->secondCh = A_bnf();
    }
    return node;
}

node * N_bnf() {
    node *node = buildNode(NodeN);
    
    node->firstCh = M_bnf();
    
    if (tk.kindOf == Di_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        node->secondCh = N_bnf();
    }
    return node;
}


node * M_bnf() {
    node *node = buildNode(NodeM);
    
    if (tk.kindOf == Minus_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        node->firstCh = M_bnf();
        return node;
    }
    else {
        node->firstCh = R_bnf();
        return node;
    }
}

node * R_bnf() {
    node *node = buildNode(NodeR);
    
    if (tk.kindOf == Lbrack_token) {
        tk = scanner(inputFilePtr);
        
        node->firstCh = Expr_bnf();
        
        if (tk.kindOf == Rbrack_token) {
            tk = scanner(inputFilePtr);
            return node;
        }
        error();
    }
    
    else if (tk.kindOf == Id_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        return node;
    }
    else if (tk.kindOf == Integer_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        return node;
    }
    error();
    return NULL;
}

node * Stats_bnf() {
    node *node = buildNode(NodeSS);
    node->firstCh = Stat_bnf();
    tk = scanner(inputFilePtr);
    node->secondCh = MStat_bnf();
    return node;
}


node * MStat_bnf() {
    node *node = buildNode(NodeMS);
    
    if (tk.kindOf == Read_token || tk.kindOf == Output_token || tk.kindOf == Begin_token || tk.kindOf == Iff_token || tk.kindOf == Loop_token || tk.kindOf == Id_token) {
        
        node->firstCh = Stat_bnf();
        tk = scanner(inputFilePtr);
        node->secondCh = MStat_bnf();
        
    }
    
    return node;
}


node * Stat_bnf() {
    node *node = buildNode(NodeS);
    
    if (tk.kindOf == Read_token) {
        node->firstCh = In_bnf();
        return node;
    }
    else if (tk.kindOf == Output_token) {
        node->firstCh = Out_bnf();
        return node;
    }
    else if (tk.kindOf == Begin_token) {
        node->firstCh = Block_bnf();
        return node;
    }
    else if (tk.kindOf == Iff_token) {
        node->firstCh = If_bnf();
        return node;
    }
    else if (tk.kindOf == Loop_token) {
        node->firstCh = Loop_bnf();
        return node;
    }
    else if (tk.kindOf == Id_token) {
        node->firstCh = Assign_bnf();
        return node;
    }
    error();
    return NULL;
}


node * In_bnf() {
    node *node = buildNode(NodeIn);
    
    if (tk.kindOf == Read_token) {
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Lbrack_token) {
            tk = scanner(inputFilePtr);
            
            if (tk.kindOf == Id_token) {
                node->firstToken=tk;
                tk = scanner(inputFilePtr);
                
                if (tk.kindOf == Rbrack_token) {
                    tk = scanner(inputFilePtr);
                    return node;
                }
                error();
            }
            error();
        }
        error();
    }
    error();
    return NULL;
}


node * Out_bnf() {
    node *node = buildNode(NodeOut);
    
    if (tk.kindOf == Output_token) {
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Lbrack_token) {
            tk = scanner(inputFilePtr);
            
            node->firstCh = Expr_bnf();
            
            if (tk.kindOf == Rbrack_token) {
                tk = scanner(inputFilePtr);
                return node;
            }
            error();
        }
        error();
    }
    error();
    return NULL;
}

node * If_bnf() {
    node *node = buildNode(NodeIf);
    
    if (tk.kindOf == Iff_token) {
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Lbrack_token) {
            tk = scanner(inputFilePtr);
            
            node->firstCh = Expr_bnf();
            node->secondCh = RO_bnf();
            node->thirdCh = Expr_bnf();
            
            if (tk.kindOf == Rbrack_token) {
                tk = scanner(inputFilePtr);
                
                node->fourthCh = Stat_bnf();
                return node;
            }
            error();
        }
        error();
    }
    error();
    return NULL;
}

node * Loop_bnf() {
    node *node = buildNode(NodeLoop);
    
    if (tk.kindOf == Loop_token) {
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Lbrack_token) {
            tk = scanner(inputFilePtr);
            
            node->firstCh = Expr_bnf();
            node->secondCh = RO_bnf();
            node->thirdCh = Expr_bnf();
            
            if (tk.kindOf == Rbrack_token) {
                tk = scanner(inputFilePtr);
                
                node->fourthCh = Stat_bnf();
                return node;
            }
            error();
        }
        error();
    }
    error();
    return NULL;
}

node * Assign_bnf() {
    node *node = buildNode(NodeAssign);
    
    if (tk.kindOf == Id_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Eq_token) {
            tk = scanner(inputFilePtr);
            
            node->firstCh = Expr_bnf();
            return node;
        }
        error();
    }
    error();
    return NULL;
}


node * RO_bnf() {
    node *node = buildNode(NodeRo);
    
    if (tk.kindOf == Less_token || tk.kindOf == Greater_token ||  tk.kindOf == Eq_token) {
        node->firstToken = tk;
        tk = scanner(inputFilePtr);
        
        if (tk.kindOf == Less_token) {
            node->secondToken = tk;
            tk = scanner(inputFilePtr);
            return node;
        }
        else if (tk.kindOf == Greater_token) {
            node->secondToken = tk;
            tk = scanner(inputFilePtr);
            return node;
        }
        else if (tk.kindOf == Eq_token) {
            node->secondToken = tk;
            tk = scanner(inputFilePtr);
            return node;
        }
        return node;
    }
    error();
    return NULL;
}

void error() {
    printf("Parser Error: There is an unexpected token '%s' received here (line %d)\n", nameTK[tk.kindOf], tk.numOfLine);
    exit(tk.kindOf);
}

void error2() {
    printf("Parser Error: There is an extra token '%s' received after end of program (line %d)\n", nameTK[tk.kindOf], tk.numOfLine);
    exit(tk.kindOf);
}
