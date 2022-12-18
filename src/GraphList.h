//
// Created by teenspirit on 12/18/22.
//

#ifndef BICONNECTED_GRAPH_SRC_GRAPHLIST_H_
#define BICONNECTED_GRAPH_SRC_GRAPHLIST_H_

#include "GraphMatrix.h"

template<class Vertex, class Edge>
class GraphList : public GraphForm<Vertex, Edge> {
  class Node {
   public:
    Edge *edge;

  };
};

#endif //BICONNECTED_GRAPH_SRC_GRAPHLIST_H_
