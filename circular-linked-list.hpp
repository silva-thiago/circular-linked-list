#ifndef _CIRCULAR_LINKED_LIST_HPP_
#define _CIRCULAR_LINKED_LIST_HPP_

#include <iostream>

template <typename CLL>
struct node
{
  CLL content;
  struct node *next;
};

template <typename CLL>
class CircularLinkeList
{
  private:
    struct node<CLL> *head;
    struct node<CLL> *tail;
    int length;
  
  public:
    CircularLinkeList();
    ~CircularLinkeList();

    void push_back(CLL content);
    void push_front(CLL content);
    int search(CLL content);
    CLL getElement(int index);
    void remove(int index);
    void erase();
    int length();
    bool empty();
    void print();
};

#include "circular-linked-list.hpp"

#endif
