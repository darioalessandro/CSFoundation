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

typedef struct LinkedList {
    void * data;
    struct LinkedList * next;
} LinkedList;

LinkedList * createNode(void * value);

LinkedList * append(LinkedList * head, void * data);

LinkedList * appendList(LinkedList * data1, LinkedList * data2);

LinkedList * deleteNodeIter(LinkedList * head, void * data);

void freeLinkedListRec(LinkedList * head);

void freeLinkedListIter(LinkedList * head);

void printLinkedList(LinkedList * list);

#endif /* defined(__LinkedList__LinkedList__) */
