//
//  main.c
//  Stack
//
//  Created by Dario Lencina on 7/19/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <stdlib.h>
#include "Stack.h"

int main(int argc, const char * argv[]) {
    Stack * stack = stack_new();
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_print(stack);
    stack_popAll(stack);
    
    return 0;
}
