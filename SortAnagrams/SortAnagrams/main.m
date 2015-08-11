//
//  main.m
//  SortAnagrams
//
//  Created by Dario on 8/10/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

NSNumber * weightForString(NSString * word){
    int weight = 0;
    const char * cRepresentation = [word UTF8String];
    for(int i = 0; i < word.length ; i++)
        weight += cRepresentation[i];
    
    return @(weight);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSArray * unsortedAnagrams = @[@"diet", @"its", @"once", @"edit", @"hug", @"sit", @"ugh", @"cone", @"tide"];
        NSMutableDictionary * weightTable = [NSMutableDictionary new];
        
        for(NSString * word in unsortedAnagrams)
            [weightTable setObject:weightForString(word) forKey:word];
        
        NSArray * allWeights = [[NSSet setWithArray:[weightTable allValues]] allObjects];
        
        for(NSNumber * n in allWeights)
            NSLog(@"%@", [weightTable allKeysForObject:n]);
        
    }
    return 0;
}
