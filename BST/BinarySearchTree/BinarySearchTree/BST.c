//
//  BST.c
//  BinarySearchTree
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "BST.h"
#include <stdlib.h>

Node * bst_new(int data, Node * left, Node * right) {
    printf("inserted %i\n", data);
    Node * node = malloc(sizeof(Node));
    node -> left = left;
    node -> right = right;
    node -> value = data;
    return node;
};

void bst_insert(Node * root, int data) {
    if(root -> value == data) {
        printf("tree already contains %i, not doing anything\n", data);
    }else if(root -> value < data) {
        if(root -> right != NULL){
            bst_insert(root -> right, data);
        } else {
            root -> right = bst_new(data, NULL, NULL);
        }
    } else {
        if(root -> left != NULL){
            bst_insert(root -> left, data);
        } else {
            root -> left = bst_new(data, NULL, NULL);
        }
    }
};

bool bst_contains_rec(Node * root, int data) {
    if(root -> value == data) {
        return true;
    }else if(root -> value < data) {
        if(root -> right != NULL){
            return bst_contains_rec(root -> right, data);
        } else {
            return false;
        }
    } else {
        if(root -> left != NULL){
            return bst_contains_rec(root -> left, data);
        } else {
            return false;
        }
    }
};

void bst_print_node_rec(Node * root, int level) {
    printf("l : %i : contains %i\n", level, root -> value);
    if(root -> left != NULL) {
        printf("l : %i :  -> left = ", level);
        bst_print_node_rec(root -> left, level + 1);
    }else {
        printf("l : %i : -> left = NULL\n", level);
    }
    if(root -> right != NULL){
        printf("l : %i : -> right = ", level);
        bst_print_node_rec(root -> right, level + 1);
    } else {
        printf("l : %i : -> right = NULL\n", level);
    }
}

/*
 
 1)
                    10
 
            8               13
 
        5       9       12      14
 
 2) delete 13
 
                    10
 
            8               12
 
        5       9     NULL       14
 
 
 3) delete 10 from 1)
 
                    13
 
            12               14
 
        8       NULL     NULL    NULL
 
    5       9
 
 
 4) delete 8
            10                                          10
 
    8               13              =>          5               13
 
 5       9       12      14                 NULL    9       12      14
 
 
*/

void bst_add_all_nodes(Node * source, Node * destination) {
    Node * ptr = source;
    if(ptr != NULL){
        bst_insert(destination, ptr->value);
        bst_add_all_nodes(ptr->left, destination);
        bst_add_all_nodes(ptr->right, destination);
    }
}

void bst_delete_helper(Node * parent, Node * node, int data) {
    if(node == NULL){
        printf("Unable to find node with value %i\n", data);
        return;
    } else if(node -> value == data){
        if (parent -> left == node) { //scenario 4
            parent -> left = node -> left;
            bst_add_all_nodes(node -> right, parent);
        } if (parent -> right == node) { //scenario 2
            parent -> right = node -> left;
            bst_add_all_nodes(node -> right, parent);
        }
    } else {
        if(data > node -> value){
            bst_delete_helper(node, node -> right, data);
        }else{
             bst_delete_helper(node, node -> left, data);
        }
        


    }
}

Node * bst_delete(Node * root, int data) {
    if(root -> value == data) {
        Node * newRoot = root -> right;
        bst_add_all_nodes(root -> left, newRoot);
        return newRoot;
    } else if(data > root -> value) {
        if(root -> right != NULL){
            bst_delete_helper(root, root -> right, data);
        }
    } else {
        if(root -> left != NULL){
            bst_delete_helper(root, root -> left, data);
        }
    }
    return root;
};

int bst_max_helper(Node * node, int currentMax) {
    if (node == NULL) {
        return currentMax;
    }else if(currentMax < node -> value){
        int max_left = bst_max_helper(node -> left, node -> value);
        int max_right = bst_max_helper(node -> right, node -> value);
        return (max_right >= max_left) ? max_right : max_left;
    } else{
        int max_left = bst_max_helper(node -> left, currentMax);
        int max_right = bst_max_helper(node -> right, currentMax);
        return (max_right >= max_left) ? max_right : max_left;
    }
}

int bst_max(Node * node) {
    if(node -> left != NULL && node -> right != NULL){
        int max_left = bst_max_helper(node -> left, node -> left -> value);
        int max_right = bst_max_helper(node -> right, node -> right -> value);
        int max_children = (max_right >= max_left) ? max_right : max_left;
        return (max_children >= node -> value) ? max_children : node -> value;
    } else if(node -> left != NULL){
        int max_children = bst_max_helper(node->left, node -> left -> value);
        return (max_children >= node -> value) ? max_children : node -> value;
    } else if (node-> right != NULL){
        int max_children = bst_max_helper(node->right, node -> right -> value);
        return (max_children >= node -> value) ? max_children : node -> value;
    } else {
        return node -> value;
    }
}


bool bst_is_bst(Node * root) {
    if(root -> right == NULL && root -> left == NULL) {
        return true;
    } else if(root -> right != NULL && root -> left != NULL){
        int maxRight = bst_max(root -> right);
        int maxLeft = bst_max(root -> left);
        return  maxRight > root->value && maxLeft <= root->value;
    }else if(root -> right != NULL){
        int maxRight = bst_max(root -> right);
        return  maxRight > root->value;
    }else {
        int maxLeft = bst_max(root -> left);
        return  maxLeft <= root->value;
    }
}