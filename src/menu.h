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
#include "Task2.h"
#include "Task1.h"

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
          "  11 EDGE QUANTITY\n"
          "  12 Weight K\n"
          "  13 IS DIRECTED\n"
          "  14 IS MATRIX\n"
          "  15 CHANGE FORM\n"
          "  16 TEST VERTEX ITERATOR\n"
          "  17 TEST EDGE ITERATOR\n"
          "  18 TEST INCOMING EDGES ITERATOR\n"
          "  19 TASK 1\n"
          "  20 TASK 2\n"
          "  21 CLEAR\n"
          "  0 EXIT\n"
          "===================\n";
}

void ShowIterMenu() {
  cout << "\n===================\n"
          "  ITERATOR MENU:\n"
          "  1 BEGIN\n"
          "  2 ++\n"
          "  3 *\n"
          "  0 EXIT\n"
          "===================\n";
}

void MainMenu() {
  int choice;
  bool flag = true;
  bool viFlag = false;
  bool eiFlag = false;
  bool oeiFlag = false;
  string str;
  int val;
  int id, v1, v2;

  auto *graph = new Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>(4, 7, false, false);

  while (flag) {
    system(clear_console_);
    graph->printGraph();
    ShowMainMenu();
    choice = GetNumber(0, 22, "");
    switch (choice) {
      /* add vertex */
      case 1: {
        if (graph->InsertVertex()) cout << "ADD\n" << endl;
        else cout << "FAIL\n" << endl;
        cin.get();
        break;
      }
        /* remove vertex */
      case 2: {
        id = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex:\n");
        if (graph->DeleteVertex(graph->GetVertex(id)))
          cout << "DELETE\n";
        else
          cout << "FAIL\n";
        cin.get();
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
        cin.get();
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
        cin.get();
        break;
      }
        /* get vertex val */
      case 5: {
        id = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex:\n");
        if (graph->GetVertex(id) != nullptr)
          cout << graph->GetVertex(id)->GetValue() << endl;
        else cout << "FAIL";
        cin.get();
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
        cin.get();
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
        cin.get();
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
        cin.get();
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
        cin.get();
        break;
      }
        /* vertex quantity */
      case 10: {
        cout << graph->GetNumOfVertex() << endl;
        cin.get();
        break;
      }
        /* edge quantity */
      case 11: {
        cout << graph->GetNumOfEdges() << endl;;
        cin.get();
        break;
      }
        /* weight  K */
      case 12: {
        cout << graph->GetDenseCoefficient() << endl;
        cin.get();
        break;
      }
        /* id directed */
      case 13: {
        cout << graph->IsDirected() << endl;
        cin.get();
        break;
      }
        /* is matrix */
      case 14: {
        if (graph->IsMatrix() == 1)
          cout << "Matrix\n";
        else
          cout << "List\n";
        cin.get();
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
        cin.get();
        break;
      }
        /* vertex iter */
      case 16: {
        viFlag = true;
        auto *vIter = new Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>::VertexIterator<int>(*graph);
        while (viFlag) {
          system(clear_console_);
          graph->printGraph();
          ShowIterMenu();
          int viChoice = GetNumber(0, 3, "");
          switch (viChoice) {
            case 1: {
              vIter->begin();
              cout << "BEGIN\n";
              cin.get();
              break;
            }
            case 2: {
              ++*vIter;
              break;
            }
            case 3: {
              if (vIter->getEnd())
                cout << "LOST ITERATOR\n";
              else
                cout << "NAME = " << vIter->getId()
                     << ", VALUE = " << vIter->getValue() << endl;
              cin.get();
              break;
            }
            case 0: {
              viFlag = false;
            }
              break;
          }
        }
        break;
      }
        /* edge iter */
      case 17: {
        eiFlag = true;
        while (eiFlag) {
          system(clear_console_);
          graph->printGraph();
          ShowIterMenu();
          Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>::EdgeIterator<int> *eIter;
          int viChoice = GetNumber(0, 3, "");
          switch (viChoice) {
            case 1: {
              eIter = new Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>::EdgeIterator<int>(graph, 0);
              cout << "BEGIN\n";
              cin.get();
              break;
            }
            case 2: {
              ++*eIter;
              break;
            }
            case 3: {
              if (eIter->getEnd())
                cout << "LOST ITERATOR\n";
              else
                cout << "NAME V1= " << eIter->getIdV1()
                     << ", VALUE V1= " << eIter->getValV1() << endl;
              cout << "NAME V2= " << eIter->getIdV2()
                   << ", VALUE V2= " << eIter->getValV2() << endl;
              cin.get();
              break;
            }
            case 0: {
              eiFlag = false;
            }
              break;
          }
        }

        break;
      }
        /* ie iter */
      case 18: {
        oeiFlag = true;
        int vertexId = GetNumber(INT32_MIN, INT32_MAX, "Enter vertex:\n");

        while (oeiFlag) {
          system(clear_console_);
          graph->printGraph();
          ShowIterMenu();
          Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>::OutgoingEdgeIterator<int> *oeIter;
          int viChoice = GetNumber(0, 3, "");
          switch (viChoice) {
            case 1: {
              oeIter = new Graph<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>::OutgoingEdgeIterator<int>(graph,
                                                                                                                graph->GetVertex(
                                                                                                                    vertexId),
                                                                                                                0);
              cout << "BEGIN\n";
              cin.get();
              break;
            }
            case 2: {
              ++*oeIter;
              break;
            }
            case 3: {
              if (oeIter->getEnd())
                cout << "LOST ITERATOR\n";
              else
                cout << "NAME V1= " << oeIter->getIdV1()
                     << ", VALUE V1= " << oeIter->getValV1() << endl;
              cout << "NAME V2= " << oeIter->getIdV2()
                   << ", VALUE V2= " << oeIter->getValV2() << endl;
              cin.get();
              break;
            }
            case 0: {
              oeiFlag = false;
            }
              break;
          }
        }
        break;
      }
        /* Task 1 */
      case 19: {
        auto *task1 = new Task1<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>(graph);
        graph = task1->toBiconnectedGraph();
        break;
      }
        /* Task 2 */
      case 20: {
        auto *task3 = new Task3<Vertex<int, int>, Edge<Vertex<int, int>, int, int>>(graph);

        int vertexId1 = GetNumber(INT32_MIN, INT32_MAX, "Enter the vertex: ");
        task3->result(vertexId1);
        cin.get();
        break;
      }
      case 21: {

        break;
      }
        /* Exit */
      case 0:flag = false;
        break;
    }
  }

}

#endif //BICONNECTED_GRAPH_SRC_MENU_H_
