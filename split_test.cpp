#include "split.h"
#include <iostream>

using namespace std;

// normal case -> in contains some odds and some evens
bool testSplitNormalCase()
{
  Node* firstNode = new Node(1, nullptr);
  Node* secondNode = new Node(2, nullptr);
  firstNode->next = secondNode;
  Node* thirdNode = new Node(3, nullptr);
  secondNode->next = thirdNode;
  Node* fourthNode = new Node(4, nullptr);
  thirdNode->next = fourthNode;
  
  Node* in = firstNode;
  Node* odds = nullptr;
  Node* evens = nullptr;
  
  split(in, odds, evens);
  
  if (odds != firstNode || odds->next != thirdNode || odds->next->next != nullptr)
  {
    cout << "Odds list is not correct" << endl;
    
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    delete fourthNode;
    
    return false;
  }
  if (evens != secondNode || evens->next != fourthNode || evens->next->next != nullptr)
  {
    cout << "Evens list is not correct" << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    delete fourthNode;
    
    return false;
  }
  if(in != nullptr)
  {
	cout << "in should be null. Got value of " << in->value << endl;
    
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    delete fourthNode;
    
    return false;
  }
    
  delete firstNode;
  delete secondNode;
  delete thirdNode;
  delete fourthNode;
  
  return true;
 
}
// edge case -> if in is nullptr
bool testSplitNull()
{
  Node* firstNode = nullptr;
  
  Node* in = firstNode;
  Node* odds = nullptr;
  Node* evens = nullptr;
  
  split(in, odds, evens);
  
  if (in != nullptr)
  {
    cout << "in should be null" << endl;
    return false;
  }
  
  if (odds != nullptr)
  {
    cout << "odds should be null" << endl;
    return false;
  }
  
  if (evens != nullptr)
  {
    cout << "evens should be null" << endl;
    return false;
  }
  
  return true;
  
}
// edge case -> in only contains odds
bool testSplitOdds()
{
  Node* firstNode = new Node(1, nullptr);
  Node* secondNode = new Node(3, nullptr);
  firstNode->next = secondNode;
  Node* thirdNode = new Node(5, nullptr);
  secondNode->next = thirdNode;
  
  Node* in = firstNode;
  Node* odds = nullptr;
  Node* evens = nullptr;
  
  split(in, odds, evens);
  
  if (odds != firstNode || odds->next != secondNode || odds->next->next != thirdNode ||  odds->next->next->next != nullptr)
  {
    cout << "Odds list is not correct" << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  if (evens != nullptr)
  {
    cout << "Evens list is not correct" << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  if(in != nullptr)
  {
	cout << "in should be null. Got value of " << in->value << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  
  delete firstNode;
  delete secondNode;
  delete thirdNode;
    
  return true;
}
// edge case -> in only contains evens
bool testSplitEvens()
{
  Node* firstNode = new Node(2, nullptr);
  Node* secondNode = new Node(4, nullptr);
  firstNode->next = secondNode;
  Node* thirdNode = new Node(6, nullptr);
  secondNode->next = thirdNode;
  
  Node* in = firstNode;
  Node* odds = nullptr;
  Node* evens = nullptr;
  
  split(in, odds, evens);
  
  if (odds != nullptr)
  {
    cout << "Odds list is not correct" << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  if (evens != firstNode || evens->next != secondNode || evens->next->next != thirdNode ||  evens->next->next->next != nullptr)
  {
    cout << "Evens list is not correct" << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  if(in != nullptr)
  {
	cout << "in should be null. Got value of " << in->value << endl;
    delete firstNode;
    delete secondNode;
    delete thirdNode;
    return false;
  }
  
  delete firstNode;
  delete secondNode;
  delete thirdNode;
    
  return true;
}

int main ()
{
	if(testSplitNormalCase())
    {
      cout << "testSplitNormalCase() passed" << endl;
    }
    else
    {
	  cout << "testSplitNormalCase() failed" << endl;
    }
  
  	if(testSplitNull())
    {
      cout << "testSplitNull() passed" << endl;
    }
    else
    {
	  cout << "testSplitNull() failed" << endl;
    }
  
  	if(testSplitOdds())
    {
      cout << "testSplitOdds() passed" << endl;
    }
    else
    {
	  cout << "testSplitOdds() failed" << endl;
    }
  
  if(testSplitEvens())
    {
      cout << "testSplitEvens() passed" << endl;
    }
    else
    {
	  cout << "testSplitEvens() failed" << endl;
    }
  
  return 0;

}