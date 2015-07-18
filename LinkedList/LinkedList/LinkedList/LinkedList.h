//
//  LinkedList.h
//  LinkedList
//
//  Created by Dario Lencina on 7/18/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#ifndef __LinkedList__LinkedList__
#define __LinkedList__LinkedList__

struct node {
    int data;
    struct node * next;
};

typedef struct node LinkedList;

LinkedList * createNode(int value);

LinkedList * append(LinkedList * head, int data);

LinkedList * deleteNodeIter(LinkedList * head, int data);

void freeLinkedListRec(LinkedList * head);

void freeLinkedListIter(LinkedList * head);

void printLinkedList(LinkedList * list);

#endif /* defined(__LinkedList__LinkedList__) */
