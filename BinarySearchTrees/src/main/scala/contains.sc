import node.Node

val root = new Node(15, None, None)

root.add(List(6, 18, 3, 7, 17, 20, 2, 4, 13, 9))

root.containsRec(13)
root.containsIter(13)
root.max
root.min