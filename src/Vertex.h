#pragma once

#include <string>



template <typename I, typename V>
class Vertex {
    public:
        std::string  name;
        V value;
        I index;
        Vertex();
        Vertex(std::string name, V value);
        Vertex(const std::string &name);
        std::string getName();
        V GetValue(I index_);
        bool SetName(std::string name_, I index_);
        bool SetValue(I index_, V value_);
};







