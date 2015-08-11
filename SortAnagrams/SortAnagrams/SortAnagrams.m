//
//  SortAnagrams.m
//  SortAnagrams
//
//  Created by Dario on 8/11/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "SortAnagrams.h"

@implementation SortAnagrams

NSNumber * weightForString(NSString * word){
    
    long weight = 0;
    const char * cRepresentation = [[word lowercaseString] UTF8String];
    for(int i = 0; i < word.length ; i++)
        weight += cRepresentation[i] ;
    return @(weight);
}

-(NSArray *)sort:(NSArray *)anagrams {
    NSMutableDictionary * weightTable = [NSMutableDictionary new];
    
    for(NSString * word in anagrams)
        [weightTable setObject:weightForString(word) forKey:word];
    
    NSArray * allWeights = [[NSSet setWithArray:[weightTable allValues]] allObjects];
    NSLog(@"weightTable %@", weightTable);
    
    NSMutableArray * results = [NSMutableArray new];
    
    for(NSNumber * n in allWeights)
        [results addObject:[weightTable allKeysForObject:n]];

    return results;
}

@end
