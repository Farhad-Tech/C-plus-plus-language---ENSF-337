// OLList2.cpp
// ENCM 339 Spring 2016 Lab 11 Exercise I


#include <iostream>
using namespace std;
#include <stdlib.h>
#include "OLList2.h"

OLList::OLList()
  : headM(0)
{
}

OLList::OLList(const OLList& source)
{
  copy(source);
}

OLList::~OLList()
{
  destroy();
}

OLList& OLList::operator =(const OLList& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

void OLList::insert(const ListItem& itemA)
{
  Node *new_node = new Node;
  new_node->item = itemA;

  if (headM == 0 || itemA <= headM->item) {
    new_node->next = headM;
    headM = new_node;
  }
  else {
    Node *before = headM;      // will point to node in front of new node
    Node *after = headM->next; // will be 0 or point to node after new node
    while(after != 0 && itemA > after->item) {
      before = after;
      after = after->next;
    }
    new_node->next = after;
    before->next = new_node;
  }
}

void OLList::remove(const ListItem& itemA)
{
  if (headM == 0 || itemA < headM->item)
    return;

  Node *doomed_node = 0;
  if (itemA == headM->item) {
    doomed_node = headM;
    headM = headM->next;
  }
  else {
    Node *before = headM;
    Node *maybe_doomed = headM->next;
    while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->next;
    }
    if (maybe_doomed != 0 && maybe_doomed->item == itemA) {
      doomed_node = maybe_doomed;
      before->next = maybe_doomed->next;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

void OLList::print() const
{
  if (headM == 0)
    cout << "  LIST IS EMPTY.\n";
  else
    for (Node *p = headM; p != 0; p = p->next)
      cout << "  " << p->item << '\n';
}

void OLList::copy(const OLList& source)
{
  // The next line doesn't do anything.  It justs shuts up the compiler
  // warning about an unused argument.
  (void) source;

  // Print an error message and terminate the program.
  cout << "\nOLList::copy is not implemented properly, so the program"
       << " is calling exit.\n";
  exit(1);

}

void OLList::destroy()
{
  destroy_sublist(headM);
}

void OLList::destroy_sublist(Node *sublist_head)
{
  if (sublist_head != 0) {
    destroy_sublist(sublist_head->next);

    // point one

    delete sublist_head;
  }
}
