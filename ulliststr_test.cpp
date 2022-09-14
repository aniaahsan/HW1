/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{

  //first if statement push_front
  ULListStr dat;
  dat.push_back("0");
  int size = dat.size();
  string value = dat.get(0);
  cout << "Val:" << value << " Size:" << size << endl;
  //now test popping that value(second if statement in pop_front) 
  dat.pop_front();
  size = dat.size();
  cout << "Size:" << size << endl;

  //first if statement push_back
  dat.push_back("0");
  size = dat.size();
  value = dat.get(0);
  cout << "Val:" << value << " Size:" << size << endl;
  //now test popping that value(second if statement in pop_back) 
  dat.pop_back();
  size = dat.size();
  cout << "Size:" << size << endl;
  // call pop front and pop back to show that they just return when there is no value
  dat.pop_back();
  dat.pop_front();

  //pushing this list will create a linked list with two items ..12 and 345..
  dat.push_front("2");
  //this push_back command shows that push_back works when a new item needs to be created
  dat.push_back("3");
  //this push_back command shows that it works when just adding a value to the front of the existing item
  dat.push_back("4");
  //this push_front command shows that it works when just adding a value to the front of the existing item
  dat.push_front("1");
  dat.push_back("5");
  //print list and size
  for(int i=0;i<(int)dat.size();i++) {
    value = dat.get(i);
    cout << value << " ";
  }
  size = dat.size();
  cout << "size:" << size << endl;
  //popping this value will show that pop front works when it is just deleting a value from the item
  dat.pop_front();  //..2 345..
  //popping this value will show that pop front works when it has to delete the item
  dat.pop_front();  // 345..
  //print list and size
  for(int i=0;i<(int)dat.size();i++) {
    value = dat.get(i);
    cout << value << " ";
  }
  size = dat.size();
  cout << "size:" << size << endl;
  //this push_front command shows that push_front works when a new item needs to be created
  dat.push_front("a");  // ..a 345..
  //popping this value will show that pop back works when it is just deleting a value from the item
  dat.pop_back();  //..a 34..
  dat.pop_back(); // ..a 3..
  //popping this value will show that pop back works when it has to delete the item
  dat.pop_back(); // ..a
  //print list and size
  for(int i=0;i<(int)dat.size();i++) {
    value = dat.get(i);
    cout << value << " ";
  }
  size = dat.size();
  cout << "size:" << size << endl;
  dat.push_back("b");
  //shows that front and back functions work
  string front = dat.front();
  string back = dat.back();
  cout << front << " " << back << endl;
  //we already know get val at loc works because get works
  //it is a private function so it cannot be displayed here

  return 0;
}
