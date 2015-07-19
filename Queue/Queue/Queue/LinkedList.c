//
//  LinkedList.c
//  LinkedList
//
//  Created by Dario Lencina on 7/18/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList * createNode(int value) {
    LinkedList * n = malloc( sizeof(LinkedList) );
    n -> next = NULL;
    n -> data = value;
    return n;
}

LinkedList * append(LinkedList * head, int data) {
    LinkedList * n = head;
    
    while (n->next != NULL) n = n->next;
    
    n->next = createNode(data);
    return head;
}

LinkedList * deleteNodeIter(LinkedList * head, int data) {
    if(head == NULL)
        return NULL;
    else if(head -> data == data){
        printf("deleting %i\n", head -> data);
        free(head);
        return head -> next;
    }
    
    LinkedList * prev = head;
    LinkedList * center = head -> next;
    
    while (center != NULL) {
        if (center -> data == data){
            prev -> next = center -> next;
            printf("deleting %i\n", center -> data);
            free(center);
            return head;
        } else {
            prev = prev -> next;
            center = center -> next;
        }
    }
    
    return head;
}

void freeLinkedListRec(LinkedList * head) {
    LinkedList * next = head -> next;
    printf("freeing %i\n", head->data);
    free(head);
    if (next != NULL) {
        freeLinkedListRec(next);
    }
}

void freeLinkedListIter(LinkedList * head) {
    LinkedList * next = head;
    while (next != NULL) {
        printf("freeing %i\n", next->data);
        free(next);
        next = next-> next;
    }
}

void printLinkedList(LinkedList * list) {
    LinkedList * n = list;
    printf("**\n");
    while (n != NULL) {
        printf("Node %i\n", n->data);
        n = n->next;
    }
    printf("**\n");
}