#pragma once

#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include "GraphForm.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include <stdexcept>

using namespace std;

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
  vector<Edge *> GetEdges();
  void printGraph();
  bool IsEdgeExist(int v1, int v2);
 private:
  bool directed;
  bool dense;           // M - graph
  int edgeCounter;
  vector<Vertex *> vertexVector;
  vector<Edge *> edgeVector;
  GraphForm<Vertex, Edge> *value;
  void VertexPutIn(int vertexCount, GraphForm<Vertex, Edge> *value);

 public:
  template<typename V>
  class VertexIterator {
   public:
    VertexIterator(Graph<Vertex, Edge> &graph_) {
      this->graph_ = &graph_;
    }

    bool operator++() {
      if (end) {
        current = -1;
        return false;
      }
      current++;
      if (graph_->vertexVector.size() - 1 == current)
        end = true;
      return true;
    };

    Vertex *operator*() {
      return graph_->GetVertex(current);
    }

    bool begin() {
      if (graph_->GetNumOfVertex() == 0) {
        end = true;
        return true;
      }
      current = 0;
      end = false;
      return true;
    }

    bool getEnd() {
      return end;
    }

    int getId() {
      Vertex *v = operator*();
      return v->GetId();
    }

    V getValue() {
      Vertex *v = operator*();
      return v->GetValue();
    }
   private:
    Graph *graph_;
    int current;
    bool end;

  };

 public:
  template<typename V>
  class EdgeIterator {
   public:
    EdgeIterator() {
      graph = nullptr;
      id = -1;
    }

    EdgeIterator(Graph<Vertex, Edge> *graph_, int id) {
      graph = graph_;
      end = false;
      if (graph->GetNumOfEdges() == 0)
        id = -1;
      else
        this->id = id;
    }

    bool operator++() {
      if (end) {
        id = -1;
        return false;
      }
      id++;
      if (graph->GetNumOfEdges() == id)
        end = true;
      if (id >= graph->GetNumOfEdges()) {
        id = -1;
        return false;
      }
      return true;
    }

    Edge *operator*() { return graph->GetEdges()[id]; }

    int getIdV1() {
      Edge *e = operator*();
      return e->GetVertexIn()->GetId();
    }

    int getIdV2() {
      Edge *e = operator*();
      return e->GetVertexOut()->GetId();
    }

    V getValV1() {
      Edge *e = operator*();
      return e->GetVertexIn()->GetValue();
    }

    V getValV2() {
      Edge *e = operator*();
      return e->GetVertexOut()->GetValue();
    }

    bool getEnd() {
      return end;
    }
   private:
    Graph<Vertex, Edge> *graph;
    int id = 0;
    bool end;
  };

  class IncomingEdgeIterator {

  };

};























