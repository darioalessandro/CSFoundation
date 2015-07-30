//
//  main.c
//  RotateImage
//
//  Created by Dario Lencina on 7/29/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>

void rotate(int image[4][4], int size, int rotated[4][4]) {
    for (int i = 0 ; i < size ; i ++)
        for (int j = 0 ; j < size ; j ++) {
            int ir = j + size - (j*2) - 1;
            rotated[ir][i] = image[i][j];
        }
}

void rotateEfficient(int image[4][4], int size) {
    for (int layer = 0; layer < size / 2 ; ++layer){
        int first = layer;
        int last = size - 1 - layer;
        for(int i = first; i < last ; ++i) {
            int offset = i - first;
            
            //save top
            
            int top = image[first][i];
            
            image[first][i] = image[last - offset][first];
            
            image[last][last - offset] = image[i][last];
            
            image[i][last] = top;
            
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int image[4][4] = {{0, 1, 2, 3}, {4,5,6,7},{8,9,10,11}, {12,13,14,15}};
    int rotated[4][4] = {{0, 1, 2, 3}, {4,5,6,7},{8,9,10,11}, {12,13,14,15}};
    
    rotate(image, 4, rotated);
    
    for (int i = 0 ; i < 4 ; i ++) {
        for (int j = 0 ; j < 4 ; j ++) {
            printf("%i ", rotated[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    rotateEfficient(image, 4);
    
    for (int i = 0 ; i < 4 ; i ++) {
        for (int j = 0 ; j < 4 ; j ++) {
            printf("%i ", rotated[i][j]);
        }
        printf("\n");
    }


    return 0;
}
