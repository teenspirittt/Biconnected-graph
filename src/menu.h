//
// Created by teenspirit on 12/19/22.
//

#ifndef BICONNECTED_GRAPH_SRC_MENU_H_
#define BICONNECTED_GRAPH_SRC_MENU_H_

#include "Edge.h"
#include "Graph.h"
#include "GraphMatrix.h"
#include "GraphList.h"
#include "Vertex.h"
#include <iostream>

#ifdef __linux__
#define clear_console_ "clear"
#else
#define clear_console_ "cls"
#endif

using namespace std;

int GetNumber(int l_gap, int h_gap, const char *msg) {
  int number;
  cout << msg;
  while (true) {
    cin >> number;
    if ((number >= l_gap) && (number <= h_gap) && (cin.peek() == '\n'))
      break;
    else {
      cout << "INVALID INPUT\n";
      cin.clear();
      while (cin.get() != '\n') {
      }
    }
  }
  cin.get();
  return number;
}

void ShowMainMenu() {
  cout << "\n===================\n"
          "    MENU:\n"
          "  1 ADD VERTEX\n"
          "  2 REMOVE VERTEX\n"
          "  3 ADD EDGE\n"
          "  4 REMOVE EDGE\n"
          "  5 GET VERTEX VALUE\n"
          "  6 SET VERTEX VALUE\n"
          "  7 GET EDGE VALUE\n"
          "  8 SET EDGE VALUE\n"
          "  9 SET EDGE WEIGHT\n"
          "  10 VERTEX QUANTITY\n"
          " 11 EDGE QUANTITY\n"
          " 12 K\n"
          " 13 IS DIRECTED\n"
          " 14 IS MATRIX\n"
          " 15 CHANGE FORM\n"
          " 16 TEST ITERATOR\n"
          " 17 CLEAR\n"
          " 0 EXIT\n"
          "===================\n";
}

void MainMenu() {
  int choice;
  int pos;
  uint list_size;
  bool flag = true;
  bool form_flag = false;
  bool iterator_flag = false;
  string str;
  int val;
  int key;
  int id, v1, v2;

  auto *graph = new Graph<Vertex<int>, Edge<Vertex<int>, int, int>>();

  while (flag) {
    system(clear_console_);
    // graph->printGraph();
    ShowMainMenu();
    choice = GetNumber(0, 14, "");
    switch (choice) {
      /* add vertex */
      case 1: {
        if (graph->InsertVertex()) cout << "ADD\n" << endl;
        else cout << "FAIL\n" << endl;
        break;
      }
        /* remove vertex */
      case 2: {
        id = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex:\n");
        if (graph->DeleteVertex(graph->GetVertex(id)))
          cout << "DELETE\n";
        else
          cout << "FAIL\n";
        break;
      }
        /* add edge */
      case 3: {
        v1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the incoming vertex:\n");
        v2 = GetNumber(INT32_MIN, INT32_MAX, "Enter the outgoing vertex:\n");
        if (graph->InsertEdge(graph->GetVertex(v1), graph->GetVertex(v2)))
          cout << "ADD\n";
        else
          cout << "FAIL\n";
        break;
      }
        /* remove edge */
      case 4: {
        v1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the incoming vertex:\n");
        v2 = GetNumber(INT32_MIN, INT32_MAX, "Enter the outgoing vertex:\n");
        if (graph->DeleteEdge(graph->GetVertex(v1), graph->GetVertex(v2)))
          cout << "DELETE\n";
        else
          cout << "FAIL\n";
        break;
      }
        /* get vertex val */
      case 5: {
        id = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex:\n");
        if (graph->GetVertex(id) != nullptr)
          cout << graph->GetVertex(id)->GetValue() << endl;
        else cout << "FAIL";
        break;
      }
        /* set vertex val */
      case 6: {
        id = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex:\n");
        val = GetNumber(INT32_MIN, INT32_MAX, "Enter the value:\n");
        if (graph->GetVertex(id) != nullptr) {
          graph->GetVertex(id)->SetValue(val);
          cout << "SET\n";
        } else cout << "FAIL\n";
        break;
      }
        /* get edge val */
      case 7: {
        v1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the incoming vertex:\n");
        v2 = GetNumber(INT32_MIN, INT32_MAX, "Enter the outgoing vertex:\n");
        if (graph->GetVertex(v1) == nullptr || graph->GetVertex(v2) == nullptr) {
          cout << "FAIL";
        } else {
          if (graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2)) != nullptr)
            cout << graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2))->GetValue() << endl;
          else
            cout << "FAIL";
        }
        break;
      }
        /* set edge val */
      case 8: {
        v1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the incoming vertex:\n");
        v2 = GetNumber(INT32_MIN, INT32_MAX, "Enter the outgoing vertex:\n");
        val = GetNumber(INT32_MIN, INT32_MAX, "Enter the value:\n");
        if (graph->GetVertex(v1) == nullptr || graph->GetVertex(v2) == nullptr) {
          cout << "FAIL";
        } else {
          if (graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2)) != nullptr)
            graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2))->SetValue(val);
          else
            cout << "FAIL";
        }
        break;
      }
      /* set edge weight */
      case 9: {
        v1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the incoming vertex:\n");
        v2 = GetNumber(INT32_MIN, INT32_MAX, "Enter the outgoing vertex:\n");
        val = GetNumber(INT32_MIN, INT32_MAX, "Enter the weight:\n");
        if (graph->GetVertex(v1) == nullptr || graph->GetVertex(v2) == nullptr) {
          cout << "FAIL";
        } else {
          if (graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2)) != nullptr)
            graph->GetEdge(graph->GetVertex(v1), graph->GetVertex(v2))->SetWeight(val);
          else
            cout << "FAIL";
        }
      }
        /* vertex quantity */
      case 10: {
        cout << graph->GetNumOfVertex() << endl;
        break;
      }
        /* edge quantity */
      case 11: {
        cout << graph->GetNumOfEdges() << endl;;
        break;
      }
        /* K */
      case 12: {
        cout << graph->GetDenseCoefficient() << endl;;
        break;
      }
        /* id directed */
      case 13: {
        cout << graph->IsDirected() << endl;;
        break;
      }
        /* is matrix */
      case 14: {
        if (graph->IsMatrix() == 1)
          cout << "Matrix\n";
        else
          cout << "List\n";
        break;
      }
        /* change form */
      case 15: {
        if (graph->IsMatrix()) {
          graph->ToListGraph();
          cout << "TO LIST";
        } else {
          graph->ToMatrixGraph();
          cout << "TO MATRIX";
        }
        break;
      }
      case 16: {

        break;
      }
        /* Exit */
      case 0:flag = false;
        break;
    }
  }
}

#endif //BICONNECTED_GRAPH_SRC_MENU_H_
