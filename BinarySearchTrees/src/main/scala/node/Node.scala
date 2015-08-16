package node

/**
 * Created by darioalessandro on 8/14/15.
 */

class Node( val value : Int , var left : Option[Node], var right: Option[Node], val height : Int = 0) {

  def add(values : List[Int]): Unit = {
    values foreach this.add
  }

  def add(value : Int) : Unit = {
    if (value > this.value) {
      right match {
        case Some(r) =>
          r.add(value)
        case None =>
          right = Some(new Node(value, None, None, height + 1))
      }
    } else {
      left match {
        case Some(l) =>
          l.add(value)
        case None =>
          left = Some(new Node(value, None, None, height + 1))
      }
    }
  }

  def containsIter(value : Int) : Boolean = {
    var x : Option[Node] = Some(this)
    while( x.nonEmpty && x.get.value != value ){
      println(s"visiting ${x.get.value}")
      if(x.get.value < value)
        x = x.get.right
      else
        x = x.get.left
    }
    x.nonEmpty && x.get.value == value
  }

  def min : Int = {
    var ptr : Option[Node] = Some(this)
    while(ptr.nonEmpty && ptr.get.left.nonEmpty)
      ptr = ptr.get.left

    ptr.get.value
  }

  def max : Int = {
    var ptr : Option[Node] = Some(this)
    while(ptr.nonEmpty && ptr.get.right.nonEmpty)
      ptr = ptr.get.right

    ptr.get.value
  }

  def containsRec(value : Int) : Boolean = {
    println(s"visiting ${this.value}")
    if(value == this.value)
      true
    else if(value > this.value)
      right.exists(r => r.containsRec(value))
    else
      left.exists(r => r.containsRec(value))
  }

  def printInOrder() : Unit = {
    left foreach {l => l.printInOrder()}
    println(value)
    right foreach {r => r.printInOrder()}
  }

  def printPostOrder() : Unit = {
    left foreach {l => l.printPostOrder()}
    right foreach {r => r.printPostOrder()}
    println(value)
  }

  def printPreOrder() : Unit = {
    println(value)
    left foreach {l => l.printPreOrder()}
    right foreach {r => r.printPreOrder()}
  }
}