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

void ULListStr::push_front(const std::string& val)
{
  // assuming the list is empty
  if(empty())
  {
    //create a node
    Item* firstItem = new Item();

    //add data to the first element of the array
    firstItem->val[0] = val;

    //set this node to head
    head_ = firstItem;

    //set this node to tail
    tail_ = firstItem;

    //set first to index 0
    firstItem->first = 0;

    //set last to index 1
    firstItem->last = 1;

    //add 1 to the size
    size_++;
  }
}

void ULListStr::push_back(const std::string& val)
{
    // assuming the list is empty
  if(empty())
  {
    //create a node
    Item* firstItem = new Item();

    //add data to the last element of the array (only element)
    firstItem->val[0] = val;

    //set this node to head
    head_ = firstItem;

    //set this node to tail
    tail_ = firstItem;

    //set first to index 0
    firstItem->first = 0;

    //set last to index 1
    firstItem->last = 1;

    //add 1 to the size
    size_++;
  }
}


/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
std::string const & ULListStr::front() const 
{
  // TODO: should we throw an exception for an empty list?
  return head_->val[ head_->first ];
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