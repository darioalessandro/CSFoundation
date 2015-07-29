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
    
    @IBOutlet weak var tilenine: UIView!
    
    @IBOutlet weak var zerozero: UILabel!
    
    @IBOutlet weak var zeroone: UILabel!
    
    @IBOutlet weak var zerotwo: UILabel!
    
    @IBOutlet weak var onezero: UILabel!
    
    @IBOutlet weak var oneone: UILabel!
    
    @IBOutlet weak var onetwo: UILabel!
    
    @IBOutlet weak var twozero: UILabel!
    
    @IBOutlet weak var twoone: UILabel!
    
    @IBOutlet weak var twotwo: UILabel!
    
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
    
    func renderState(state : PuzzleState) -> Void {
        let labels : [[UILabel]] = [[zerozero, zeroone, zerotwo], [onezero, oneone,onetwo], [twozero, twoone, twotwo]]
        let views : [[UIView]] = [[tile1, tile2, tile3], [tile4, tile5, tile6], [tile7,tile8, tilenine]]
        
        for i in 0 ... 2{
            for j in 0 ... 2{
                labels[i][j].text = String(state.matrix[i][j])
                if state.matrix[i][j] == 0 {
                   views[i][j].layer.opacity = 0
                } else {
                   views[i][j].layer.opacity = 1
                }
            }
        }
    }
    
    func renderStates(states : [PuzzleState]) -> Void {
        
        if !states.isEmpty {
            renderState(states.first!)
            let delayTime = dispatch_time(DISPATCH_TIME_NOW,
                Int64(1 * Double(NSEC_PER_SEC)))
            
            dispatch_after(delayTime, dispatch_get_main_queue()) {
                self.renderStates(states.filter{$0 != states.first})
            }
        }
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        eightPuzzle.printMatrix()
        
        /*
        var easy = self.solve(Node.easy(), maxDepth: 5, numberOfSolutions: 1)[0]
        println("found solution for easy puzzle")
        easy.printHistory() */
        
        var medium = self.solve(Node.medium(), maxDepth: 20, numberOfSolutions: 1)[0]
        println("found solution for medium puzzle")
        renderStates(medium.historyOfStates())
        
       
        /*var hard = self.solve(Node.hard(), maxDepth: 25, numberOfSolutions: 1)[0]
        println("found solution for hard puzzle")
        hard.printHistory()
        
        var random = self.solve(Node.random(), maxDepth: 30, numberOfSolutions: 1 )[0]
        println("found solution for random puzzle")
        random.printHistory()
        */
        
    
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
    
                    newChildren.forEach{$0.parent = node}
                
                    newChildren.sort{
                        $0.state!.closenessToSolution() < $1.state!.closenessToSolution()
                    }
    
                    if newChildren.isEmpty == false {
                        newChildren.forEach{solveHelper($0)}
                    }
                }
            }
        }
    
        solveHelper(root)
        
        return solutions
    }

}

