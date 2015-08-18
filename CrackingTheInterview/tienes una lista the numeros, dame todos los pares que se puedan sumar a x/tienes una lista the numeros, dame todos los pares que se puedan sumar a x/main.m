//
//  main.m
//  tienes una lista the numeros, dame todos los pares que se puedan sumar a x
//
//  Created by Dario on 8/18/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

void printPairsN2(int numbers [], unsigned long length, int k) {
    int count = 0;
    for(int i = 0; i < length ; i ++) {
        for(int j = 0; j < length ; j ++) {
            count++;
            if(numbers[i] + numbers[j] == k)
                printf("\nfound numbers[%d](%d) + numbers[%d](%d) == %d", i, numbers[i], j, numbers[j],k);
        }
    }
    printf("\n\ntime complexity O((%f)N) = %d where N = %d", (float)count/(float)length, count, (int)length);
}

void printPairsN(int numbers [], unsigned long length, int target) {
    qsort(numbers, length,sizeof(int),compare_function);
    int i = 0;
    int j = (int)length-1;
    int count = 0;
    while(i < j){
        count++;
        if (numbers[i] + numbers[j] == target) {
            printf("\nfound numbers[%d](%d) + numbers[%d](%d) == %d", i, numbers[i], j, numbers[j],target);
            i++; j--;
        }else if (numbers[i] + numbers[j] <  target) i ++;
        else if (numbers[i] + numbers[j] >  target) j --;
    }
    printf("\n\ntime complexity O((%f)N) = %d where N = %d", (float)count/(float)length, count, (int)length);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int numbers [] = {2,4,3,6,8,2,4,3,6,8,2,4,3,6,8};
        int numbersLength = sizeof(numbers)/sizeof(int);
        printf("numbersLength %d\n\n", numbersLength);
        printPairsN(numbers, numbersLength, 10);
    }
    return 0;
}
