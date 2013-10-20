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

        int getY() {
            return y;
        }

        int getWeight() {
            return weight;
        }
};

class Graph {
    private:
        int nvertices;          // Number of vertices in graph
        int nedges;             // Number of edges in graph
        bool directed;          // If the graph is directed or not
        list<Edge> *adjList;    // Array containing adjacency lists
        typedef list<Edge>::iterator adjListItr;

        // Following arrays need initialization every time graph is travsered
        bool *discovered;       // Array to track discovered vertices
        bool *processed;        // Array to track processed vertices
        void initializeTraversal() {
            for (int i = 0; i < this->nvertices; i++) {
                discovered[i] = processed[i] = false;
            }
        }

        void processVertexEarly(int vertex) {
            cout << "Processed vertex: " << vertex << endl;
        }
        void processVertexLate(int vertex) {
        }
        void processEdge(int vertex, int y) {
        }

        void dftRecursive(int vertex) {
            discovered[vertex] = true;
            processVertexEarly(vertex);

            list<Edge> temp = adjList[vertex];
            for (adjListItr it = temp.begin(); it != temp.end(); it++) {
                int y = (*it).getY();
                if (discovered[y] == false) {
                    processEdge(vertex, y);
                    dftRecursive(y);
                } else if (processed[y] == false || directed == true) {
                    processEdge(vertex, y);
                }
            }
            processVertexLate(vertex);
            processed[vertex] = true;
        }

    public:
        explicit Graph(int nvertices, bool directed) {
            this->nvertices = nvertices;
            this->nedges = 0;
            this->directed = directed;
            adjList = new list<Edge>[nvertices];
            discovered = new bool[nvertices];
            processed = new bool[nvertices];
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
            if (start < 0 || start >= nvertices) {
                cout << "Error: vertex out of range." << endl;
            }

            cout << "Breadth First Traversal (start vertex: " << start << ")" << endl;
            initializeTraversal();

            queue<int> myqueue;
            myqueue.push(start);
            discovered[start] = true;

            while(!myqueue.empty()) {
                int vertex = myqueue.front();
                myqueue.pop();
                processVertexEarly(vertex);
                processed[vertex] = true;

                list<Edge> temp = adjList[vertex];
                for (adjListItr it = temp.begin(); it != temp.end(); it++) {
                    int y = (*it).getY();
                    if (processed[y] == false || this->directed) {
                        processEdge(vertex, y);
                    }
                    if (discovered[y] == false) {
                        myqueue.push(y);
                        discovered[y] = true;
                    }
                }
                processVertexLate(vertex);
            }
        }

        void connectedComponents() {
            int c = 0;  // Component Number

            initializeTraversal();
            for (int i = 0; i < this->nvertices; i++) {
                if (discovered[i] == false) {
                    c = c + 1;
                    cout << "Component " << c << ": ";
                    bft(i);
                    cout << endl;
                }
            }
        }

        void dft(int start) {
            if (start < 0 || start >= nvertices) {
                cout << "Error: vertex out of range." << endl;
            }

            cout << "Depth First Traversal (start vertex: " << start << ")" << endl;
            initializeTraversal();
            dftRecursive(start);
        }
};

#endif
