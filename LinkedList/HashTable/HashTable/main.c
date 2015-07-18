//
//  main.c
//  HashTable
//
//  Created by Dario Lencina on 7/18/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "HashMap.h"



int main(int argc, const char * argv[]) {
    HashTableNode nodes[2] = {{"Pantera",234}, {"Pantera2",223}};
    HashTable * hashTable = newHashMap(nodes, 2);
    hashTableSet(hashTable, "key2", 666);
    hashTableSet(hashTable, "key3", 666);
    printHashTable(hashTable);
    int key2 = hashTableGet(hashTable, "key2");
    printf("\nkey2 %i\n", key2);
    
    return 0;
}
