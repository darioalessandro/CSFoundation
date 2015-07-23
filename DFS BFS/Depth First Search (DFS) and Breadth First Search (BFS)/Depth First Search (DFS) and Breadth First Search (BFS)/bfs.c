//
//  bfs.c
//  Depth First Search (DFS) and Breadth First Search (BFS)
//
//  Created by Dario Lencina on 7/22/15.
//  Copyright (c) 2015 dario. All rights reserved.
//

#include "bfs.h"

/*
 1  procedure BFS(G,v) is
 2      let Q be a queue
 3      Q.enqueue(v)
 4      label v as discovered
 5      while Q is not empty
 6         v ← Q.dequeue()
 7         process(v)
 8         for all edges from v to w in G.adjacentEdges(v) do
 9             if w is not labeled as discovered
 10                Q.enqueue(w)
 11                label w as discovered
*/

LinkedList * bfs_explore_iter(Node * root) {
    LinkedList * results = createNode(root);
    Queue * queue = queue_new();
    queue_enqueue(queue, root);
    root -> visited = true;
    while (queue_isEmpty(queue) == false) {
        Node * node = queue_dequeue(queue);
        for(int i = 0 ; i < node -> childrenSize ; i++ ){
            Node * w = node -> children[i];
            if (w -> visited == false) {
                queue_enqueue(queue, w);
                w -> visited = true;
                append(results, w);
            }
        }
    }
    
    return results;
}