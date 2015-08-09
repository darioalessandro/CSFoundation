//
//  RadixSort.m
//  RadixSort
//
//  Created by Dario on 8/8/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "RadixSort.h"
#import "NSMutableArray+QueueAdditions.h"
#import <math.h>


@implementation RadixSort

+(NSArray *)sort:(NSArray *) array {
    return [[RadixSort new] sort:array];
}

-(NSArray *)sort:(NSArray *) array {
    NSNumber * max= getMax(array);
    NSArray * sorted = array;
    for (int exp = 1; max.doubleValue/exp > 0; exp *= 10){
        sorted = [self countSort:sorted exp:exp];
    }
    
    return sorted;
}

-(NSArray *)countSort:(NSArray *) array exp:(int) exp {
    for(int i = 0; i< [array count] ; i++){
        NSNumber * element = array[i];
        double  modRes = fmod([element doubleValue] , exp * 10);
        int div = round(modRes / exp);
        [self.queues[div] enqueue:element];
    }
    
    NSMutableArray * newArray = [NSMutableArray new];
    for(int i = 0; i <= 9; i++) {
        while (![self.queues[i] isEmpty]) {
            id obj= [self.queues[i] dequeue];
            [newArray addObject:obj];
        }
    }
    return newArray;
}

NSNumber * getMax(NSArray * arr){
    NSNumber * mx = arr[0];
    for (int i = 1; i < [arr count]; i++)
        if ([arr[i] doubleValue] > mx.doubleValue)
            mx = arr[i];
    return mx;
}

-(id)init {
    self = [super init];
    if(self){
        self.queues = [NSMutableArray new];
        for(int i = 0; i <= 9; i++)
            [self.queues addObject:[NSMutableArray array]];
    }
    return self;
}

@end
