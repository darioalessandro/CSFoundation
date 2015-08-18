//
//  main.m
//  2.2FindKElementToLastLinkedListElement
//
//  Created by Dario on 8/18/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef struct Node {
    int value;
    struct Node * next;
} Node;

Node * linkedList_new(int value) {
    Node * ll = malloc(sizeof(Node));
    ll -> value = value;
    ll -> next = NULL;
    return ll;
}

void append(Node * head, int data) {
    Node * n = head;
    
    while (n->next != NULL) n = n->next;
    
    n->next = linkedList_new(data);
}

Node * linkedList_findkElementToLast(Node * ll, int k) {
    Node * headPtr = ll;
    Node * headPlusKPtr = headPtr;
    
    //Move headPlusPtr k places ahead of headPtr
    for(int i = k; i > 0; i--)
        if(headPlusKPtr -> next != NULL) headPlusKPtr = headPlusKPtr -> next;
        else return NULL;
    
    while (headPlusKPtr -> next != NULL) {
        headPtr = headPtr -> next;
        headPlusKPtr = headPlusKPtr -> next;
    }	
    
    return headPtr;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        Node * ll = linkedList_new(0);
        for (int i = 10 ; i >= 0; i--) {
            append(ll, i);
        }
        Node * foundNode = linkedList_findkElementToLast(ll, 1);
        if(foundNode)
            printf("found value %d", foundNode -> value);
        else
            printf("unable to find node because it does not contain enough elements");
        
    }
    return 0;
}
