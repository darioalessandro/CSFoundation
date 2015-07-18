//
//  main.c
//  LinkedList
//
//  Created by Dario Lencina on 7/17/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

typedef struct node LinkedList;

LinkedList * createNode(int value) {
    LinkedList * n = malloc( sizeof(LinkedList) );
    n -> next = NULL;
    n -> data = value;
    return n;
}

void freeLinkedListRec(LinkedList * head){
    LinkedList * next = head -> next;
    printf("freeing %i\n", head->data);
    free(head);
    if (next != NULL) {
        freeLinkedListRec(next);
    }
}

void freeLinkedListIter(LinkedList * head){
    LinkedList * next = head;
    while (next != NULL) {
        printf("freeing %i\n", next->data);
        free(next);
        next = next-> next;
    }
}

LinkedList * append(LinkedList * head, int data) {
    LinkedList * n = head;
    
    while (n->next != NULL) n = n->next;
    
    n->next = createNode(data);
    return head;
}

void printLinkedList(LinkedList * list) {
    LinkedList * n = list;
    while (n != NULL) {
        printf("Node %i\n", n->data);
        n = n->next;
    }
}

int main(int argc, const char * argv[]) {
    LinkedList * head = createNode(12);
    head = append(head, 12);
    head = append(head, 1123);
    head = append(head, 12);
    head = append(head, 123);
    printLinkedList(head);
    freeLinkedListIter(head);
    
    return 0;
}


