//
//  Queue.h
//  Queue
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#ifndef __Queue__Queue__
#define __Queue__Queue__

#include <stdio.h>
#include "LinkedList.h"

typedef struct Queue{
    LinkedList * first;
    LinkedList * last;
} Queue;

Queue * queue_new();

int * queue_dequeue(Queue * queue);

void queue_print(Queue * queue);

void queue_dequeueAll(Queue * queue);

void queue_enqueue(Queue * queue, int data);

#endif /* defined(__Queue__Queue__) */
