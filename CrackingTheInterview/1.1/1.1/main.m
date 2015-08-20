//
//  main.m
//  1.1
//
//  Created by Dario on 8/19/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <stdbool.h>

bool hasUniqueCharactersSet(const char * str, unsigned long length) {
    if (length > 256) return false;
    
    bool allChars[256] = {0};
    
    for(int i = 0; i < length; i++) {
        char c = str[i];
        if(allChars[c])
            return false;
        else
            allChars[c] = true;
    }
    return true;
}

bool hasUniqueCharactersBinary(const char * str, unsigned long length) {
    if (length > 'z' - 'a' + 1) return false;
    
    int checker = 0;
    
    for(int i = 0; i < length; i++) {
        int c = str[i] - 'a';
        if(checker & (1 << c))
            return false;
        checker = checker | (1 << c);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSString * sample1= @"qwertyuiopasdfghjklzxcvbnm";
        NSLog(@"hasUniqueCharactersSet %d", hasUniqueCharactersSet([sample1 UTF8String], [sample1 length]));
        NSLog(@"hasUniqueCharactersBinary %d", hasUniqueCharactersBinary([sample1 UTF8String], [sample1 length]));
    }
    return 0;
}
