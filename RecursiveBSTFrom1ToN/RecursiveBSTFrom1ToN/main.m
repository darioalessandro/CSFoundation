//
//  main.m
//  RecursiveBSTFrom1ToN
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct Node {
    void * value;
    struct Node * left;
    struct Node * right;
} Node;

Node * newNode(void * value) {
    Node * node = malloc(sizeof(Node));
    node -> value = value;
    node -> right = NULL;
    node -> left = NULL;
    return node;
}

void printAllPossibleBST(Node * nodes, int length) {
    
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Node  nodes [] = {newNode((void *)1), newNode((void *)2), newNode((void *)3)};
        printAllPossibleBST(nodes, 3);
        
        
    }
    return 0;
}
