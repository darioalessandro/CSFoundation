//
//  HashMap.h
//  HashTable
//
//  Created by Dario Lencina on 7/18/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#ifndef __HashTable__HashMap__
#define __HashTable__HashMap__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdio.h>

typedef char * HashKey;

typedef struct HashTableNode {
    char * key;
    int value;
    char * hash;
} HashTableNode;

typedef struct HashTable {
    HashTableNode * nodes;
    int size;
} HashTable;

enum HashTableVals {
    HashTableNotFound = -10000,
    HashTableEmpty = -20000
};

HashTableNode * newHashTableNode(char * key, int value);

int hashTableGet(HashTable * hashTable, char * key);

void hashTableSet(HashTable * hashTable, HashKey key, int value);

HashTable * newHashMap(HashTableNode * nodes, size_t size);

void printHashTable(HashTable * hash);

#endif /* defined(__HashTable__HashMap__) */
