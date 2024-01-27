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
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (head_ == NULL || loc >= size_) {
    return NULL;
  }
  int i = loc;
  Item* temp = head_;
  int first_;
  int last_;
  while (i > 0 && temp != NULL) {
    first_ = temp->first;
    last_ = temp->last;
    if (i - (last_ - first_) >= 0) {
      i = i - (last_ - first_);
      temp = temp->next;
    } else {
      break;
    }
  }
  if (temp == NULL) {
    return NULL;
  }
  return temp->val + temp->first + i;
}

/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val) {
  if (tail_ == NULL) { //if empty list
    head_ = new Item();
    tail_ = head_;
    tail_->val[0] = val;
    tail_->last = 1;
    size_ += 1;
    return;
  }
  else {
    if (tail_->last == 10) {//if val is full we need to make a new item
      tail_->next = new Item();
      Item* temp = tail_;
      tail_ = tail_->next;
      tail_->prev = temp;
    }
    tail_->val[tail_->last] = val;
    tail_->last += 1;
    size_ += 1;
    return;
  }
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back() {
  //3 checks needed if empty, if only one item left, if otherwise normal
  if (tail_ == NULL) { //if empty
    return;
  }
  if (tail_->last - tail_->first == 1) { //one item left
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ == NULL) {
      head_ = NULL;
    } else {
      tail_->next = NULL;
    }
    delete temp;
    size_ -= 1;
    return;
  }
  else { //everything is fine
    tail_->last -= 1;
    size_ -= 1;
    return;
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
  if (head_ == NULL) { //if empty list
    head_ = new Item();
    tail_ = head_;
    head_->val[9] = val;
    head_->last = 10;
    head_->first = 9;
    size_ += 1;
    return;
  }
  else {
    if (head_->first == 0) {//if val is full we need to make a new item
      head_->prev = new Item();
      Item* temp = head_;
      head_ = head_->prev;
      head_->next = temp;
      //since newly created, first & last are 0 so we gotta fix it here
      head_->val[9] = val;
      head_->first = 9;
      head_->last = 10;
      size_ += 1;
      return;
    }
    else { //if list was not newly created
      head_->val[head_->first - 1] = val;
      head_->first -= 1;
      size_ += 1;
      return;
    }
  }
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front() {
  //3 cases must be checked: if empty list, if last item, if otherwise normal
  if (head_ == NULL) { //empty
    return;
  }
  if (head_->last - head_->first == 1) { //one item left
    Item* temp = head_;
    head_ = head_->next;
    if (head_ == NULL) {
      tail_ = NULL;
    } else {
      head_->prev = NULL;
    }
    delete temp;
    size_ -= 1;
    return;
  } else { //otherwise normal
    head_->first += 1;
    size_ -= 1;
    return;
  }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

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
