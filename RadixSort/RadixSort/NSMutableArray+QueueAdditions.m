//
//  NSMutableArray+QueueAdditions.m
//  RadixSort
//
//  Created by Dario on 8/8/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import "NSMutableArray+QueueAdditions.h"

@implementation NSMutableArray (QueueAdditions)

- (id) dequeue {
    if ([self isEmpty]) return nil; 
    id headObject = [self objectAtIndex:0];
    if (headObject != nil) {
        [self removeObjectAtIndex:0];
    }
    return headObject;
}

- (void) enqueue:(id)anObject {
    [self addObject:anObject];
}

- (BOOL)isEmpty {
    return [self count] == 0;
}

@end
