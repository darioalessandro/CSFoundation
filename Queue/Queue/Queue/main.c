//
//  main.c
//  Queue
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

int main(int argc, const char * argv[]) {
    Queue * queue = queue_new();
    queue_enqueue(queue, 23);
    queue_enqueue(queue, 12);
    queue_enqueue(queue, 12);
    queue_enqueue(queue, 12);
    queue_enqueue(queue, 123);
    queue_print(queue);
    queue_dequeueAll(queue);
    return 0;
}
