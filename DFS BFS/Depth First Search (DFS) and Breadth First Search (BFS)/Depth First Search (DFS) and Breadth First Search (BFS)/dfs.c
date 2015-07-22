//
//  dfs.c
//  Depth First Search (DFS) and Breadth First Search (BFS)
//
//  Created by Dario Lencina on 7/20/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "dfs.h"

Node * dfs_new(char value, Node ** children) {
    Node * node = malloc(sizeof(Node));
    node -> children = children;
    node -> childrenSize = 0;
    node -> value = value;
    return node;
}

Node * dfs_addChildren(Node * parent, Node ** children, int size) {
    if(parent -> children == NULL) {
        parent -> children = children;
        parent -> childrenSize = size;
    } else {
        printf("system does not support updating children");
    }
    return parent;
}

void dfs_printNode(Node * node) {
    printf("****");
    printf("node %c children=> \n", node -> value);
    for(int i=0; i < node -> childrenSize; i++){
        printf("node %c \n", node->children[i]->value);
    }
    printf("****");
}

/*
 1  procedure DFS(G,v): wikipedia
 2      label v as discovered
 3      for all edges from v to w in G.adjacentEdges(v) do
 4          if vertex w is not labeled as discovered then
 5              recursively call DFS(G,w)
 
 */

LinkedList * dfs_rec(Node * root) {
    LinkedList * results = createNode(NULL);
    if (root -> visited == false) {
        root -> visited = true;
        append(results, root);
    }
    
    for (int i =0; i < root -> childrenSize; i++)
        if(root -> children[i] -> visited == false)
            appendList(results, dfs_rec(root -> children[i]));
    
    return results;
}

/*
 procedure DFS-iterative(G,v): wikipedia
 2      let S be a stack
 3      S.push(v)
 4      while S is not empty
 5            v = S.pop()
 6            if v is not labeled as discovered:
 7                label v as discovered
 8                for all edges from v to w in G.adjacentEdges(v) do
 9                    S.push(w)
 */

LinkedList * dfs_iter(Node * root) {
    LinkedList * results = NULL;
    Stack * stack = stack_new();
    stack_push(stack, root);
    while (stack_peek(stack) != NULL) {
        Node * nodeBeingExplored = stack_pop(stack);
        if(nodeBeingExplored->visited == false) {
            nodeBeingExplored -> visited = true;
            if(results == NULL)
                results = createNode(root);
            else
                append(results, nodeBeingExplored);
            for (int i=0; i < nodeBeingExplored -> childrenSize; i++) {
                Node * child = nodeBeingExplored -> children[i];
                if(child -> visited == false){
                    stack_push(stack, child);
                }
            }

        }
    }
    return results;
}


