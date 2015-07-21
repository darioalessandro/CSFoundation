//
//  Stack.h
//  Stack
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#ifndef __Stack__Stack__
#define __Stack__Stack__

#include <stdio.h>
#include "LinkedList.h"

typedef struct Stack {
    LinkedList * top;
} Stack;

void stack_push(Stack * stack, void * a);

void * stack_pop(Stack * stack);

void * stack_peek(Stack * stack);

void stack_popAll(Stack * stack);

Stack * stack_new();

void stack_print(Stack * stack);

#endif /* defined(__Stack__Stack__) */
