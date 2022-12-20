//
// Created by teenspirit on 12/20/22.
//

#ifndef BICONNECTED_GRAPH_SRC_TASK2_H_
#define BICONNECTED_GRAPH_SRC_TASK2_H_

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include "Graph.h"

using namespace std;

template<class Vertex, class Edge>
class Task3 {
 public:
  ~Task3() = default;

  explicit Task3(Graph<Vertex, Edge> *g) {
    Set(g);
  }

  explicit Task3(const Graph<Vertex, Edge> &graph_) {
    if (!graph_.IsMatrix())
      this->value = new GraphMatrix<Vertex, Edge>(graph_.value);
    else
      this->value = new GraphList<Vertex, Edge>(graph_.value);
    this->directed = graph_.directed;
    this->dense = graph_.dense;
  }

  void Set(Graph<Vertex, Edge> *g) {
    if (g->IsDirected()) cout << " FAIL: need non directed " << endl;
    this->graph = g;
  }

  void result(int vertex) {
    int weightOstTree = 0;
    int size = graph->GetNumOfVertex();
    auto *keys = new long long[size];
    int *AncestorsEdge = new int[size];
    int *q = new int[size];
    for (unsigned i = 0; i < size; ++i) {
      keys[i] = 1000000000000000000;
      AncestorsEdge[i] = -1;
      q[i] = 1;
    }
    keys[vertex] = 0;
    int n = size;
    while (n != 0) {
      int minVertex = -1;
      for (unsigned i = 0; i < size; ++i) {
        if (q[i] == 1 && (minVertex == -1 || keys[i] < keys[minVertex])) {
          minVertex = i;
        }
      }
      for (unsigned i = 0; i < size; ++i) {
        if (graph->IsEdgeExist(minVertex, i)) {

          if (i != minVertex && q[i] == 1
              && keys[i] > graph->GetEdge(graph->GetVertex(minVertex), graph->GetVertex(i))->GetWeight()) {
            AncestorsEdge[i] = minVertex;
            keys[i] = graph->GetEdge(graph->GetVertex(minVertex), graph->GetVertex(i))->GetWeight();
            weightOstTree += graph->GetEdge(graph->GetVertex(minVertex), graph->GetVertex(i))->GetWeight();
          }
        }

      }
      --n;
      q[minVertex] = 0;
    }
    for (int i = 0; i < size; i++) {
      if (AncestorsEdge[i] != -1) {
        cout << "Vertex from: " << i << " Vertex to: " << AncestorsEdge[i] << endl;
      }
    }
  }

 private:
  Graph<Vertex, Edge> *graph;
};

#endif //BICONNECTED_GRAPH_SRC_TASK2_H_
