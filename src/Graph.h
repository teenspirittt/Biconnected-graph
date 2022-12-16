#pragma once

#include "Vertex.h"
#include "Edge.h"

/** 
 * E - edges
 * D - oriented or not
 * F - graph's form (List-graph, Matrix-graph)
 * V - vertexes
*/

template <class Vertex, class Edge>
class Graph {
    public:
        Graph();
        Graph(int V, int D, int F);
        Graph(int V, int E, int D, int F);
        Graph(Graph &copy);
        ~Graph();
        int GetNumOfVertex();
        int GetNumOfEdges();
        bool IsDirected();
        bool IsList();
        int GetDenseCoefficient();
        void ToListGraph();
        void ToMatrixGraph();
        Vertex* insertVertex();
        bool DeleteVertex(Vertex vertex);
        Edge* InsertEdge(Vertex vertex1, Vertex vertex2);
        bool DeleteEdge(Vertex vertex1, Vertex vertex2);
        Edge* GetEdge(Vertex vertex1, Vertex vertex2);
};
