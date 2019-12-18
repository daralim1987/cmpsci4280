//  tree.h
//  finalP4
//  Created by Dara Lim on 7/14/19.
//  Copyright © 2019 Dara Lim. All rights reserved.

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "createNode.h"

node * buildNode(instanceNode);
void preTraverse(node *, int);
void nodeMark(node *, int);
extern char *nameTK[];
#endif /* tree_h */
