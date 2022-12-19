//
// Created by teenspirit on 12/18/22.
//

#ifndef BICONNECTED_GRAPH_SRC_GRAPHLIST_H_
#define BICONNECTED_GRAPH_SRC_GRAPHLIST_H_

#include <list>
#include "GraphMatrix.h"

template<class Vertex, class Edge>
class GraphList : public GraphForm<Vertex, Edge> {
  class Node {
   public:
    Edge *edge;
    int v2;
  };
  bool directed;
  vector<list < Node>> edgeList;
 public:
  explicit GraphList(bool directed) : directed(directed) {};
  bool InsertVertex(int index) {
    int size = edgeList.size();
    if (index < 0 || index > size)
      return false;

    list<Node> newList;

    edgeList.insert(edgeList.begin() + index, newList);
    ++size;

    for (int i = 0; i < size; ++i)
      for (typename list<Node>::iterator j = edgeList[i].begin(); j != edgeList[i].end(); ++j)
        if ((*j).v2 >= index)
          ++((*j).v2);
    return true;
  }
  bool DeleteVertex(int index) {
    int size = edgeList.size();
    if (index < 0 || index >= size)
      return false;

    for (int i = 0; i < size; ++i)
      for (typename list<Node>::iterator j = edgeList[i].begin(); j != edgeList[i].end(); ++j)
        if ((*j).v2 == index) {
          edgeList[i].erase(j);
          break;
        }

    edgeList.erase(edgeList.begin() + index);
    --size;

    for (int i = 0; i < size; ++i)
      for (typename list<Node>::iterator j = edgeList[i].begin(); j != edgeList[i].end(); ++j)
        if ((*j).v2 > index)
          --((*j).v2);
    return true;
  }

  bool InsertEdge(int v1, int v2, Edge *e) {
    int size = edgeList.size(); //Число вершин
    if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)//Неверный номер вершины
      return false;
    if (v1 == v2 || IsEdgeExist(v1, v2))  //Петля или ребро уже есть
      return false;
    //Вставляем ребро
    Node node;
    node.edge = e;
    node.v2 = v2;
    edgeList[v1].push_front(node);
    return true;
  }

  bool DeleteEdge(int v1, int v2) {
    int size = edgeList.size(); //Число вершин
    //Неверный номер вершины
    if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
      return false;
    //Ребра нет
    if (v1 == v2 || IsEdgeExist(v1, v2) == false)
      return false;
    //Удаляем ребро
    for (typename list<Node>::iterator j = edgeList[v1].begin(); j != edgeList[v1].end(); ++j)
      if ((*j).v2 == v2) {
        edgeList[v1].erase(j);
        break;
      }
    return true;
  }

  int DeleteOutEdges(int index, bool directed) {
    int size = edgeList.size(); //Число вершин
    int deleted = 0;
    //Неверный номер вершины
    if (index < 0 || index >= size)
      return 0;
    //Удаляем связанные с вершиной рёбра
    for (int i = 0; i < size; ++i)
      for (typename list<Node>::iterator j = edgeList[i].begin(); j != edgeList[i].end(); ++j)
        if ((*j).v2 == index) {
          delete (*j).edge;
          edgeList[i].erase(j);
          ++deleted;
          //Стираем симметричное ребро
          if (directed == false)
            for (typename list<Node>::iterator k = edgeList[index].begin(); k != edgeList[index].end(); ++k)
              if ((*k).v2 == i) {
                edgeList[index].erase(k);
                break;
              }
          break;
        }
    if (directed == true) {
      for (typename list<Node>::iterator z = edgeList[index].begin(); z != edgeList[index].end(); ++z) {
        delete (*z).edge;
        deleted++;
      }
    }
    return deleted;
  }
  bool IsEdgeExist(int v1, int v2) {
    int size = edgeList.size();
    if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
      return false;
    // Loop
    if (v1 == v2)
      return false;
    for (typename list<Node>::iterator j = edgeList[v1].begin(); j != edgeList[v1].end(); ++j)
      if ((*j).v2 == v2)
        return true;
    return false;
  }

  Edge *GetEdge(int v1, int v2) {
    int size = edgeList.size();
    if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
      return nullptr;
    // Loop
    if (v1 == v2)
      return nullptr;

    if (edgeList[v1].size() == 0 || edgeList[v2].size() == 0)
      return nullptr;

    for (typename list<Node>::iterator j = edgeList[v1].begin(); j != edgeList[v1].end(); ++j)
      if ((*j).v2 == v2)
        return (*j).edge;
  }

};

#endif //BICONNECTED_GRAPH_SRC_GRAPHLIST_H_
