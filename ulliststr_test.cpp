/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;

bool testPushFrontEmptyList()
{
  // Create a ULListStr
 ULListStr list;
  
  // push a string to the front of it
  list.push_front("Hello World");
  // Should check that the first item is what we expect -> call front()
  if(list.front() != "Hello World") {
   	cout << "Got " << list.front() << " as first element of list. Expected 'Hello World'" << endl;
    return false;
  }
  
  // Check that the size is 1
  if(list.size() != 1) {
    cout << "Got a size of " << list.size() << ". Expected 1" << endl;
    return false;
  }
  
  return true;
}

int main(int argc, char* argv[])
{
  //push front for an empty list
  if(testPushFrontEmptyList())
  {
	cout << "testPushFrontEmptyList() passed" << endl;
  }
  else 
  {
    cout << "testPushFrontEmptyList() failed" << endl;
  }

  return 0;
}
