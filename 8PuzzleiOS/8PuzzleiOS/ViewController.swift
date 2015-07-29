//
//  ViewController.swift
//  8PuzzleiOS
//
//  Created by Dario Lencina on 7/28/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var tile1: UIView!

    @IBOutlet weak var tile2: UIView!
    
    @IBOutlet weak var tile3: UIView!
    
    @IBOutlet weak var tile4: UIView!
    
    @IBOutlet weak var tile5: UIView!
    
    @IBOutlet weak var tile6: UIView!
    
    @IBOutlet weak var tile7: UIView!
    
    @IBOutlet weak var tile8: UIView!
    
    var eightPuzzle = PuzzleState.random()
    
    func translateView(view : UIView, pan : UIPanGestureRecognizer) {
        var  target = pan.view
        var translation = pan.translationInView(self.view)
        target!.center=CGPointMake(target!.center.x+translation.x, target!.center.y+translation.y)
        pan.setTranslation(CGPointZero, inView:self.view)
    }
    
    func panEventHandler(pan : UIPanGestureRecognizer) {
        translateView(pan.view!,pan: pan)
        refreshPuzzle()
    }
    
    func refreshPuzzle(){
        eightPuzzle = PuzzleState.random()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        eightPuzzle.printMatrix()
        
        println("found solution for easy puzzle \(self.solve(Node.easy(), maxDepth: 5, numberOfSolutions: 1))")
        
       /* println("found solution for easy puzzle \(self.solve(Node.medium(), maxDepth: 20, numberOfSolutions: 1))")
        
        println("found solution for easy puzzle \(self.solve(Node.hard(), maxDepth: 25, numberOfSolutions: 1))")
        
        println("found solution for easy puzzle \(self.solve(Node.random(), maxDepth: 30, numberOfSolutions: 1 ))") */
    
    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func isSolution(node : Node ) -> Bool {
        var matrix = node.state!.matrix
    
        var isSolution = true
    
        for i in 0 ... 2 {
            for j in 0 ... 2 {
                if i == 2 && j == 2 {
                    if matrix[j][j] != 0 {
                        isSolution = false
                    }
                } else {
                    if matrix[i][j] != 3 * i + j + 1 {
                        isSolution =  false
                    }
                }
            }
        }
        return isSolution
    }
    
    func solve(root : Node, maxDepth : Int, numberOfSolutions : Int) -> [Node] {
        
        var solutions : [Node] = []
        
        var solveHelper: (Node) -> () = { _ in }
        
        solveHelper = { node in
            if(solutions.count < numberOfSolutions) {
                if self.isSolution(node) {
                    solutions.append(node)
                } else if (node.depth < maxDepth) {
                    var newChildren : [Node] = node.generateChildren().filter{node.isDifferent($0)}
    
                    newChildren.forEach{var n = $0 as Node; n.parent = node}
                
                    newChildren.sort{
                        $0.state!.closenessToSolution() < $1.state!.closenessToSolution()
                    }
    
                    if newChildren.isEmpty == false {
                        for children in newChildren {
                            solveHelper(children)
                        }
                    }
                }
            }
        }
    
        solveHelper(root)
        
        return solutions
    }


}

