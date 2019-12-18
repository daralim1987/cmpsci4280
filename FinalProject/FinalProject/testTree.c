//  tree.c
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "createToken.h"
#include "createNode.h"
#include "testTree.h"


char *nameTK[] = {
    "BEGINTk", "ENDTk", "LOOPTk", "VOIDTk", "INTTk", "RETURNTk", "READTk", "OUTPUTTk", "PROGRAMTk", "IFFTk", "THENTk", "LETTk",
    
    
    
    "EOFTk", "IDTk", "INTEGERTk", "EQTk", "LESSTk", "GREATERTk", "COLTk", "PLUSTk", "MINUSTk",
    "MULTTk", "DIVTk", "MODTk", "DOTTk", "LPARENTk", "RPARENTk", "COMMATk", "LEFTBRACETk",
    "RIGHTBRACETk", "SEMICOLTk", "LBRACKTk", "RBRACKTk"
    
};
static char *markName[] = {
    "PROGRAM", "BLOCK", "VARS", "EXPR", "A", "N", "M", "R", "STATS", "MSTAT", "STAT", "IN", "OUT", "IF", "LOOP", "ASSIGN", "RO"
};

node * buildNode(instanceNode label) {
    node *otherNode = (node *) malloc(sizeof(node));
    
    otherNode->mark = label;
    
    token token_first = { .kindOf = Ntk, .ofType = "", .numOfLine = 0 };
    token token_second = { .kindOf = Ntk, .ofType = "", .numOfLine = 0 };
    otherNode->firstToken = token_first;
    otherNode->secondToken = token_second;
    
    otherNode->firstCh = NULL;
    otherNode->secondCh = NULL;
    otherNode->thirdCh = NULL;
    otherNode->fourthCh = NULL;
    return otherNode;
}

void preTraverse(node *nd, int level) {
    if (nd != NULL) {
        nodeMark(nd, level);
        preTraverse(nd->firstCh, level + 1);
        preTraverse(nd->secondCh, level + 1);
        preTraverse(nd->thirdCh, level + 1);
        preTraverse(nd->fourthCh, level + 1);
    }
}

void nodeMark(node *nd, int level) {
    printf("%*s%s", level * 2, "", markName[nd->mark]);
    
    if (nd->firstToken.kindOf != Ntk) {
        printf(" {%s, %s, %d}", nameTK[nd->firstToken.kindOf], nd->firstToken.ofType, nd->firstToken.numOfLine);
    }
    if (nd->secondToken.kindOf != Ntk) {
        printf(" {%s, %s, %d}", nameTK[nd->secondToken.kindOf], nd->secondToken.ofType, nd->secondToken.numOfLine);
    }
    
    printf("\n");
}
