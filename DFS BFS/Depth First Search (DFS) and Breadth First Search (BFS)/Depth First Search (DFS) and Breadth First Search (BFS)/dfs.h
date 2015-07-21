//
//  dfs.h
//  Depth First Search (DFS) and Breadth First Search (BFS)
//
//  Created by Dario Lencina on 7/20/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#ifndef __Depth_First_Search__DFS__and_Breadth_First_Search__BFS___dfs__
#define __Depth_First_Search__DFS__and_Breadth_First_Search__BFS___dfs__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"

typedef struct Node {
    struct Node ** children;
    int childrenSize;
    bool visited;
    char value;
}Node;

Node * dfs_new(char value, Node ** children);

Node * dfs_addChildren(Node * parent, Node ** children, int size);

void dfs_printNode(Node * node);

LinkedList * dfs_explore(Node * node);

#endif /* defined(__Depth_First_Search__DFS__and_Breadth_First_Search__BFS___dfs__) */
