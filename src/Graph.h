#pragma once

#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include "GraphForm.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include <stdexcept>

using namespace std;

/** 
 * E - edges
 * D - oriented or not
 * F - graph's form (List-graph, Matrix-graph)
 * V - vertexes
*/



template<class Vertex, class Edge>
class Graph {
 public:
  Graph();
  Graph(int vertexCount, bool directed, bool dense);
  Graph(int vertexCount, int edgeCounter, bool directed, bool dense);
  Graph(Graph<Vertex, Edge> &copy);
  ~Graph();
  int GetNumOfVertex();
  int GetNumOfEdges();
  bool IsDirected();
  bool IsMatrix();
  double GetDenseCoefficient();
  void ToListGraph();
  void ToMatrixGraph();
  Vertex *InsertVertex();
  bool DeleteVertex(Vertex *vertex);
  void DeleteVertex(int index);
  int GetIndex(Vertex *vertex);
  Vertex *GetVertex(unsigned int id);
  Vertex *GetVertexByIndex(unsigned int index);
  Edge *InsertEdge(Vertex *vertex1, Vertex *vertex2);
  bool DeleteEdge(Vertex *vertex1, Vertex *vertex2);
  Edge *GetEdge(Vertex *vertex1, Vertex *vertex2);
  void printGraph();
  bool IsEdgeExist(int v1, int v2);
 private:
  bool directed;
  bool dense;          // M - graph
  int edgeCounter;
  vector<Vertex *> vertexVector;
  GraphForm<Vertex, Edge> *value;
  void VertexPutIn(int vertexCount, GraphForm<Vertex, Edge> *value);
};




















