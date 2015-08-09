//
//  NSMutableArray+QueueAdditions.h
//  RadixSort
//
//  Created by Dario on 8/8/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (QueueAdditions)
- (id) dequeue;
- (void) enqueue:(id)obj;
- (BOOL)isEmpty;

@end
