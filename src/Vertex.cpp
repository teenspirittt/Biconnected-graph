#include "Vertex.h"
#include "Graph.h"
#include <stdexcept>

template<typename V>
Vertex<V>::Vertex() {
  id = VERTEX_COUNT++;
}

template<typename V>
Vertex<V>::Vertex(int id_, V value_) {
  if (id_ >= VERTEX_COUNT) {
    throw std::invalid_argument("Invalid id!");
  } else {
    id = id_;
    value = value_;
  }
}

template<typename V>
int Vertex<V>::getId() {
  return id;
}

template<typename V>
V Vertex<V>::GetValue() {
  return value;
}

template<typename V>
void Vertex<V>::SetId(int id_) {
  id = id_;
}

template<typename V>
void Vertex<V>::SetValue(V value_) {
  value = value_;
}




