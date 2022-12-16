#pragma once

#include "Vertex.h"

template <class Vertex, typename V>
class Edge {
    public:
        Edge(Vertex *vertex1, Vertex *vertex2);
        Edge(Vertex *vertex1, Vertex *vertex2, int weight_);
        Edge(Vertex *vertex1, Vertex *vertex2, int weight_, V value_);
        Vertex* GetVertexIn();
        Vertex* GetVertexOut();
        int GetWeight();
        void SetWeight(int weight_);
        V GetValue();
        void SetValue(V value_);
    private:
        Vertex *vertexIn;
        Vertex *vertexOut;
        int weight;
        V value;
};





