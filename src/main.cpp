#include <iostream>
#include "Graph.h"

int main() {
  auto *graph = new Graph<Vertex<int>, Edge<Vertex<int>,int,int>>();
  graph->GetVertex(1);

  return 0;
}
