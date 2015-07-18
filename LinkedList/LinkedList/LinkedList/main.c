//
//  main.c
//  LinkedList
//
//  Created by Dario Lencina on 7/17/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList * removeDuplicates(LinkedList * head){
    //char hash[][];
    
    return head;
}

int main(int argc, const char * argv[]) {
    LinkedList * head = createNode(12);
    head = append(head, 12);
    head = append(head, 1123);
    head = append(head, 12);
    head = append(head, 123);
    printLinkedList(head);
    
    head = deleteNodeIter(head,123);
    printLinkedList(head);
    freeLinkedListIter(head);
    
    /*
    Excercises
        Write code to remove duplicates from unsorted linked list
    */
    
    //head = removeDuplicates(head);
    
    return 0;
}


