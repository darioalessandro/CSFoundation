//
//  main.c
//  MergeSort
//
//  Created by Dario Lencina on 7/14/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * mergeChunks(int * chunka, int * chunkb, unsigned long chunkaSize, unsigned long chunkbSize) {
    unsigned long  sortedArraySize = chunkaSize + chunkbSize;
    int  * sortedArray = malloc(sizeof(int)*sortedArraySize);
    
    int aPtr = 0;
    int bPtr = 0;
    
    for(int k = 0; k < sortedArraySize ; k++){
        if(aPtr >= chunkaSize) {
            sortedArray[k] = chunkb[bPtr];
            bPtr++;
        }else if(bPtr >= chunkbSize){
            sortedArray[k] = chunka[aPtr];
            aPtr++;
        }else if(chunka[aPtr] < chunkb[bPtr]){
            sortedArray[k] = chunka[aPtr];
            aPtr++;
        }else {
            sortedArray[k] = chunkb[bPtr];
            bPtr++;
        }
    }
    
    return sortedArray;
};

int * mergeSort(int * collection, unsigned long size){
    if(size == 0){
        return NULL;
    }else if(size == 1){
        return mergeChunks(collection, NULL, 1,0); //This is to balance 'free' on the main
    }
    
    unsigned long chunkaSize = floor(size/2);
    unsigned long chunkbFirstElement = chunkaSize;
    unsigned long chunkbSize = size - chunkbFirstElement;

    
    int * chunka = mergeSort(collection, chunkaSize);
    int * chunkb = mergeSort(&collection[chunkbFirstElement], chunkbSize);
    
    return mergeChunks(chunka, chunkb, chunkaSize, chunkbSize);
}

int main(int argc, const char * argv[]) {
    
    int collection[] = {234,4321,1423,4231,4123,2341,135,1336,3,413,6314,6,1-346,346,13,136,1346,243626,24};
    
    unsigned long collectionSize = sizeof(collection)/sizeof(collection[0]);
    
    int * sortedCollection = mergeSort(collection, collectionSize);
    
    if(sortedCollection != NULL){
        printf("sorted collection: \n[ ");
        for (int i = 0; i<collectionSize; i++) {
            printf("%i ",sortedCollection[i]);
        }
        printf("]");
        free(sortedCollection);
    }else{
        printf("collection must contain at least 1 element");
    }
    
    printf("\n");
    
    
    return 0;
}


