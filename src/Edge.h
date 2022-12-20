#pragma once

#include "Vertex.h"
#include <stdexcept>

template<class Vertex, typename W, typename V>
class Edge {
 public:
  Edge(Vertex *vertex1, Vertex *vertex2) {
    if (vertex1 == nullptr || vertex2 == nullptr) {
      throw std::invalid_argument("One of the vertices is null!");
    } else {
      vertexIn = vertex1;
      vertexOut = vertex2;
    }
    weight = 0;
  }
  Edge(Vertex *vertex1, Vertex *vertex2, int weight) {
    if (vertex1 == nullptr || vertex2 == nullptr) {
      throw std::invalid_argument("One of the vertices is null!");
    } else {
      vertexIn = vertex1;
      vertexOut = vertex2;
      this->weight = weight;
    }
  }

  Edge(Vertex *vertex1, Vertex *vertex2, int weight, V value) {
    if (vertex1 == nullptr || vertex2 == nullptr) {
      throw std::invalid_argument("One of the vertices is null!");
    } else {
      vertexIn = vertex1;
      vertexOut = vertex2;
      this->weight = weight;
      this->value = value;
    }
  }

  Vertex *GetVertexIn() {
    return vertexIn;
  }
  Vertex *GetVertexOut() {
    return vertexOut;
  }
  int GetWeight() {
    return weight;
  }
  void SetWeight(W weight) {
    this->weight = weight;
  }
  V GetValue() {
    return value;
  }
  void SetValue(V value) {
    this->value = value;
  }
 private:
  Vertex *vertexIn;
  Vertex *vertexOut;
  W weight;
  V value;
};





