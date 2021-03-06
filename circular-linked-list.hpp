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
    void push_back(CLL content);
    void push_front(CLL content);
    // int start_search(CLL content);
    // CLL get_element(int index);
    void remove_node(int index);
    // void erase_node();
    // int length_list();
    bool empty_list();
    void print_list();
};

#include "circular-linked-list.cpp"

#endif
