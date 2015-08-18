//
//  main.m
//  Findcombinationthatgives0
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <stdlib.h>

void find0_n_cube(int a[], int b[], int c[], unsigned long size_a, unsigned long size_b, unsigned long size_c) {
    for (int i =0; i < size_a; i++)
        for (int j =0; j < size_b; j++)
            for (int k =0; k < size_c; k++)
                if(a[i] + b[j] + c[k] == 0)
                    printf("found a[%d]=%d + b[%d]=%d + c[%d]=%d = 0 \n", i, a[i], j, b[j], k, c[k]);
    
}

int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

void find0_n_squared(int a[], int b[], int c[], unsigned long size_a, unsigned long size_b, unsigned long size_c) {
    
    qsort(a, size_a,sizeof(int),compare_function);
    qsort(b, size_b,sizeof(int),compare_function);
    
    for (int i = 0; i < size_c; i ++) {
        int lookingfor = c[i] * -1;
        int ptri = (int)size_a -1;
        int ptrj = 0;

        while (ptri >= 0 && ptrj < size_b) {
            int val = a[ptri] + b[ptrj];
            if(lookingfor == val){
                printf("found a[%d]=%d + b[%d]=%d + c[%d]=%d = 0 \n", ptri, a[ptri], ptrj, b[ptrj], i, c[i]);
                ptri = -1 ;
                ptrj = (int)size_b;
            }else if(lookingfor > val && ptrj < size_b -1)
                ptrj ++;
            else if(lookingfor < val)
                ptri --;
            else {
                ptri = -1 ;
                ptrj = (int)size_b;
            }

        }
    }
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int a [] = {3, 6, -9, -12, 15};
        int b [] = {2, -5, 8, 13, 17};
        int c [] = {1 , -3, 5, -10, 15};
        //find a[i], b[j], c[k] such that a[i] + b[j] + c[k] = 0
        find0_n_squared(a,b,c, sizeof(a)/sizeof(int), sizeof(b)/sizeof(int), sizeof(c)/sizeof(int));
    }
    return 0;
}
