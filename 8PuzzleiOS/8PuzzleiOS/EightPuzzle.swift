//
//  EightPuzzle.swift
//  8PuzzleiOS
//
//  Created by Dario Lencina on 7/28/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import Foundation

class PuzzleState: NSObject {
    
    class func random() -> PuzzleState {
        var puzzle = PuzzleState()
        var tiles : [Int] = [0,1,2,3,4,5,6,7,8]
        for i in 0 ... 2 {
            for j in 0 ... 2 {
                var nextIndex = Int(arc4random_uniform(UInt32(tiles.count)))
                var n = tiles.removeAtIndex(nextIndex)
                puzzle.matrix[i][j] = n;
                if(n == 0){
                    puzzle.gapCoordinates = (i,j)
                }
            }
        }
        return puzzle
    }
    
    class func easy() -> PuzzleState {
        var puzzle = PuzzleState()
        puzzle.matrix[0] = [1, 2, 3]
        puzzle.matrix[1] = [4, 5, 6]
        puzzle.matrix[2] = [7, 0, 8]
        puzzle.gapCoordinates = (2,1)
        return puzzle
    }
    
    class func medium() -> PuzzleState {
        var puzzle = PuzzleState()
        puzzle.matrix[0] = [1, 2, 3]
        puzzle.matrix[1] = [7, 0, 8]
        puzzle.matrix[2] = [4, 5, 6]
        puzzle.gapCoordinates = (1,1)
        return puzzle
    }
    
    class func hard() -> PuzzleState {
        var puzzle = PuzzleState()
        puzzle.matrix[0] = [7, 0, 8]
        puzzle.matrix[1] = [1, 2, 3]
        puzzle.matrix[2] = [4, 5, 6]
        puzzle.gapCoordinates = (0,1)
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
        println("gap goordinates \(gapCoordinates)")
    }
    
    let solution : Double = Double(0.3691275168)
    
    func closenessToSolution() -> Double {
    var num  = matrix[0][0] + matrix[0][1] * 2 + matrix[0][2] * 3 + matrix[1][0] * 4 + matrix[1][2] * 5
        
        
    var den  = matrix[1][2] * 6 + matrix[2][0] * 7 + matrix[2][1] * 8 + matrix[2][2] * 0
   
    var division =  Double(num)/Double(den) / solution
        
    var closeness = Double.abs(1 - division)
    
    return closeness
    }
}