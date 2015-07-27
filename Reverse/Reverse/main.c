//
//  main.c
//  Reverse
//
//  Created by Dario Lencina on 7/26/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char * str) {
    unsigned long length = strlen(str);
    if(length == 0) {
        printf("nothing to reverse\n");
        return;
    }
    char * startPtr = &str[0];
    char * endPtr = startPtr + (sizeof(char) * length -1 );
    
    while (startPtr < endPtr) {
        char tmp = *startPtr;
        *startPtr ++ = *endPtr;
        *endPtr -- = tmp;
    }
    
}

int main(int argc, const char * argv[]) {
    char *s = malloc(sizeof(char) * 50);
    strcpy(s, "Get bored");
    reverse(s);
    printf("reversed: %s", s);
    free(s);
    return 0;
}
