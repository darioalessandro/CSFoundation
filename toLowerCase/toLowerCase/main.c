//
//  main.c
//  toLowerCase
//
//  Created by Dario on 8/11/15.
//  Copyright (c) 2015 Dario. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char toLowerCase(char a){
    if(a < 'a' && a >= 'A')
        return a + 'a' - 'A';
    else
        return a;
    
}

int main(int argc, const char * argv[]) {
    char * input = "ThiS is THE Rythm of my LIFE\n";
    printf("input: %s", input);
    long length = strlen(input);
    char * output = malloc(sizeof(char) * length -1 );
    for (long i = 0 ; i <= length; i++){
        output[i] = toLowerCase(input[i]);
    }
    printf("output: %s", output);
    free(output);
    
    
    return 0;
}

