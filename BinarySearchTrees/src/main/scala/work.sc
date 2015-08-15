import node.Node

val root = new Node(2, None, None)

root.add(6)

root.add(7)

root.add(8)

root.add(5)

root.printInOrder()
root.printPreOrder()
root.printPostOrder()