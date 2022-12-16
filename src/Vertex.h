#pragma once

#include <string>


template <typename I, typename V>
class Vertex {
    public:
        string name;
        V value;
        I index;
        Vertex();
        Vertex(string name, V value);
        string getName();
        V GetValue(I index);
        bool SetName(string name, I index);
        bool SetValue(I index, V value);    
};