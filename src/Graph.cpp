#include "Graph.h"

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph() {
  value = new GraphList<Vertex, Edge>(false);
  directed = false;
  dense = false;
  edgeCounter = 0;
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int vertexCount, bool directed, bool dense) {
  if (dense)
    value = new GraphMatrix<Vertex, Edge>(directed);
  else
    value = new GraphMatrix<Vertex, Edge>(directed);
  vertexPutIn(vertexCount, value);
  this->dense = dense;
  this->directed = directed;
  edgeCounter = 0;

}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(int vertexCount, int edgeCount, bool directed, bool dense) {
  if (dense)
    value = new GraphMatrix<Vertex, Edge>(directed);
  else
    value = new GraphMatrix<Vertex, Edge>(directed);
  vertexPutIn(vertexCount, value);
  this->dense = dense;
  this->directed = directed;

  if (edgeCount <= 0) throw invalid_argument("Negative argument");
  if (directed) {
    if (edgeCount > vertexCount * (vertexCount - 1))
      edgeCount = vertexCount * (vertexCount - 1);
  } else {
    if (edgeCount > (vertexCount * (vertexCount - 1)) / 2)
      edgeCount = (vertexCount * (vertexCount - 1) / 2);
  }
  int v1, v2;
  while (edgeCounter < edgeCount) {
    v1 = rand() % vertexCount;
    v2 = rand() % vertexCount;
    if (v1 == v2)
      continue;
    if (value->isEdgeExist(v1, v2))
      continue;
    Edge *e = new Edge(vertexVector[v1], vertexVector[v2], (rand() % 19) + 1);
    value->InsertEdge(v1, v2, e);
    if (!directed)
      value->InsertEdge(v2, v1, e);
    edgeCounter++;
  }
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(Graph &copy) {
  if (copy.IsMatrix())
    value = new GraphMatrix<Vertex, Edge>(*(copy.value));
  else
    value = new GraphList<Vertex, Edge>(*(copy.value));
  directed = copy.directed;
  dense = copy.dense;
  delete value;
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::~Graph() {
  while (vertexVector.size() != 0)
    DeleteVertex(vertexVector.size() - 1);
  delete value;
}

template<class Vertex, class Edge>
void Graph<Vertex, Edge>::vertexPutIn(int vertexCount, GraphForm<Vertex, Edge> *value) {
  for (int i = 0; i < vertexCount; ++i) {
    value->InsertVertex(i);
    for (int j = 0; j < vertexCount; ++j) {
      auto *v = new Vertex();
      vertexVector.push_back(v);
      value->InsertVertex(i);
    }
  }
}





