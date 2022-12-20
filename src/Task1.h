//
// Created by teenspirit on 12/20/22.
//

#ifndef BICONNECTED_GRAPH_SRC_TASK1_H_
#define BICONNECTED_GRAPH_SRC_TASK1_H_

#include <list>
#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"

using namespace std;

template<class Vertex, class Edge>
class Task1 {
 public:
  Task1(Graph<Vertex, Edge> *graph_) {
    graph = graph_;
  }

  Graph<Vertex, Edge> *toBiconnectedGraph() {
    int numOfVertices = graph->GetNumOfVertex();
    vector<Vertex *> vertices = graph->GetVector();
    Vertex *vertex1, *vertex2;

    for (int i = 0; i < numOfVertices; ++i) {
      int v1 = i;
      int v2 = (i + 1) % numOfVertices;
      Edge *e;
      if ((e = graph->InsertEdge(graph->GetVertex(v1), graph->GetVertex(v2))) != nullptr) {
        e->SetWeight(10);
        e->SetValue(1);
      }
    }
    return graph;
  }
 private:
  Graph<Vertex, Edge> *graph;
};

#endif //BICONNECTED_GRAPH_SRC_TASK1_H_
