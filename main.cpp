/**
 * @file main.cpp
 * @brief Developed the main file in C++
 * @author Thiago Silva
 * @since 28/05/2018
 * @date 28/05/2018
 * 
 * @section Description
 *  
 * This file, main.cpp, contains important functions
 * for the correct execution of the program.
 */

#include "circular-linked-list.hpp"

int main(int argc, char const *argv[])
{
  CircularLinkeList<int> list;

  /**
   * Adding nodes at the bottom of the list
   */
  list.push_back(150);
  list.push_back(160);
  list.push_back(170);
  list.push_back(180);
  list.push_back(190);
  
  /**
   * Adding nodes at the top of the list
   */
  list.push_front(100);
  list.push_front(110);
  list.push_front(120);
  list.push_front(130);
  list.push_front(140);

  /**
   * Attached loop to test remove function
   */
  for (int i = 0; i < 5; i++)
  {
    list.remove_node(4);
  }

  /**
   * Printing list
   */
  list.print_list();

  return 0;
}
