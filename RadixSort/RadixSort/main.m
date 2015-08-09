//
//  main.m
//  RadixSort
//
//  Created by Dario on 8/8/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "RadixSort.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"sorted %@", [RadixSort sort:@[@9,@179,@139, @38, @5, @36]]);
        NSLog(@"sorted %@", [RadixSort sort:@[@0]]);
    }
    return 0;
}
