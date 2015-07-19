//
//  Stack.c
//  Stack
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "Stack.h"
#include "LinkedList.h"
#include <stdlib.h>


void stack_push(Stack * stack, int a) {
    LinkedList * oldTop = stack -> top;
    LinkedList * newTop = createNode(a);
    newTop -> next = oldTop;
    stack -> top = newTop;
};

int * stack_pop(Stack * stack) {
    LinkedList * top = stack -> top;
    if(top != NULL){
        stack->top = top -> next;
        return &top -> data;
    } else {
        return NULL;
    }
};

int stack_peek(Stack * stack) {
    return stack -> top-> data;
}

void stack_popAll(Stack * stack) {
    int * top = stack_pop(stack);
    while(top != NULL){
        printf("top %i\n", *top);
        free(top);
        top = stack_pop(stack);
    }
    printf("Stack is empty");
}

Stack * stack_new() {
    return malloc(sizeof(Stack));
}

void stack_print(Stack * stack) {
    printLinkedList(stack->top);
}