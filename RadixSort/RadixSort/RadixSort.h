//
//  RadixSort.h
//  RadixSort
//
//  Created by Dario on 8/8/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RadixSort : NSObject

+(NSArray *)sort:(NSArray *) array;

@property NSMutableArray * queues;

@end
