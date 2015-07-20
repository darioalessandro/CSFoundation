//
//  main.c
//  BinarySearchTree
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "BST.h"

int main(int argc, const char * argv[]) {
    Node * root = bst_new(5, NULL, NULL);
    printf("max %i\n", bst_max(root));
    printf("is bst %i\n", bst_is_bst(root));
    bst_insert(root, 12);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));
    bst_insert(root, 15);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));
    bst_insert(root, 30);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));
    bst_insert(root, -30);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));
    bst_insert(root, 10);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));    
    bst_print_node_rec(root, -1);
    
    printf("bst_contains 34 : %d\n", bst_contains_rec(root, 34));
    printf("bst_contains 12 : %d\n", bst_contains_rec(root, 12));
    printf("bst_contains 15 : %d\n", bst_contains_rec(root, 15));
    printf("bst_contains 10 : %d\n", bst_contains_rec(root, 10));
    printf("bst_contains 30 : %d\n", bst_contains_rec(root, 30));
    printf("bst_contains -30 : %d\n", bst_contains_rec(root, -30));
    
    bst_delete(root, 15);
    
    bst_print_node_rec(root, -1);
    printf("is bst %i\n", bst_is_bst(root));
    printf("max %i\n", bst_max(root));
    
    return 0;
}
