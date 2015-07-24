//
//  main.c
//  ConvertBinToHex
//
//  Created by Dario Lencina on 7/23/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

typedef struct Number {
    char * value;
    int base;
} Number;

int charToDigit(char c) {
    switch (c) {
        case '0':
            return 0;
            break;
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;
        default:
            return -1;
            break;
    }
}

int convertToInt(char * number, int length){
    int numberAsInt = 0;
    for(int i = length -1; i >= 0; i--) {
        int digit = charToDigit(number[i]);
        if(digit == -1) {
            printf("Error, this is not a valid number %s", number);
        } else {
            int multiplicator = 1;
            
            for(int j = 0 ; j < length -1 - i; j++)
                multiplicator = multiplicator * 10;
            
            numberAsInt = numberAsInt + digit * multiplicator;
        }
    }
    return numberAsInt;
}

int changeBase(char * number, int length, int newBase) {
    int value = 0;
    for(int i = length - 1; i >= 0; i --) {
        int digit = charToDigit(number[i]);
        int exp = length - 1 - i;
        value = value + digit * pow(newBase, exp);
    }
        
    return value;
}

bool compare(Number n1, Number n2) {
    printf("size of int : %lu bytes\n", sizeof(int));
    int n1Dec = changeBase(n1.value, (int)strlen(n1.value), n1.base);
    int n2Dec = changeBase(n2.value, (int)strlen(n2.value), n2.base);
    return n1Dec == n2Dec;
}

int main(int argc, const char * argv[]) {
    Number n1 = {"7FFFFFFF", 16};
    Number n2 = {"2147483647", 10};
    bool equal = compare(n1, n2);
    printf("compare %s", (equal == true) ? "true" : "false");
    return 0;
}
