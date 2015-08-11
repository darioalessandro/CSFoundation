//
//  main.c
//  MergeSortedArrays
//
//  Created by Dario on 8/10/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // merge sorted arrays merge 2 into a
    int a [] = {1,2,13,23,24,24};
    int b[] = {1,2,4,5,12};
    unsigned long sizeOfa = sizeof(a)/sizeof(a[0]);
    unsigned long sizeOfb = sizeof(b)/sizeof(b[0]);
    unsigned long sizeOfA = sizeOfa + sizeOfb;
    
    printf("size of A = %ld \n", sizeOfA);
    int * A = malloc(sizeof(int) * sizeOfA);
    
    for(int i = 0; i< sizeOfa; i++)
        A[i] = a[i];
    
    long Aptr = sizeOfa - 1;
    long bptr = sizeOfb -1 ;
    
    for(long i = sizeOfA - 1 ; i>=0l ; i-- )
        if(bptr < 0)
            A[i] = A[Aptr--];
        else if(A[Aptr] <= b[bptr])
            A[i] = b[bptr--];
        else
            A[i] = A[Aptr--];
    
    for(long i = 0 ; i<sizeOfA ; i++)
        printf(" %d ", A[i]);
    
    free(A);
    return 0;
}
