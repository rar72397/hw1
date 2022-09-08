/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr data;

  //Pushing back if list is empty
  cout << data.size() << endl;
  data.push_back("hello");

  //Should give the same output
  cout << data.front() << endl;
  cout << data.back() << endl;

  data.pop_front();

  //Pushing front if list is empty
  cout << data.size() << endl;
  data.push_front("hi");

  //Pushing front if there are already items
  data.push_front("world");

  cout << data.front() << endl; //world
  cout << data.back() << endl; //hi  

  data.pop_back();
  cout << data.size() << endl; //1
  data.pop_back();
  cout << data.size() << endl; //0

  //Filling array of node + pushing back if items
  for(int i=0; i<10; i++){
    data.push_back("a");
  }

  for(size_t i=0; i<10; i++){
    cout << i << ": " << data.get(i) << endl;
  }

  //Creates new node at front 
  data.push_front("word1");
  cout << data.front() << endl; //word1
  cout << data.get(0) << endl; //word1

  //Creates new node at back
  data.push_back("word2"); 
  cout << data.back() << endl; //word2
  cout << data.get(11) << endl; // word2

  data.pop_front();
  data.pop_back();
  
  cout << data.front() << endl; //a
  cout << data.back() << endl; //a
  
  
  //deleting list
  data.clear();
  return 0;
}
