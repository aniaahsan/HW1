#include "split.h"
#include <iostream>
// #include "split.cpp"

using namespace std;

int main (){
  Node tail = Node(9, nullptr);
  Node* seven = &tail;
  Node se = Node(7, seven);
  Node* six = &se;
  Node si = Node(6, six);
  Node* five = &si;
  Node fi = Node(5, five);
  Node* four = &fi;
  Node fo = Node(3, four);
  Node* two = &fo;
  Node head = Node(2, two);
  Node* in = &head;
  Node* evens;
  evens = nullptr;
  Node* odds;
  odds=nullptr;
  split(in, odds, evens);
  int x = odds-> value;
  int y = evens->value;
  cout << x << y << endl;
  // cout << evens->value << endl;
  return 0;
}