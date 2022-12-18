#pragma once

#include <string>



template<typename V>
class Vertex {
 public:
  V value;
  Vertex();
  Vertex(int id_, V value_);
  int getId();
  V GetValue();
  void SetId(int id_);
  void SetValue(V value_);
 private:
  int id;

};








