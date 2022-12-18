#include "Vertex.h"
#include "Edge.h"
#include <stdexcept>

template<class Vertex, typename W, typename V>
Edge<Vertex, W, V>::Edge(Vertex *vertex1, Vertex *vertex2) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
  }
  weight = 0;
}

template<class Vertex, typename W, typename V>
Edge<Vertex, W, V>::Edge(Vertex *vertex1, Vertex *vertex2, int weight) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
    this->weight = weight;
  }
}

template<class Vertex, typename W, typename V>
Edge<Vertex, W, V>::Edge(Vertex *vertex1, Vertex *vertex2, int weight, V value) {
  if (vertex1 == nullptr || vertex2 == nullptr) {
    throw std::invalid_argument("One of the vertices is null!");
  } else {
    vertexIn = vertex1;
    vertexOut = vertex2;
    this->weight = weight;
    this->value = value;
  }
}

template<class Vertex, typename W, typename V>
Vertex *Edge<Vertex, W, V>::GetVertexOut() {
  return vertexOut;
}

template<class Vertex, typename W, typename V>
Vertex *Edge<Vertex, W, V>::GetVertexIn() {
  return vertexIn;
}

template<class Vertex, typename W, typename V>
void Edge<Vertex, W, V>::SetValue(V value) {
  this->value = value;
}

template<class Vertex, typename W, typename V>
void Edge<Vertex, W, V>::SetWeight(int weight) {
  this->weight = weight;
}

template<class Vertex, typename W, typename V>
int Edge<Vertex, W, V>::GetWeight() {
  return weight;
}

template<class Vertex, typename W, typename V>
V Edge<Vertex, W, V>::GetValue() {
  return value;
}


