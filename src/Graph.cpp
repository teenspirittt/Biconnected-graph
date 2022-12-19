#include <iostream>
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
  VertexPutIn(vertexCount, value);
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
  VertexPutIn(vertexCount, value);
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
    if (v1 == v2) {
      continue;
    }
    if (value->IsEdgeExist(v1, v2)) {
      continue;
    }
    Edge *e = new Edge(vertexVector[v1], vertexVector[v2], (rand() % 19) + 1);
    value->InsertEdge(v1, v2, e);
    if (!directed) {
      value->InsertEdge(v2, v1, e);
    }
    edgeCounter++;
  }
}

template<class Vertex, class Edge>
Graph<Vertex, Edge>::Graph(Graph<Vertex, Edge> &copy) {
  if (copy.IsMatrix())
    value = new GraphMatrix<Vertex, Edge>(copy.value);
  else
    value = new GraphList<Vertex, Edge>(copy.value);
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
void Graph<Vertex, Edge>::VertexPutIn(int vertexCount, GraphForm<Vertex, Edge> *value) {
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
      if (value->IsEdgeExist(i, j))
        newValue->InsertEdge(i, j, value->GetEdge(i, j));

  delete value;
  value = newValue;
  dense = false;
}

template<class Vertex, class Edge>
void Graph<Vertex, Edge>::ToMatrixGraph() {
  GraphForm<Vertex, Edge> *newValue = new GraphMatrix<Vertex, Edge>(this->directed);

  for (int i = 0; i < vertexVector.size(); ++i)
    newValue->InsertVertex(i);

  for (int i = 0; i < vertexVector.size(); ++i)
    for (int j = 0; j < vertexVector.size(); ++j)
      if (value->IsEdgeExist(i, j))
        newValue->InsertEdge(i, j, value->GetEdge(i, j));

  delete value;
  value = newValue;
  dense = true;
}

template<class Vertex, class Edge>
Vertex *Graph<Vertex, Edge>::InsertVertex() {
  auto *vertex = new Vertex;
  if ((value->InsertVertex(vertexVector.size()) == false))
    return nullptr;
  vertexVector.push_back(vertex);
  return vertex;
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteVertex(Vertex *vertex) {
  int index = GetIndex(vertex);
  edgeCounter -= value->DeleteOutEdges(index, directed);
  if (value->DeleteVertex(index)) {
    vertexVector.erase(vertexVector.begin() + index);
    return true;
  }
  return false;
}

template<class Vertex, class Edge>
void Graph<Vertex, Edge>::DeleteVertex(int index) {
  edgeCounter -= value->DeleteOutEdges(index, directed);
  if (value->DeleteVertex(index))
    vertexVector.erase(vertexVector.begin() + index);
}

template<class Vertex, class Edge>
int Graph<Vertex, Edge>::GetIndex(Vertex *vertex) {
  int index = 0;
  for (int i = 0; i < vertexVector.size(); ++i) {
    if (vertexVector[index] == vertex)
      break;
    ++index;
  }
  if (index == vertexVector.size())
    throw invalid_argument("Invalid argument!");
  return index;
}

template<class Vertex, class Edge>
Edge *Graph<Vertex, Edge>::InsertEdge(Vertex *vertex1, Vertex *vertex2) {
  Edge *e = new Edge(vertex1, vertex2);
  if (!value->InsertEdge(GetIndex(vertex1), GetIndex(vertex2), e))
    throw invalid_argument("Invalid argument!");
  if (!directed)
    value->InsertEdge(GetIndex(vertex2), GetIndex(vertex1), e);
  ++edgeCounter;
  return e;
}

template<class Vertex, class Edge>
Vertex *Graph<Vertex, Edge>::GetVertexByIndex(unsigned int index) {
  if (index < 0 || index >= vertexVector.size())
    throw invalid_argument("Invalid argument!");
  return vertexVector[index];
}

template<class Vertex, class Edge>
Vertex *Graph<Vertex, Edge>::GetVertex(unsigned int id) {
  int i;
  for (i = 0; i < vertexVector.size(); ++i) {
    if (vertexVector[i]->GetId() == id)
      return vertexVector[i];
    if (i == vertexVector.size())
      throw invalid_argument("Invalid argument!");
  }
  return nullptr;
}

template<class Vertex, class Edge>
bool Graph<Vertex, Edge>::DeleteEdge(Vertex *vertex1, Vertex *vertex2) {
  if (value->DeleteEdge(GetIndex(vertex1), GetIndex(vertex2))) {
    --edgeCounter;
    if (!directed)
      value->DeleteEdge(GetIndex(vertex2), GetIndex(vertex1));
    return true;
  } else
    return false;
}

template<class Vertex, class Edge>
Edge *Graph<Vertex, Edge>::GetEdge(Vertex *vertex1, Vertex *vertex2) {
  Edge *e;
  e = value->GetEdge(GetIndex(vertex1), GetIndex(vertex2));
  return e;
}

template
class Graph<Vertex<int>, Edge<Vertex<int>, int, int>>;




