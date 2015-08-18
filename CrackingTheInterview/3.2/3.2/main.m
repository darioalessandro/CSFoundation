//
//  main.m
//  3.2
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QueueWithMin.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        QueueWithMin * queue = [QueueWithMin new];
        [queue push:@30];
        [queue push:@43];
        [queue push:@13];
        [queue push:@33];

        NSLog(@"min %@", [queue min]);
        NSLog(@"max %@", [queue max]);
        NSLog(@"pop %@", [queue pop]);
        NSLog(@"pop %@", [queue pop]);
        NSLog(@"min %@", [queue min]);
        NSLog(@"max %@", [queue max]);
        NSLog(@"pop %@", [queue pop]);
        NSLog(@"max %@", [queue max]);
        NSLog(@"pop %@", [queue pop]);
        NSLog(@"min %@", [queue min]);
        NSLog(@"max %@", [queue max]);
    }
    return 0;
}
