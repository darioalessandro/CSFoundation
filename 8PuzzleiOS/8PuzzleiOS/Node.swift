//
//  Node.swift
//  8PuzzleiOS
//
//  Created by Dario Lencina on 7/28/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import Foundation

class Node : NSObject {
    
    class func random() -> Node {
        var node = Node()
        node.state = PuzzleState.random()
        return node
    }
    
    class func easy() -> Node {
        var node = Node()
        node.state = PuzzleState.easy()
        return node
    }
    
    class func medium() -> Node {
        var node = Node()
        node.state = PuzzleState.medium()
        return node
    }
    
    class func hard() -> Node {
        var node = Node()
        node.state = PuzzleState.hard()
        return node
    }
    
    var state : PuzzleState? = nil
    
    var depth : Int = 0
    
    var parent : Node? = nil
    
    var children : [Node]? = nil
    
    func isDifferent(node : Node) -> Bool  {
        
        if parent != nil {
            var isDifferent : Bool = false
            for i in 0 ... 2 {
                for j in 0 ... 2 {
                    if node.state!.matrix[i][j] != parent!.state!.matrix[i][j] {
                        isDifferent = true
                    }
                }
            }
            if(isDifferent) {
                return parent!.isDifferent(node)
            } else {
                return isDifferent
            }
        } else {
            return true;
        }
    }

    func generateChildShifting(i : Int, j : Int) -> Node {
        var s = self.state!
        var oldValue = s.matrix[i][j]
        
        var newMatrix : [[Int]] = []
        
        for ii in 0 ... 2 {
            var newRow : [Int] = []
            for jj in 0 ... 2 {
                newRow.append(s.matrix[ii][jj])
            }
            newMatrix.append(newRow)
        }
        
        
        newMatrix[s.gapCoordinates.0][s.gapCoordinates.1] = oldValue
        newMatrix[i][j] = 0
        
        var node = Node()
        node.state = PuzzleState()
        node.state!.matrix = newMatrix
        node.state!.gapCoordinates = (i,j)
        node.depth = depth + 1
        return node
    }
    
    func generateChildren() -> [Node] {
        var s  = self.state!
        
        var children : [Node] = []
        
        if s.gapCoordinates.0 > 0 {
            children.append(self.generateChildShifting(s.gapCoordinates.0 - 1, j: s.gapCoordinates.1))
        }
        
        if s.gapCoordinates.0 < 2{
            children.append(self.generateChildShifting(s.gapCoordinates.0 + 1, j: s.gapCoordinates.1))
        }
        
        if s.gapCoordinates.1 < 2 {
            children.append(self.generateChildShifting(s.gapCoordinates.0, j: s.gapCoordinates.1 + 1))
        }
        
        if s.gapCoordinates.1 > 0 {
            children.append(self.generateChildShifting(s.gapCoordinates.0 , j: s.gapCoordinates.1 - 1))
        }
        
        return children
    }
    
    func historyOfStates() -> [PuzzleState] {
        var states : [PuzzleState] = []
        var n = self
        states.append(n.state!)
        while(n.parent != nil) {
            n = n.parent!
            states.append(n.state!)
        }
        return states.reverse()
    }
    
    func printHistory() -> Void {
        var states = historyOfStates()
        for state in states {
            state.printMatrix()
        }
    }
    
    /*
    
    Possible children
    
    if(i > 0)
    i - 1, j
    
    if(i< 2)
    i + 1, j
    
    if(j < 2)
    i, j + 1
    
    if(j > 0)
    i, j - 1
    
    
    */
    
}