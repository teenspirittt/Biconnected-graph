#pragma once

#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include "GraphForm.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include <stdexcept>

// todo fix iterators(seg)

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
  vector<Vertex *> GetVector();
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
      if (graph_->vertexVector.size() == current)
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
      current = -1;
    }

    EdgeIterator(Graph<Vertex, Edge> *graph_, int current) {
      graph = graph_;
      end = false;
      if (graph->GetNumOfEdges() == 0)
        current = -1;
      else
        this->current = current;
    }

    bool operator++() {
      if (end) {
        current = -1;
        return false;
      }
      current++;
      if (graph->edgeVector.size() == current)
        end = true;
      if (current >= graph->GetNumOfEdges()) {
        current = -1;
        return false;
      }
      return true;
    }

    bool getEnd() {
      return end;
    }

    Edge *operator*() { return graph->GetEdges()[current]; }

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

   private:
    Graph<Vertex, Edge> *graph;
    int current = 0;
    bool end;
  };

 public:
  template<typename V>
  class OutgoingEdgeIterator {
   public:

    OutgoingEdgeIterator(Graph *graph, Vertex *vertex, int curr) {
      this->graph = graph;
      this->vertex = vertex;
      if (curr == -1) {
        current = -1;
        return;
      }
      end = false;

      for (int i = 0; i < graph->edgeVector.size(); ++i)
        if (graph->GetEdges()[current]->GetVertexIn() == vertex ||
            (!graph->IsDirected() && graph->GetEdges()[current]->GetVertexOut() == vertex))
          return;
      current = -1;
    }

    OutgoingEdgeIterator(Vertex *vertex) {
      graph = nullptr;
      this->vertex = vertex;
      current = -1;
      end = false;
    }

    bool getEnd() {
      return end;
    }

    bool operator++() {
      if (current == -1) {
        return false;
      }
      current++;
      for (; current < graph->edgeVector.size(); ++current) {
        if (graph->GetEdges()[current]->GetVertexIn() == vertex ||
            (!graph->IsDirected() && graph->GetEdges()[current]->GetVertexOut() == vertex)) {
          return false;
        }

      }
      current = -1;
      return true;
    }

    Edge *operator*() { return graph->GetEdges()[current]; }

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

   private:
    Graph<Vertex, Edge> *graph;
    Vertex *vertex;
    bool end;
    int current = 0;
  };

};
























