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

static int VERTEX_COUNT = 0;

template<class Vertex, class Edge>
class Graph {
 public:
  Graph();
  Graph(int vertexCount, bool directed, bool dense);
  Graph(int vertexCount, int edgeCounter, bool directed, bool dense);
  Graph(Graph &copy);
  ~Graph();
  int GetNumOfVertex();
  int GetNumOfEdges();
  bool IsDirected();
  bool IsOriented();
  bool IsList();
  bool IsMatrix();
  int GetDenseCoefficient();
  void ToListGraph();
  void ToMatrixGraph();
  Vertex *insertVertex();
  bool DeleteVertex(Vertex vertex);
  Edge *InsertEdge(Vertex vertex1, Vertex vertex2);
  bool DeleteEdge(Vertex vertex1, Vertex vertex2);
  Edge *GetEdge(Vertex vertex1, Vertex vertex2);
 private:
  bool directed;
  bool dense;          // M - graph
  int edgeCounter;
  vector<Vertex> vertexVector;
  GraphForm<Vertex, Edge> *value;
  void vertexPutIn(int vertexCount, GraphForm<Vertex, Edge> *value);

};





