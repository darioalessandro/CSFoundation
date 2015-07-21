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

LinkedList * createNode(void * value) {
    LinkedList * n = malloc( sizeof(LinkedList) );
    n -> next = NULL;
    n -> data = value;
    return n;
}

LinkedList * append(LinkedList * head, void * data) {
    LinkedList * n = head;
    
    while (n->next != NULL) n = n->next;
    
    n->next = createNode(data);
    return head;
}

LinkedList * appendList(LinkedList * data1, LinkedList * data2) {
    LinkedList * n = data1;
    
    while (n->next != NULL) n = n->next;
    
    n->next = data2;
    return data1;
}

LinkedList * deleteNodeIter(LinkedList * head, void * data) {
    if(head == NULL)
        return NULL;
    else if(head -> data == data){
        free(head);
        return head -> next;
    }
    
    LinkedList * prev = head;
    LinkedList * center = head -> next;
    
    while (center != NULL) {
        if (center -> data == data){
            prev -> next = center -> next;
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
    free(head);
    if (next != NULL) {
        freeLinkedListRec(next);
    }
}

void freeLinkedListIter(LinkedList * head) {
    LinkedList * next = head;
    while (next != NULL) {
        free(next);
        next = next-> next;
    }
}

void printLinkedList(LinkedList * list) {
    LinkedList * n = list;
    printf("**\n");
    while (n != NULL) {
        n = n->next;
    }
    printf("**\n");
}