#pragma once

#include <string>
#include "Graph.h"

static int VERTEX_COUNT = 0;

template<typename N, typename V>
class Vertex {
 public:
  V value;
  Vertex() {
    id = VERTEX_COUNT++;
  }

  Vertex(N name, V value) {
    this->name = name;
    this->value = value;
  }

  int GetId() {
    return id;
  }
  void SetId(unsigned int id) {
    this->id = id;
  }
  V GetValue() {
    return value;
  }
  N GetName() {
    return name;
  }
  void SetName(N name) {
    this->name = name;
  }
  void SetValue(V value) {
    this->value = value;
  }
 private:
  int id;
  N name;

};








