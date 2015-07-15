

class MergeSort {

  def sort(a : Array[Int]) : Array[Int] = {
    if(a.length > 1) {
      val chunks = a.splitAt(a.length / 2)
      mergeChunks((sort(chunks._1), sort(chunks._2)))
    }else{
      a
    }
  }

  private def mergeChunks(chunks : (Array[Int], Array[Int])) : Array[Int] = {
    val sortedListSize = chunks._1.length + chunks._2.length
    var sortedArray = Array[Int]()
    var aPtr = 0
    var bPtr = 0

    for(i <- 1 to sortedListSize) {
      if(aPtr >= chunks._1.length) {
        sortedArray = chunks._2(bPtr) +: sortedArray
        bPtr = bPtr + 1
      }else if(bPtr >= chunks._2.length){
        sortedArray = chunks._1(aPtr) +: sortedArray
        aPtr = aPtr + 1
      }else if(chunks._1(aPtr) < chunks._2(bPtr)){
        sortedArray =   chunks._1(aPtr) +: sortedArray
        aPtr = aPtr + 1
      }else {
        sortedArray = chunks._2(bPtr) +: sortedArray
        bPtr = bPtr + 1
      }
    }
    sortedArray.reverse
  }

}
