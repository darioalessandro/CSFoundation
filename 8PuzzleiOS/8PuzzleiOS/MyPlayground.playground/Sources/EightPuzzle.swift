//
//  EightPuzzle.swift
//  8PuzzleiOS
//
//  Created by Dario Lencina on 7/28/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import Foundation

class EightPuzzle: NSObject {
    
    class func random() -> EightPuzzle {
        var puzzle = EightPuzzle()
        var tiles : [Int] = [0,1,2,3,4,5,6,7,8]
        for i in 0 ... 2 {
            for j in 0 ... 2 {
                var nextIndex = Int(rand()/RAND_MAX) * tiles.count
                var n = tiles.removeAtIndex(nextIndex)
                puzzle.matrix[i][j] = n;
            }
        }
        puzzle.printMatrix()
        return puzzle
    }
    
    var matrix : [[Int]] = [[1,2,3],[4,5,6],[7,8,0]]
    
    var gapCoordinates : (Int, Int) = (2,2)
    
    func tileCoordinates(tile : Int) -> (Int, Int) {
        var tileCoordinates = (-1,-1)
        for i in 0 ... 2 {
            for j in 0 ... 2 {
                if matrix[i][j] == tile {
                    tileCoordinates = (i,j);
                }
            }
        }
        
        return tileCoordinates;
    }
    
    func printMatrix() {
        
        println("****\n")
        for i in 0 ... 2 {
            for j in 0 ... 2 {
                var m  = matrix[i][j]
                print("\(m) ")
            }
            println("\n")
        }
        println("****")
    }
}