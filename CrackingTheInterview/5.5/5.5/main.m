//
//  main.m
//  5.5
//
//  Created by Dario on 8/17/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {

        int a = 3;
    
        int b = 7;
        
        int xo = a ^ b;
        
        int bitsToFlip = 0;
        while(xo != 0) {
            if(xo % 2 != 0)
                bitsToFlip ++;
            xo >>= 1;
        }
        
        NSLog(@"number of bits to flip %d\n", bitsToFlip);
        
    }
    return 0;
}
