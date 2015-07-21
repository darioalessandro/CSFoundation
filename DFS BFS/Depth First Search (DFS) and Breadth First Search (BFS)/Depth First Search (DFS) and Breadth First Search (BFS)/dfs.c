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

void dfs_explore_helper(Node * node, LinkedList * results, Stack * stack) {
    append(results, node);
    if( node == NULL)
        return;
    if( node -> visited == false ){
        node -> visited = true;
        stack_push(stack, node);
        printf("pushed %c\n", node -> value);
    }
    for (int i=0; i < node -> childrenSize; i++) {
        Node * child = node -> children[i];
        if(child -> visited == false) {
            printf("visiting %c\n", child -> value);
            dfs_explore_helper(child,results, stack);
            break;
        } else if(i == node -> childrenSize -1 ) {
            Node * popped  = stack_pop(stack);
            dfs_explore_helper(popped, results, stack);
        }
    }
}

LinkedList * dfs_explore(Node * node) {
    LinkedList * results = createNode(node);
    dfs_printNode(node);
    node -> visited = true;
    Stack * stack = stack_new();
    stack_push(stack, node);
    for (int i=0;i<node->childrenSize; i++) {
        Node * child = node -> children[i];
        if(child -> visited == false){
            dfs_explore_helper(node, results, stack);
            break;
        }
    }
    
    return results;
}

