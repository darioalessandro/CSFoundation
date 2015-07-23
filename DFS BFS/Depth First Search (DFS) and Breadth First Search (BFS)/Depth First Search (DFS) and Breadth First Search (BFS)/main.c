//
//  main.c
//  Depth First Search (DFS) and Breadth First Search (BFS)
//
//  Created by Dario Lencina on 7/20/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "dfs.h"
#include "bfs.h"

void run_dfs(){
    Node * a = dfs_new('a', NULL);
    Node * b = dfs_new('b', NULL);
    Node * c = dfs_new('c', NULL);
    Node * d = dfs_new('d', NULL);
    Node * e = dfs_new('e', NULL);
    Node * f = dfs_new('f', NULL);
    Node * g = dfs_new('g', NULL);
    Node * h = dfs_new('h', NULL);
    
    Node * aChildren[3] = {b,g,d};
    Node * bChildren[3] = {a,e,f};
    Node * cChildren[2] = {h, f};
    Node * dChildren[2] = {a,f};
    Node * eChildren[2] = {b,g};
    Node * fChildren[3] = {b,d,c};
    Node * gChildren[2] = {e,a};
    Node * hChildren[1] = {c};
    
    dfs_addChildren(a, aChildren, (int) sizeof(aChildren)/sizeof(aChildren[0]));
    dfs_addChildren(b, bChildren, (int) sizeof(bChildren)/sizeof(bChildren[0]));
    dfs_addChildren(c, cChildren, (int) sizeof(cChildren)/sizeof(cChildren[0]));
    dfs_addChildren(d, dChildren, (int) sizeof(dChildren)/sizeof(dChildren[0]));
    dfs_addChildren(e, eChildren, (int) sizeof(eChildren)/sizeof(eChildren[0]));
    dfs_addChildren(f, fChildren, (int) sizeof(fChildren)/sizeof(fChildren[0]));
    dfs_addChildren(g, gChildren, (int) sizeof(gChildren)/sizeof(gChildren[0]));
    dfs_addChildren(h, hChildren, (int) sizeof(hChildren)/sizeof(hChildren[0]));
    
    dfs_printNode(a);
    dfs_printNode(b);
    dfs_printNode(c);
    dfs_printNode(d);
    dfs_printNode(e);
    dfs_printNode(f);
    dfs_printNode(g);
    dfs_printNode(h);
    
    LinkedList * result = dfs_rec(a);
    LinkedList * resultptr = (LinkedList *)result;
    
    printf("dfs ****\n");
    
    while (resultptr != NULL) {
        Node * n = (Node *) resultptr -> data;
        if(n != NULL){
            printf("\nfound %c", n -> value);
        }
        resultptr = resultptr->next;
    }
    printf("**\n");
}

void run_bfs() {
    Node * a = dfs_new('a', NULL);
    Node * b = dfs_new('b', NULL);
    Node * c = dfs_new('c', NULL);
    Node * d = dfs_new('d', NULL);
    Node * e = dfs_new('e', NULL);
    Node * f = dfs_new('f', NULL);
    Node * g = dfs_new('g', NULL);
    Node * h = dfs_new('h', NULL);
    
    Node * aChildren[3] = {b,g,d};
    Node * bChildren[3] = {a,e,f};
    Node * cChildren[2] = {h, f};
    Node * dChildren[2] = {a,f};
    Node * eChildren[2] = {b,g};
    Node * fChildren[3] = {b,d,c};
    Node * gChildren[2] = {e,a};
    Node * hChildren[1] = {c};
    
    dfs_addChildren(a, aChildren, (int) sizeof(aChildren)/sizeof(aChildren[0]));
    dfs_addChildren(b, bChildren, (int) sizeof(bChildren)/sizeof(bChildren[0]));
    dfs_addChildren(c, cChildren, (int) sizeof(cChildren)/sizeof(cChildren[0]));
    dfs_addChildren(d, dChildren, (int) sizeof(dChildren)/sizeof(dChildren[0]));
    dfs_addChildren(e, eChildren, (int) sizeof(eChildren)/sizeof(eChildren[0]));
    dfs_addChildren(f, fChildren, (int) sizeof(fChildren)/sizeof(fChildren[0]));
    dfs_addChildren(g, gChildren, (int) sizeof(gChildren)/sizeof(gChildren[0]));
    dfs_addChildren(h, hChildren, (int) sizeof(hChildren)/sizeof(hChildren[0]));
    
    dfs_printNode(a);
    dfs_printNode(b);
    dfs_printNode(c);
    dfs_printNode(d);
    dfs_printNode(e);
    dfs_printNode(f);
    dfs_printNode(g);
    dfs_printNode(h);
    
    LinkedList * bfs = bfs_explore_iter(a);
    LinkedList * resultptr = (LinkedList *)bfs;
    
    printf("bfs ****\n");
    
    while (resultptr != NULL) {
        Node * n = (Node *) resultptr -> data;
        if(n != NULL){
            printf("\nfound %c", n -> value);
        }
        resultptr = resultptr->next;
    }
    printf("**\n");
}

int main(int argc, const char * argv[]) {

    run_dfs();
    run_bfs();
    
    /*
     
     B ----- F -- C -- H
     | \     |
     |   A   |
     |   | \ |
     E   |  \|
       \ |   D
         G
     
     */
    
    return 0;
}
