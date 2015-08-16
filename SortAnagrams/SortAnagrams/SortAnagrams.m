//
//  SortAnagrams.m
//  SortAnagrams
//
//  Created by Dario on 8/11/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "SortAnagrams.h"
#import "MergeSort.h"

@implementation SortAnagrams


-(NSArray *)sort:(NSArray *)anagrams {
    NSMutableDictionary * weightTable = [NSMutableDictionary new];
    
    for(NSString * word in anagrams)
        [weightTable setObject:[MergeSort sortStr:word] forKey:word];
    
    NSArray * allWeights = [[NSSet setWithArray:[weightTable allValues]] allObjects];
    NSLog(@"weightTable %@", weightTable);
    
    NSMutableArray * results = [NSMutableArray new];
    
    for(NSNumber * n in allWeights)
        [results addObject:[weightTable allKeysForObject:n]];

    return results;
}

@end
