//  node.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef node_h
#define node_h
#include "createToken.h"

typedef enum {
    Prond, Bnd, Varnd, Exnd, ANode, NodeN, NodeM, NodeR, NodeSS, NodeMS, NodeS,
    NodeIn, NodeOut, NodeIf, NodeLoop, NodeAssign, NodeRo
} instanceNode;

typedef struct node {
    instanceNode mark;
    token firstToken;
    token secondToken;
    struct node *firstCh;
    struct node *secondCh;
    struct node *thirdCh;
    struct node *fourthCh;
} node;


#endif /* node_h */
