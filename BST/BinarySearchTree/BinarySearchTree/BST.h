//
//  BST.h
//  BinarySearchTree
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#ifndef __BinarySearchTree__BST__
#define __BinarySearchTree__BST__

#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    struct Node * left;
    struct Node * right;
    int value;
} Node;

Node * bst_new(int data, Node * left, Node * right);

void bst_insert(Node * root, int data);

bool bst_contains_rec(Node * root, int data);

Node * bst_delete(Node * node, int data);

void bst_delete_helper(Node * parent, Node * node, int data);

void bst_print_node(Node * tree);

bool bst_is_bst(Node * root);

int bst_max(Node * node);

#endif /* defined(__BinarySearchTree__BST__) */
