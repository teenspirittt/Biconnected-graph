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
          "  9 VERTEX QUANTITY\n"
          " 10 EDGE QUANTITY\n"
          " 11 K\n"
          " 13 IS DIRECTED\n"
          " 14 IS LIST\n"
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
  bool iterator_flag = false;
  string str;
  int val;
  int key;

  //TTTree<int, int> tree;

  while (flag) {
    system(clear_console_);
    //cout << tree.ToString();
    ShowMainMenu();
    choice = GetNumber(0, 11, "");
    switch (choice) {
      case 1: {

        break;
      }
      case 2: {

        break;
      }
      case 3: {

        break;
      }
      case 4: {

        break;
      }
      case 5: {
        break;
      }
      case 6: {
        break;
      }
      case 7: {
        break;
      }
      case 8: {
        break;
      }
      case 9: {

        break;
      }
      case 10: {

        break;
      }
      case 11: {

        break;
      }
      case 0:flag = false;
        break;
    }
  }
}

#endif //BICONNECTED_GRAPH_SRC_MENU_H_
