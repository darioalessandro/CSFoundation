//
//  main.c
//  8Puzzle
//
//  Created by Dario Lencina on 7/23/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int (array3x3)[3][3];

typedef struct EightPuzzle {
    int tiles [3][3];;
    int i_0;
    int j_0;
} EightPuzzle;

EightPuzzle eightPuzzle(){
    EightPuzzle p = {};
    return p;
}

void eight_print(EightPuzzle * puzzle) {
    
    printf("**********\n");
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++)
            printf(" %i ", puzzle -> tiles[i][j]);
        printf("\n");
    }
    printf("**********\n\n");
}

bool eight_equal(EightPuzzle * p1, EightPuzzle * p2) {
    bool eight_equal = true;
    
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            if(p1->tiles[i][j] != p2 -> tiles[i][j]) {
                eight_equal = false;
                i = 4;
                j = 4;
            }
        }
    }
    
    return eight_equal;
    
}

bool eight_isSolution(EightPuzzle * puzzle) {
    static EightPuzzle solution = {{1,2,3,4,5,6,7,8,0}, 2, 2};
    return eight_equal(puzzle, &solution);
}

void cloneTiles(int original [3][3] , int clone [3][3] ) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            clone[i][j] = original[i][j];
    
}


void appendTilesToLinkedList(LinkedList * list, EightPuzzle puzzle) {
    printf("appending\n");
    eight_print(&puzzle);
    append(list, &puzzle);
}



bool solutionContainsPosition(LinkedList * solution, EightPuzzle * puzzle) {
    bool contains = false;
    LinkedList * n = solution;
    while (n != NULL) {
        EightPuzzle * npuzzle = n -> data;
        printf("+comparing****\n");
        if(npuzzle) {
            eight_print(puzzle);
            eight_print(npuzzle);
        }
        printf("-comparing****\n");
        
        if(npuzzle != NULL && eight_equal(puzzle,npuzzle)){
            contains = true;
            break;
        }
        n = n->next;
    }
    
    return contains;
}

void solve(EightPuzzle * initialPuzzle, LinkedList * solution, int depth) {

    EightPuzzle nextMove = eightPuzzle();
    EightPuzzle * nextMovePtr = &nextMove;
    cloneTiles(initialPuzzle->tiles,  nextMove.tiles);
    nextMovePtr -> i_0 = initialPuzzle -> i_0;
    nextMovePtr -> j_0 = initialPuzzle -> j_0;
    
    while (eight_isSolution(initialPuzzle) == false && depth < 10) {
        int i_0 = nextMovePtr -> i_0;
        int j_0 = nextMovePtr -> j_0;
        if(i_0 - 1 >= 0){
            nextMovePtr -> tiles[i_0][j_0] = nextMovePtr -> tiles[i_0-1][j_0];
            nextMovePtr -> tiles[i_0-1][j_0] = 0;
            nextMovePtr -> i_0 = i_0 -1;
        } else if(i_0 +1 <= 2){
            nextMovePtr -> tiles[i_0][j_0] = nextMovePtr -> tiles[i_0+1][j_0];
            nextMovePtr -> tiles[i_0+1][j_0] = 0;
            nextMovePtr -> i_0 = i_0 + 1;
        } else if(j_0 -1 >= 0){
            nextMovePtr -> tiles[i_0][j_0] = nextMovePtr -> tiles[i_0][j_0-1];
            nextMovePtr -> tiles[i_0][j_0-1] = 0;
            nextMovePtr -> j_0 = j_0 -1;
        } else if(j_0 +1 <= 2){
            nextMovePtr -> tiles[i_0][j_0] = nextMovePtr -> tiles[i_0][j_0+1];
            nextMovePtr -> tiles[i_0][j_0+1] = 0;
            nextMovePtr -> j_0 = j_0 + 1;
        }
        
        if(solutionContainsPosition(solution, nextMovePtr) == false) {
            printf("added \n");
            eight_print(nextMovePtr);
            appendTilesToLinkedList(solution, *nextMovePtr);
            depth ++;
            //cloneTiles(nextMovePtr ->tiles, initialPuzzle -> tiles);
        } else {
            printf("discarted \n");
            eight_print(nextMovePtr);
        }
    }
    
    if(eight_isSolution(initialPuzzle)){
        printf("found solution");
    }

}

int main(int argc, const char * argv[]) {
    int initial[3][3];
    
    initial[0][0] = 3;
    initial[0][1] = 7;
    initial[0][2] = 4;
    initial[1][0] = 5;
    initial[1][1] = 1;
    initial[1][2] = 2;
    initial[2][0] = 8;
    initial[2][1] = 6;
    initial[2][2] = 0;

    EightPuzzle puzzle = eightPuzzle();
    puzzle.i_0 = 2;
    puzzle.j_0 = 2;
    cloneTiles(initial, puzzle.tiles);
    
    printf("test equal %i\n", eight_equal(&puzzle,&puzzle));
    
    eight_print(&puzzle);
    
    LinkedList * solutions = createNode(NULL);

    
    solve(&puzzle, solutions, 0);
    
    LinkedList * n = solutions;
    printf("**\n");
    while (n != NULL) {
        EightPuzzle * p = n -> data;
        if(p != NULL){
            eight_print(p);
        }
        n = n->next;
    }
    
    
    return 0;
}
