/*

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"


void split(Node*& in, Node*& odds, Node*& evens)
{
  splitHelper(in, odds, evens);
  in = nullptr;
}

/* Add a prototype for a helper function here if you need */

void splitHelper(Node*& in, Node*& odds, Node*& evens)
{
  // check for the base case
  // check if the current node is null
  if (in == nullptr)
  {
    return;
  }
  
  // 	return;
  
  // recursive step
  split(in->next, odds, evens);
  // go to the next node after 'in'
  
  // do the work
  // put the 'in' Node into odds or evens
  if (in->value %2 != 0)
  {
    Node* prevOdds = odds;
    odds = in;
    odds->next = prevOdds;
  }
  
  else
  {
    Node* prevEvens = evens;
    evens = in;
    evens->next = prevEvens;
  }
    
}