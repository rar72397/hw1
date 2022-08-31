#include "split.h"
#include <iostream>

using namespace std;

void print_list(Node*& head);

int main(){
  //test cases
  //1. empty list
  //2. negative numbers
  // (the output should still work, but just in case)
  //3. evens only
  //4. odds only
  //5. normal list

  int x;
  cout << "Enter a number 1-5 for different tests." << endl;
  cin >> x;

  if(x != 1){ // All other tests
    int a, b, c, d;
    if(x == 2){
      cout << "Test 2: negative numbers" << endl;
      a = -2;
      b = -1;
      c = 0;
      d = 5;
    }
    else if(x == 3){
      cout << "Test 3: evens only" << endl;
      a = 2;
      b = 4;
      c = 6;
      d = 8;
    }
    else if(x == 4){
      cout << "Test 4: odds only" << endl;
      a = 1;
      b = 3;
      c = 5;
      d = 7;
    }
    else if(x == 5){
      cout << "Test 5: normal list" << endl;
      a = 1;
      b = 2;
      c = 3;
      d = 4;
    }

    Node* in_head = NULL;
    Node* evens_head = NULL;
    Node* odds_head = NULL;

    Node* temp = new Node(a, NULL);
    in_head = temp;
    Node* temp1 = new Node(b, NULL);
    temp->next = temp1;
    Node* temp2 = new Node(c, NULL);
    temp1->next = temp2;
    Node* temp3 = new Node(d, NULL);
    temp2->next = temp3;

    cout << "linked list: ";
    print_list(in_head);

    //main execution, clean up of original linked list
    split(in_head, odds_head, evens_head);
    clear(in_head);

    //Printing out lists
    cout << "evens: ";
    print_list(evens_head);
    cout << "odds: ";
    print_list(odds_head);
    clear(odds_head);
    clear(evens_head);
  }

  else{ //Test 1
    cout << "Test 1: Empty list" << endl;
    Node* in_head = NULL;
    Node* evens_head = NULL;
    Node* odds_head = NULL;
    
    cout << "linked list: ";
    print_list(in_head);
    split(in_head, odds_head, evens_head);
    print_list(evens_head);
    print_list(odds_head);
  }

  return 0;
}

void print_list(Node*& head){
  Node* temp = head;
  while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}