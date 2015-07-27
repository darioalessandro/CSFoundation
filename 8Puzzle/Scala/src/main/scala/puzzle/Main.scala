package puzzle

import java.util.{Calendar, Date}

import scala.collection.mutable.ListBuffer


object Main extends App {

  def isSolution(node : Node ) : Boolean = {
    val matrix = node.state.matrix

    var isSolution = true

    for(i <- 0 to 2; j <- 0 to 2) {
      if(i == 2 && j == 2) {
        if(matrix(j)(j) != 0)
          isSolution = false
      } else {
        if(matrix(i)(j) != 3 * i + j + 1)
          isSolution =  false
      }
    }
    isSolution
  }

  def solve(root : Node, maxDepth : Int, numberOfSolutions : Int) : List[Node] = {
   val start = Calendar.getInstance().getTimeInMillis
    var solutions = List[Node]()

    def solveHelper(node : Node) : Unit = {
      if(  solutions.length < numberOfSolutions) {
        if (isSolution(node)) {
          solutions = node +: solutions
        } else if (node.depth < maxDepth) {
          var newChildren = node.generateChildren.filter(node.isDifferent)

          newChildren = newChildren.map(_.setParent(Some(node))).sortBy{n => n.state.closenessToSolution}

          if (newChildren.nonEmpty)
            newChildren.foreach(c => solveHelper(c))

        }
      }
    }
    solveHelper(root)
    println(s"it took ${Calendar.getInstance().getTimeInMillis - start} ms")
    solutions
  }

  println(s"Found solutions for easy puzzle = ${solve(Node(PuzzleState.easy), maxDepth = 5, numberOfSolutions = 1)}")

    println(s"Found solutions for medium puzzle = ${solve(Node(PuzzleState.medium), maxDepth = 20, numberOfSolutions = 1)}")

  println(s"Found solutions for hard puzzle = ${solve(Node(PuzzleState.hard), maxDepth = 25, numberOfSolutions = 1)}")

  println(s"Found solutions for random puzzle = ${solve(Node(PuzzleState.random), maxDepth = 30, numberOfSolutions = 1)}")

}

