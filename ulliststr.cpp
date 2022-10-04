#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
<<<<<<< HEAD
=======
void ULListStr::push_back(const std::string& val){
  if(empty()){
    Item* node = new Item; 
    head_ = node;
    tail_ = node; 
    node->first = 0;
    node->last = 1;
    node->val[node->first] = val;
  }
  else{
    //If there isn't any space and end of Item's array, create a new
    //Item. Point tail at new node. 

    if(tail_->last == 10){
      Item* node = new Item;
      tail_->next = node;
      node->prev = tail_;
      tail_ = node;

      node->first = 0;
      node->last = 1;
      node->val[node->first] = val;
      
    }

    // Otherwise, put at end
    else{
      //not last+1 since last doesn't actually point to anything
      tail_->val[tail_->last] = val;
      (tail_->last)++;
    }
  }
  size_++;
}

void ULListStr::pop_back(){
  size_--;

  //last-1 since last points to memory after array
  (tail_->last)--;

  //delete node if array is now empty
  if((tail_->first - tail_->last) == 0){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(head_ == tail_){
      head_->next = NULL;
    }
    delete temp;
  }
}

// O(1), can't use get()
void ULListStr::push_front(const std::string& val){
  if(empty()){
    Item* node = new Item;
    head_ = node;
    tail_ = node;
    node->first = 9;
    node->last = 10;
    node->val[node->first] = val;
  }
  else{
    ///If there isn't any space in front of Item's array create a new
    // Item. Make head point to new node.
    
    if(head_->first == 0){
      Item* node = new Item;
      head_->prev = node;
      node->next = head_;
      head_ = node;
      
      node->first = 9;
      node->last = 10;
      node->val[node->first] = val;
    }

    //Otherwise, put at front
    else{ 
      //first-1 since otherwise it would be replacing first
      head_->val[(head_->first)-1]= val;
      (head_->first)--;
    }
  }
  size_++;
}

//O(1) can't use get
void ULListStr::pop_front(){
  size_--;
  (head_->first)++;
  
  //delete node if array is now empty
  if((head_->first - head_->last) == 0){
    Item* temp = head_;
    head_ = head_->next;
    if(head_ == tail_){
      head_->next = NULL;
    }
    delete temp;
  }
}

//O(1) can't use get
std::string const & ULListStr::back() const{
  return tail_->val[(tail_->last)-1];
}

//O(1) can't use get
std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

//O(n)
std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;
  size_t counter = temp->first; 
  for(size_t i=0; i<size_; i++){
    //if we reached the end of a node's array, move to next node
    if(counter == temp->last){
      temp = temp->next;
      counter = temp->first;
    }
    if(i == loc){
      return &(temp->val[counter]);
    }
    counter++;
  }
  return NULL;
}

////// END OF MY CODE ////////
>>>>>>> da7d71ca271da0654c0d898808416f701b7011a3

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
