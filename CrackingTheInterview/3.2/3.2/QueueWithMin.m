//
//  QueueWithMin.m
//  3.2
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "QueueWithMin.h"

@implementation QueueWithMin

NSMutableArray * array;
NSMutableArray * minArray;
NSMutableArray * maxArray;

-(id)init{
    self= [super init];
    if( self){
        array = [NSMutableArray new];
        minArray = [NSMutableArray new];
        maxArray = [NSMutableArray new];
    }
    return self;
}

-(NSNumber *)min {
    return [minArray lastObject];
}

-(NSNumber *)max {
    return [maxArray lastObject];
}

-(NSNumber *)pop {
    NSNumber * poppedVal = [array lastObject];
    if(poppedVal == [self min]) [minArray removeLastObject];
    if(poppedVal == [self max]) [maxArray removeLastObject];
    [array removeLastObject];    
    return poppedVal;
}

-(void)push:(NSNumber *)number{
    if(number <= [self min] || [self min] == nil) [minArray addObject:number];
    
    if(number >= [self max] || [self max] == nil) [maxArray addObject:number];
    
    [array addObject:number];
}

@end
