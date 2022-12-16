#include "Vertex.h"
#include "Graph.h"
#include <stdexcept>

template<typename I, typename V>
Vertex<I, V>::Vertex() {
  id = VERTEX_COUNT++;
}

template<typename I, typename V>
Vertex<I, V>::Vertex(int id_, V value_) {
  if (id_ >= VERTEX_COUNT) {
    throw std::invalid_argument("Invalid id!");
  } else {
    id = id_;
    value = value_;
  }
}

template<typename I, typename V>
int Vertex<I, V>::getId() {
  return id;
}

template<typename I, typename V>
V Vertex<I, V>::GetValue() {
  return value;
}

template<typename I, typename V>
void Vertex<I, V>::SetId(int id_) {
  id = id_;
}

template<typename I, typename V>
void Vertex<I, V>::SetValue(V value_) {
  value = value_;
}




