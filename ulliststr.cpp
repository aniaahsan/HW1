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

void ULListStr::push_back(const std::string& val) {
  if (tail_==nullptr) {  //if the list is empty
    Item* new_item = new Item();  //create a new item
    new_item->first = 0;  //since it is push_back make the value input into the front of the array
    new_item->last = 1;
    new_item->val[new_item->first] = val;
    head_ = new_item;  //both head and tail are this item since there is only one
    tail_ = new_item;
    size_++;  //increment size
  }
  else if(tail_->last<ARRSIZE) {  //there is already an array with space to push_back
    tail_->val[tail_->last] = val; //set last pointer to value
    tail_->last += 1;  //increment last
    size_++;  //increment size
  }
  else {  //need to make a new item
    Item* new_item = new Item();
    new_item->first = 0;  //for push_back push to the front of the new array
    new_item->last = 1;
    new_item->val[new_item->first] = val;
    new_item->prev = tail_; //set new item as tail
    tail_->next = new_item;
    tail_ = new_item;
    size_++;  //increment size
  }
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back() {
  if(size_==0) {  //nothing exists to be deleted
    return;
  }
  else if(head_==tail_&&size_==1) {  //only one value
    size_--;  //decrement size
    Item* temp = tail_;  //temp to delete
    head_ = nullptr;  //make head and tail null
    tail_ = nullptr;  
    delete temp;
  }
  else if(tail_->last-tail_->first>1) { //if removing one value does not require deleting the item
    tail_->last -=1; //decrease last by 1
    size_--; //decrement size
  }
  else {
    Item* temp = tail_;  //need to create temp item to delete
    tail_->prev->next = nullptr;  //set previous item's next to null
    tail_ = tail_->prev; 
    delete temp; 
    size_--;  //decrement size
  }
}

/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const std::string& val) {
  if (head_==nullptr) {  //if list is empty
    Item* new_item = new Item();  //create an item
    new_item->first = ARRSIZE-1;  //since push_front insert val at the back of the array
    new_item->last = ARRSIZE;
    new_item->val[new_item->first] = val;
    head_ = new_item;  //set head and tail to new item
    tail_ = new_item;
    size_++;  //increment size
  }
  else if(head_->first>0) {  //if first is greater than zero you can push front in the current item
    head_->first -= 1; //move first pointer to next empty slot
    head_->val[head_->first] = val;  //input value at first
    size_++;  //increment size
  }
  else {
    Item* new_item = new Item();  //need to create new item
    new_item->first = ARRSIZE-1;  //imput value at the end of the array
    new_item->last = ARRSIZE;
    new_item->val[new_item->first] = val; 
    new_item->next = head_;  //set next pointer of new item to current head
    head_->prev = new_item;  //set current head prev to new item
    head_ = new_item;  //set head to new item
    size_++;  //increment size
  }
}

/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front() {
  if(size_==0) {  //no items in list
    return;
  }
  else if(head_==tail_&&size_==1) {  //only one item in list
    size_--;  //decrement size
    Item* temp = head_; //create temp to delete
    tail_ = nullptr;  //set head and tail to null
    head_ = nullptr; 
    delete temp;
  }
  else if(head_->last-head_->first>1) {  //there is more than one value in the current head
    head_->first +=1;  //just move the first pointer to next item
    size_--;  //decrement size
  }
  else {
    Item* temp = head_;  //set temp item to delete head
    head_->next->prev = nullptr;  //set next node's prev to null since the head is being deleted
    head_ = head_->next;  //head becomes next node
    delete temp;  //delete item
    size_--;  //decrement size
  }
}

/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];  
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

/** 
  * Returns a pointer to the item at index, loc,
  *  if loc is valid and NULL otherwise
  *   - MUST RUN in O(n) 
  */
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc>size_) {
    return nullptr;
  }
  Item* placer = head_;  //current node that we are looking for value in
  unsigned int sub = 0;  //how much we are subtracting from the location if it is later in the list
  while(loc>=0) {  //haven't found value
    sub = placer->last-placer->first;  //size of array of current item
    if(loc<sub) {  //location is within the current item
      std::string ret = placer->val[placer->first+loc]; //return string is the value in the placer item at (first + loc) location
      std::string* location = &ret;  //set pointer to the return string
      return location;
    } else {
      placer = placer->next;  //move to next item as placer
      loc = loc-sub;  //subtract old placer size from loc
    }
  }
}
