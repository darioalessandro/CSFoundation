//
//  main.m
//  SortAnagrams
//
//  Created by Dario on 8/10/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "SortAnagrams.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        SortAnagrams * s = [SortAnagrams new];
        NSLog(@"sorted %@", [s sort:@[@"bba", @"za", @"bbb", @"aaa", @"aab", @"baa", @"cca", @"acc"]]);
        
    }
    return 0;
}
