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

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::GetNumOfEdges() {
  return vertexVector.size();
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::GetNumOfVertex() {
  return edgeCounter;
}

template<class Vertex, class Edge>
double Graph<Vertex, Edge>::GetDenseCoefficient() {
  double max = vertexVector.size() * (vertexVector.size() - 1);
  if (!IsDirected()) {
    max /= 2;
  }
  if (max == 0) {
    return -1;
  } else {
    return edgeCounter / max;
  }
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::IsMatrix() {
  return dense;
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::IsDirected() {
  return directed;
}

template<class Vertex, class Edge>
void Graph<Vertex, Edge>::ToListGraph() {
  GraphForm<Vertex, Edge> *newValue = new GraphList<Vertex, Edge>(this->directed);
  // Create vertices
  for (int i = 0; i < vertexVector.size(); ++i)
    newValue->InsertVertex(i);

  // Transfer edges
  for (int i = 0; i < vertexVector.size(); ++i)
    for (int j = 0; j < vertexVector.size(); ++j)
      if (value->isEdgeExist(i, j))
        newValue->InsertEdge(i, j, value->getEdge(i, j));

  delete value;
  value = newValue;
  dense = false;
}




