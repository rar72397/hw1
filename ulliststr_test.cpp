/* Write your test code for the ULListStr in this file */
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
#include "ulliststr.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  ULListStr data;

  cout << "size: " << data.size() << endl;
  cout << "Pushing back if list is empty" << endl;
  cout << "Pushing 'hello' at back" << endl;
  data.push_back("hello");

  //Should give the same output
  cout << "front: " << data.front() << endl;
  cout << "back: " << data.back() << endl;

  cout << "Popping front" << endl;
  data.pop_front();

  //Pushing front if list is empty
  cout << "size: " << data.size() << endl;
  cout << "Pushing hi at front of empty list" << endl;
  data.push_front("hi");

  //Pushing front if there are already items
  cout << "Pushing 'world' at front if there are already items" << endl;
  data.push_front("world");

  cout << "front: " << data.front() << endl; //world
  cout << "back: " << data.back() << endl; //hi  

  cout << "Popping back" << endl;
  data.pop_back();
  cout << "size: " << data.size() << endl; //1
  data.pop_back();
  cout << "size: " << data.size() << endl; //0

  //Filling array of node + pushing back if items
  cout << "Filling node's array, and pushing back if items" << endl;
  for(int i=0; i<10; i++){
    data.push_back("a");
  }

  for(size_t i=0; i<10; i++){
    cout << i << ": " << data.get(i) << endl;
  }

  //Creates new node at front 
  cout << "Creating new node at front" << endl;
  data.push_front("word1");
  cout << ".front(): " << data.front() << endl; //word1
  cout << ".get(0): " << data.get(0) << endl; //word1

  //Creates new node at back
  cout << "Creating new node at back" << endl;
  data.push_back("word2"); 
  cout << ".back(): " << data.back() << endl; //word2
  cout << ".get(11): " << data.get(11) << endl; // word2

  cout << "front address: " << &(data.front()) << endl;
  cout << "back address: " << &(data.back()) << endl;
 
  cout << "Popping front and deallocating front node" << endl;
  data.pop_front();
  cout << "Popping back and deallocating back node" << endl;
  data.pop_back();
  
  cout << "new front: " <<  data.front() << " address: " << &(data.front()) << endl; //a
  cout << "new back: " << data.back() << " address: " << &(data.back()) << endl; //a

  //deleting list
  cout << "Clearing list" << endl;
  data.clear();
  return 0;
}
