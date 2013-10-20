#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<list>
#include<queue>

using namespace std;

class Edge {
    private:
        int y;
        int weight;
    public:
        explicit Edge(int y) {
            this->y = y;
            this->weight = 0;
        }

        explicit Edge(int y, int weight) {
            this->y = y;
            this->weight = weight;
        }

        ~Edge() {
        }

        void print() {
            cout << " (" << y << ", " << weight << ") ";
        }

        int get_y() {
            return y;
        }

        int get_weight() {
            return weight;
        }
};

class Graph {
    private:
        int nvertices;  // Number of vertices in graph
        int nedges;     // Number of edges in graph
        bool directed;  // If the graph is directed or not
        list<Edge> *adjList; // Pointer to an array containing adjacency lists
        typedef list<Edge>::iterator adjListItr;

        void process_vertex_early(int vertex) {
            cout << "Processed vertex: " << vertex << endl;
        }
        void process_vertex_late(int vertex) {
        }
        void process_edge(int vertex, int y) {
        }

    public:
        explicit Graph(int nvertices, bool directed) {
            this->nvertices = nvertices;
            this->nedges = 0;
            this->directed = directed;
            adjList = new list<Edge>[nvertices];
        }

        ~Graph() {
            // FIXME Delete the adjacency List array
        }

        void addEdge(int v, int y, int weight) {
            adjList[v].push_back(Edge(y, weight));
            this->nedges++;

            if (this->directed == false) {
                adjList[y].push_back(Edge(v, weight));
                this->nedges++;
            }
        }

        void print() {
            cout << "Graph Details: \n";
            cout << "\t Directed: " << directed << ", Total Edges: " << nedges << "\n";
            cout << "Graph Contents: \n";
            for (int i = 0; i < this->nvertices; i++) {
                cout << "\tVertex: " << i << " Edges: ";
                list<Edge> temp = adjList[i];
                for (adjListItr it = temp.begin(); it != temp.end(); it++) {
                    (*it).print();
                }
                cout << "\n";
            }
        }

        void bft(int start) {
            bool discovered[nvertices];
            bool processed[nvertices];

            // Validate start vertex
            if (start < 0 || start >= nvertices) {
                cout << "Error: vertex out of range." << endl;
            }

            cout << "Breadth First Traversal (start vertex: " << start << ")" << endl;
            // Initialize
            for (int i = 0; i < this->nvertices; i++) {
                discovered[i] = processed[i] = false;
            }

            queue<int> myqueue;
            myqueue.push(start);
            discovered[start] = true;

            while(!myqueue.empty()) {
                int vertex = myqueue.front();
                myqueue.pop();
                process_vertex_early(vertex);
                processed[vertex] = true;

                list<Edge> temp = adjList[vertex];
                for (adjListItr it = temp.begin(); it != temp.end(); it++) {
                    int y = (*it).get_y();
                    if (processed[y] == false || this->directed) {
                        process_edge(vertex, y);
                    }
                    if (discovered[y] == false) {
                        myqueue.push(y);
                        discovered[y] = true;
                    }
                }
                process_vertex_late(vertex);
            }
        }

};

#endif
