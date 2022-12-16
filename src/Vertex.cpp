#include "Vertex.h"



template<typename I, typename V>
Vertex<I, V>::Vertex() = default;


template<typename I, typename V>
Vertex<I, V>::Vertex(std::string name, V value) {

}

template<typename I, typename V>
Vertex<I, V>::Vertex(const std::string &name) {

}

template<typename I, typename V>
std::string Vertex<I, V>::getName() {
  return std::string();
}

template<typename I, typename V>
V Vertex<I, V>::GetValue(I index_) {
  return nullptr;
}

template<typename I, typename V>
bool Vertex<I, V>::SetName(std::string name_, I index_) {

  return false;
}

template<typename I, typename V>
bool Vertex<I, V>::SetValue(I index_, V value_) {

  return false;
}


