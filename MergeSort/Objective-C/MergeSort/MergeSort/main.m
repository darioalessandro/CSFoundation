//
//  main.m
//  MergeSort
//
//  Created by Dario Lencina on 7/15/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MergeSort.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSArray * collection = @[@234,@4321,@1423,@4231,@4123,@2341,@135,@1336,@3,@413,@6314,@6,@1,@(-346),@346,@13,@136,@1346,@243626,@24];
        NSLog(@"Sorted collection: %@", [MergeSort sort:collection]);
        
        NSArray * collection2 = @[];
        NSLog(@"Sorted collection: %@", [MergeSort sort:collection2]);
        
        NSArray * collection3 = @[@12];
        NSLog(@"Sorted collection: %@", [MergeSort sort:collection3]);
        
        NSArray * collection4 = @[@12];
        NSLog(@"Sorted collection: %@", [MergeSort sort:collection4]);
    }
    return 0;
}
