//
//  Queue.c
//  Queue
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>

Queue * queue_new() {
    Queue * queue = malloc(sizeof(Queue));
    queue -> first = NULL;
    queue -> last = NULL;
    return queue;
}

void * queue_dequeue(Queue * queue) {
    LinkedList * first = queue -> first;
    if(first != NULL){
        queue -> first = first -> next;
        if(queue -> first == NULL) queue -> last = NULL;
        void * dataToReturn = first -> data;
        free(first);
        return dataToReturn;
    } else {
        return NULL;
    }
}

void queue_dequeueAll(Queue * queue) {
    int * val = queue_dequeue(queue);
    printf("**\n");
    while (val != NULL) {
        printf("dequeued %i\n", *val);
        val = queue_dequeue(queue);
    }
    printf("**\n");
    printf("Empty queue");
}

void queue_print(Queue * queue) {
    printLinkedList(queue->first);
}

void queue_enqueue(Queue * queue, void * data) {  //last = NULL // first = NULL if last = 3
    LinkedList * newNode = createNode(data);

    if (queue -> first == NULL) {
        queue -> first = newNode;
    } else {
        if(queue -> last == NULL){
            queue -> first -> next = newNode;
        }else{
            queue -> last -> next = newNode;
        }
        queue -> last = newNode;
    }
}

bool queue_isEmpty(Queue * queue) {
    return queue -> first == NULL && queue -> last == NULL;
}