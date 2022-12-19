#pragma once

#include <string>
#include "Graph.h"

static int VERTEX_COUNT = 0;

template<typename V>
class Vertex {
 public:
  V value;
  Vertex() {
    id = VERTEX_COUNT++;
  }

  Vertex(int id_, V value_) {
    if (id_ >= VERTEX_COUNT) {
      throw std::invalid_argument("Invalid id!");
    } else {
      id = id_;
      value = value_;
    }
  }

  int GetId() {
    return id;
  }
  V GetValue() {
    return value;
  }
  void SetId(int id_) {
    id = id_;
  }
  void SetValue(V value_) {
    value = value_;
  }
 private:
  int id;

};








