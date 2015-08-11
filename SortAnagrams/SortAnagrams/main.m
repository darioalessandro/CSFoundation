//
//  main.m
//  SortAnagrams
//
//  Created by Dario on 8/10/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

NSNumber * weightForString(NSString * word){

    long weight = 0;
    const char * cRepresentation = [[word lowercaseString] UTF8String];
    for(int i = 0; i < word.length ; i++)
        weight += cRepresentation[i];
    
    weight = weight + ('z' * word.length);
    
    return @(weight);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        NSArray * unsortedAnagrams = @[@"zz", @"zw", @"noni", @"nino", @"opni", @"diet", @"its", @"once", @"edit", @"hug", @"sit", @"ugh", @"cone", @"tide"];
        
        NSMutableDictionary * weightTable = [NSMutableDictionary new];
        
        for(NSString * word in unsortedAnagrams)
            [weightTable setObject:weightForString(word) forKey:word];
        
        NSArray * allWeights = [[NSSet setWithArray:[weightTable allValues]] allObjects];
        NSLog(@"weightTable %@", weightTable);
        
        for(NSNumber * n in allWeights)
            NSLog(@"%@", [weightTable allKeysForObject:n]);
        
    }
    return 0;
}
