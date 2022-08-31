/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
Node*& traverse(Node*& linkList);
void clear(Node*& head);

void split(Node*& in, Node*& odds, Node*& evens)
{

  if(in == NULL){ //Base case, the input list is empty
    return;
  }

  if( (in->value) % 2 == 0){ //If the value is even
    Node* temp = new Node(in->value, NULL);

    //If the evens is empty
    if(evens == NULL){
      evens = temp;
    }
    else{ //traverse list
      (traverse(evens))->next = temp;

    }

    split(in->next, odds, evens); //recursive call
  }

  else{ //If the value is odd
    Node* temp = new Node(in->value, NULL);
    //If odds is empty
    if(odds == NULL){
      odds = temp;
    }
    else{//traverse list
      (traverse(odds))->next = temp;
    }

    split(in->next, odds, evens); //recursive call
  }
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE

//returns the last node in the linked list, should not affect linked list
Node*& traverse(Node*& linkList){
  if(linkList->next == NULL){
    return linkList;
  }
  else{
    return traverse(linkList->next);
  }
}

void clear(Node*& head){
  if(head==NULL){
    return;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
  clear(head);
}