#ifndef _CIRCULAR_LINKED_LIST_HPP_
#define _CIRCULAR_LINKED_LIST_HPP_

#include <iostream>

template <typename CLL>
struct node
{
  CLL content;
  struct node *next;
};

#endif