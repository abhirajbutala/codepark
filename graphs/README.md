GRAPHS
======


Breadth First Traversal
=======================
Takes O(n + m) linear runtime if implemented using adjacency lists,
where n is the number of vertices and m is the number of edges.


BFT Applications
================

* Finding Shortest Paths: We can maintain the array of parent vertices which
led to the discovery of those vertices when performing bft. With the help of
this array, we can find paths from vertex x to vertex y. Works only if the
bft was done starting from vertex x. Also, works only if the graph is
unweighted.

TODO: Update bft() to maintain parent array for all vertices.

* Finding Connected Components: A connected component of an undirected graph
is a maximal set of vertices such that there is a path between every pair of
vertices. The components are separate “pieces” of the graph such that there
is no connection between the pieces. Such components can be found using bft.
Please check connectedComponents() method for sample implementation.

An amazing number of seemingly complicated problems reduce to finding or
counting connected components. For example, testing whether a puzzle such as
Rubik’s cube or the 15-puzzle can be solved from any position is really asking
whether the graph of legal configurations is connected.

* Two Coloring Graphs: Determining if the graph is bipartite and/or two coloring
them can be done using bft. processEdge() method can be customized to validate
that the no two adjacent vertices of the edge are of the same color/type.



Depth First Traversal
=====================

DFT Applications
================

* DFT can partition the edges of an undirected graph into exactly two classes:
tree edges and back edges. The tree edges discover new vertices, and are those
encoded in the parent relation. Back edges are those whose other endpoint is
an ancestor of the vertex being expanded, so they point back into the tree.

* DFT can organize the vertices by their entry/exit times. If we maintain such
times, we can determine ancestor relations between vertices and also determine
descendents of a given vertex.

TODO: Update dft method to maintain entry/exit times.

* Finding Cycles: If we find a back edge in the graph, then it means there is
a cycle in a graph. Can be done easily in processEdge() method during dft.

* Finding Articulation Vertices: Articulation vertices or cut nodes are single
point of failure nodes; If we remove the edge between them, the graph can be
disconnected into two sub graphs.


DFT on Directed Graphs
======================

* Topological Sorting of DAGs: Topological sorting of vertices on directed
acyclic graphs is an ordering of vertices in a line such that all edges go
from left to right. It can be easily found using DFT. This can be done in
processVertexLate() method by maintaining a stack of vertices, such that the
top vertex will not have any incoming edges from the other vertices in the
stack. Also, processEdge() can be used to determine if back edge is found and
fail in that case.

TODO: Implement topological sorting on DAG.

* Strongly Connected Components: We can partition the graph into chunks of
vertices such that directed paths exist between all pairs of vertices within
a given chunk. Such a chunk is called strongly connected component. Can be done
using DFT.

TODO: Implement method for finding strongly connected components in a DAG.
