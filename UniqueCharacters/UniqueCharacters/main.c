//
//  main.c
//  UniqueCharacters
//
//  Created by Dario Lencina on 7/26/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "HashMap.h"

bool hasUniqueCharacters(char * str) {
    HashTable  * table = newHashMap(NULL, 0);
    char * ptr = &str[0];
    while (ptr != NULL && *ptr != '\0') {
        char temp[2] = {*ptr,'\0'};
        if(hashTableGet(table, temp) == HashTableNotFound){
            hashTableSet(table, temp, 1);
            printHashTable(table);
            ptr++;
        }else{
            printHashTable(table);
            printf("string does not have unique characters, found at least two %c\n", *ptr);
            ptr = NULL;
        }
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    char * str = malloc(sizeof(char) * 50);
    str = "metallica";
    
    printf("has unique characters %i", hasUniqueCharacters(str));
    
    return 0;
}
