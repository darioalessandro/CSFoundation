
//Problem 9.2

case class Coordinates(x:Int, y : Int) {
  def isInsideRect(rect : Coordinates) = {
    this.x >=0 && this.y>=0 && this.x <= rect.x && this.y <= rect.y
  }
  def == (r : Coordinates) =
    this.x == r.x && this.y == r.y
}
def numberOfWaysToGoTo(coords : Coordinates) : Int = {
  def helper(robotPos : Coordinates, path : List[Coordinates]) : Int= {
    if (robotPos.isInsideRect(coords)) {
      if(robotPos == coords) {
        println(s"found solution ${path.reverse}")
        1
      }else {
        helper(Coordinates(robotPos.x + 1, robotPos.y), Coordinates(robotPos.x + 1, robotPos.y) :: path) +
        helper(Coordinates(robotPos.x, robotPos.y + 1), Coordinates(robotPos.x, robotPos.y+1) :: path)
      }
    } else {
      0
    }
  }
  helper(Coordinates(1,1), List(Coordinates(1,1)))
}
numberOfWaysToGoTo(Coordinates(3,3))