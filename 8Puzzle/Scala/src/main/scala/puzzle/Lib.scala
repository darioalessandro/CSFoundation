package puzzle

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.util.Random

object PuzzleState {

  def random : PuzzleState = {
    val matrix: mutable.MutableList[mutable.MutableList[Int]] =
      mutable.MutableList[mutable.MutableList[Int]](mutable.MutableList(1,2,3),mutable.MutableList(1,2,3),mutable.MutableList(1,2,3))
    val remaining: ArrayBuffer[Int] = ArrayBuffer(1, 2, 3, 4, 5, 6, 7, 8, 0)
    val randy = new Random()
    var i = 0
    var j = 0
    for (ii <- 0 to 2; jj <- 0 to 2) yield {
      val indexToDelete = randy.nextInt(remaining.length)
      val value = remaining(indexToDelete)
      matrix(ii)(jj) = value
      if(value == 0){
        i = ii
        j = jj
      }
      remaining.remove(indexToDelete)
    }

    PuzzleState(matrix, i , j)
  }

  def solution = {
    var matrix = mutable.MutableList[mutable.MutableList[Int]]()

    matrix = matrix+= mutable.MutableList(1,2,3)
    matrix = matrix+= mutable.MutableList(4,5,6)
    matrix = matrix+= mutable.MutableList(7,8,0)

    PuzzleState(matrix, 2 , 2)
  }

  def hard = {
    var matrix = mutable.MutableList[mutable.MutableList[Int]]()

    matrix = matrix+= mutable.MutableList(7,0,8)
    matrix = matrix+= mutable.MutableList(1,2,3)
    matrix = matrix+= mutable.MutableList(4,5,6)

    PuzzleState(matrix, 0, 1)
  }

  def medium = {
    var matrix = mutable.MutableList[mutable.MutableList[Int]]()

    matrix = matrix+= mutable.MutableList(1,2,3)
    matrix = matrix+= mutable.MutableList(7,0,8)
    matrix = matrix+= mutable.MutableList(4,5,6)

    PuzzleState(matrix, 1 , 1)
  }

  def easy = {
    var matrix = mutable.MutableList[mutable.MutableList[Int]]()

    matrix = matrix+= mutable.MutableList(1,2,3)
    matrix = matrix+= mutable.MutableList(4,5,6)
    matrix = matrix+= mutable.MutableList(7,0,8)

    PuzzleState(matrix, 2 , 1)
  }

}

case class PuzzleState(matrix : mutable.MutableList[mutable.MutableList[Int]], i : Int, j : Int) {

  val solution : Double = 0.3691275168

  def closenessToSolution = {
    val num : Double = matrix(0)(0) + matrix(0)(1) * 2 + matrix(0)(2) * 3 + matrix(1)(0) * 4 + matrix(1)(2) * 5
    val den : Double = matrix(1)(2) * 6 + matrix(2)(0) * 7 + matrix(2)(1) * 8 + matrix(2)(2) * 0

    Math.abs(1 - (num/den) / solution)
  }
}


object Node {
  def random : Node = Node(PuzzleState.random)

  def solution : Node = Node(PuzzleState.solution)
}

case class Node(state : PuzzleState, var visited : Boolean = false, depth : Int = 0, parent : Option[Node] = None, children : Option[List[Node]] = None) {

  def isDifferent(node : Node) : Boolean = {

    parent match {
      case None =>
        true

      case Some(p) =>
        var isDifferent = false
        for(i <- 0 to 2; j <- 0 to 2) {
          if(node.state.matrix(i)(j) != p.state.matrix(i)(j))
            isDifferent = true
        }
        if(isDifferent)
          p.isDifferent(node)
        else
          isDifferent
    }

  }

  def setParent(parent_ : Option[Node]) =
    Node(state,visited,depth,parent_, children)

  def setChildren(children_ : Option[List[Node]]) =
    Node(state,visited,depth,parent, children_)


  def generateChildShifting(i : Int, j : Int) : Node = {
    val s = this.state
    val oldValue = s.matrix(i)(j)

    var newMatrix : mutable.MutableList[mutable.MutableList[Int]] = new mutable.MutableList[mutable.MutableList[Int]]()

    for(ii <- 0 to 2) yield {
      val newRow = mutable.MutableList[Int]()
      for(jj <- 0 to 2) yield {
         newRow += s.matrix(ii)(jj)
      }
      newMatrix = newMatrix ++ mutable.MutableList(newRow)
    }


    newMatrix(s.i)(s.j) = oldValue
    newMatrix(i)(j) = 0

    Node(PuzzleState(newMatrix, i, j), visited = false, depth + 1)
  }

  def generateChildren : List[Node] = {
    val s : PuzzleState = this.state

    var children = List[Node]()

    if(s.i > 0)
      children = generateChildShifting(s.i-1,s.j) +: children

    if(s.i < 2)
      children = generateChildShifting(s.i+1,s.j) +: children

    if(s.j < 2)
      children = generateChildShifting(s.i,s.j+1) +: children

    if(s.j > 0)
      children = generateChildShifting(s.i,s.j-1) +: children

    children
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
