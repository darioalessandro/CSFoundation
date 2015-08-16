//
//  MergeSort.m
//  MergeSort
//
//  Created by Dario Lencina on 7/15/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MergeSort.h"

@implementation MergeSort

+ (NSArray *)sortStr: (NSString *) a {
    const char * cPtr = [a UTF8String];
    NSMutableArray * stringArray = [NSMutableArray new];
    for(int i = 0 ; i < [a length] ; i ++){
        [stringArray addObject:[NSString stringWithFormat:@"%c", cPtr[i]]];
    }
    return [self sort:stringArray];
}

+(NSArray *)sort: (NSArray *) a{
    if(a.count < 2) {
        return a;
    } else {
        NSRange chunkARange = NSMakeRange(0, a.count/2);
        NSRange chunkBRange = NSMakeRange(chunkARange.length, a.count - chunkARange.length);
        
        NSArray * chunkA = [self sort:[a subarrayWithRange:chunkARange]];
        NSArray * chunkB = [self sort:[a subarrayWithRange:chunkBRange]];
        return [self mergeSort:chunkA with:chunkB];
    }
}

+(NSArray *)mergeSort: (NSArray *)chunkA with:(NSArray *)chunkB {
    long sortedArraySize = chunkA.count + chunkB.count;
    NSMutableArray * sortedArray = [NSMutableArray arrayWithCapacity:sortedArraySize];
    
    long aPtr = 0;
    long bPtr = 0;
    
    for(long k = 0; k < sortedArraySize ; k++){
        if(aPtr >= chunkA.count)
            [sortedArray addObject:chunkB[bPtr++]];
        else if(bPtr >= chunkB.count)
            [sortedArray addObject:chunkA[aPtr++]];
        else if([chunkA[aPtr] compare:chunkB[bPtr]] == NSOrderedAscending)
            [sortedArray addObject:chunkA[aPtr++]];
        else
            [sortedArray addObject:chunkB[bPtr++]];
    }
    
    return sortedArray;
}

@end