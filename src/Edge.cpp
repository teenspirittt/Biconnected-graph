#include "Vertex.h"
#include "Edge.h"
#include <stdexcept>

template<class Vertex, typename V>
Edge<Vertex, V>::Edge(Vertex *vertex1, Vertex *vertex2) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
  }
}

template<class Vertex, typename V>
Edge<Vertex, V>::Edge(Vertex *vertex1, Vertex *vertex2, int weight_) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
    weight = weight_;
  }
}

template<class Vertex, typename V>
Edge<Vertex, V>::Edge(Vertex *vertex1, Vertex *vertex2, int weight_, V value_) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
    weight = weight_;
    value = value_;
  }
}

template<class Vertex, typename V>
Vertex *Edge<Vertex, V>::GetVertexOut() {
  return vertexOut;
}

template<class Vertex, typename V>
Vertex *Edge<Vertex, V>::GetVertexIn() {
  return vertexIn;
}

template<class Vertex, typename V>
void Edge<Vertex, V>::SetValue(V value_) {
  value = value_;
}

template<class Vertex, typename V>
void Edge<Vertex, V>::SetWeight(int weight_) {
  weight = weight_;
}

template<class Vertex, typename V>
int Edge<Vertex, V>::GetWeight() {
  return weight;
}

template<class Vertex, typename V>
V Edge<Vertex, V>::GetValue() {
  return value;
}


