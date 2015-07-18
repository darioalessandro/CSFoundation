//
//  HashMap.c
//  HashTable
//
//  Created by Dario Lencina on 7/18/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "HashMap.h"

HashTableNode * newHashTableNode(char * key, int value) {
    HashTableNode * newNode = malloc( sizeof(HashTableNode) );
    newNode -> key = key;
    newNode -> value = value;
    return newNode;
}

int hashTableGet(HashTable * hashTable, char * key){
    for (int i = 0; i < hashTable->size; i++) {
        HashTableNode * node = &hashTable -> nodes[i];
        if(strcmp(node->key, key) == 0){
            return node -> value;
        }
    }
    return HashTableNotFound;
}

void hashTableSet(HashTable * hashTable, HashKey key, int value) {
    int existingValue = hashTableGet(hashTable, key);
    if(existingValue == HashTableNotFound){
        HashTableNode * nodes = hashTable -> nodes;
        int size = hashTable -> size;
        nodes[size] = *newHashTableNode(key, value);
        hashTable -> size = size + 1;
    }else{
        printf("\nunable to set %s because it already exists", key);
    }
}

HashTable * newHashMap(HashTableNode * nodes, size_t size) {
    HashTable * hashTable = malloc(sizeof(HashTable));
    hashTable -> nodes = malloc(sizeof(HashTableNode));
    hashTable -> size = 0;
    for (int i = 0; i < size; i++) {
        HashTableNode n = nodes[i];
        hashTableSet(hashTable,n.key,n.value);
    }
    return hashTable;
}

void printHashTable(HashTable * hash) {
    printf("\n**\n");
    for (int i = 0; i < hash->size; i++) {
        HashTableNode * node = &hash -> nodes[i];
        printf("%s : %i\n", node -> key, node -> value);
    }
    printf("**\n");
}