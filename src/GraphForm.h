//
// Created by teenspirit on 12/18/22.
//

#ifndef BICONNECTED_GRAPH_SRC_GRAPHFORM_H_
#define BICONNECTED_GRAPH_SRC_GRAPHFORM_H_

#include "Vertex.h"

template<class Vertex, class Edge>
class GraphForm {
 public:
  virtual bool InsertVertex(int index) = 0;
  virtual bool DeleteVertex(int index) = 0;
  virtual bool InsertEdge(int v1, int v2, Edge *e) = 0;
  virtual bool DeleteEdge(int v1, int v2) = 0;
};

#endif //BICONNECTED_GRAPH_SRC_GRAPHFORM_H_
