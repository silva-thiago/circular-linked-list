/**
 * @file circular-linked-list.hpp
 * @brief Developed circular linked list class in C++
 * @author Thiago Silva
 * @since 28/05/2018
 * @date 28/05/2018
 * 
 * @section Description
 *  
 * This class contains the basis of a circular linked list.
 */

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
    /**
       * @brief Atributes
       */
    struct node<CLL> *head;
    struct node<CLL> *tail;
    int length;

  public:
    /**
       * @brief constructor & destructor
       */
    CircularLinkeList();
    ~CircularLinkeList();

    /**
       * @brief methods
       */
    void PushBack(CLL content);
    void PushFront(CLL content);
    int Search(CLL content);
    CLL getElement(int index);
    void Remove(int index);
    void Erase();
    int Length();
    bool Empty();
    void Print();
};

#include "circular-linked-list.cpp"

#endif
