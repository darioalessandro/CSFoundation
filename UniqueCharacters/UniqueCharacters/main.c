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
    HashTable  * table = newHashMap(newHashTableNode("asdsd", 1), 1);;
    char * ptr = str;
    while (ptr && *ptr != '\0') {
        char * temp = malloc(sizeof(char) * 2);
        memcpy(temp, ptr, 1);
        temp[1] = '\0';
        if(hashTableGet(table, temp) == HashTableNotFound){
            hashTableSet(table, temp, 1);
            ptr++;
        }else{
            printHashTable(table);
            printf("string does not have unique characters, found at least two %c\n", *ptr);
            ptr = NULL;
        }
        free(temp);
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    char * str = malloc(sizeof(char) * 50);
    str = "Blind";
    
    printf("has unique characters %i", hasUniqueCharacters(str));
    
    return 0;
}
