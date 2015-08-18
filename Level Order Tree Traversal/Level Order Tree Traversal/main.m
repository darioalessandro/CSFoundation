//
//  main.m
//  Level Order Tree Traversal
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef struct Node {
    struct Node * left;
    struct Node * right;
    void * value;
    int level;
} Node;

Node * newNode(void * value) {
    Node * n = malloc(sizeof(Node));
    n-> value = value;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

int height(struct Node * node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        
        /* use the larger one */
        if (lheight > rheight) return(lheight+1);
        else return(rheight+1);
    }
}

void printNode(Node node) {
    printf("%d ", (int) node.value);
}

void printLevel(Node * root, int level) {
    if(root == NULL)
        return;
    
    if(level == 1){
        printNode(*root);
    } else {
        printLevel(root -> left, level -1);
        printLevel(root -> right, level -1);
    }
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Node *root = newNode((void *) 1);
        root->left        = newNode((void *)2);
        root->right       = newNode((void *)3);
        root->left->left  = newNode((void *)4);
        root->left->right = newNode((void *)5);
        
        printLevel(root, 3);
        printf("\nheight %d", height(root));
    }
    return 0;
}
