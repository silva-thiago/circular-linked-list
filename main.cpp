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
  list.PushBack(150);
  list.PushBack(160);
  list.PushBack(170);
  list.PushBack(180);
  list.PushBack(190);
  
  /**
   * Adding nodes at the top of the list
   */
  list.PushFront(100);
  list.PushFront(110);
  list.PushFront(120);
  list.PushFront(130);
  list.PushFront(140);

  /**
   * Attached loop to test remove function
   */
  for (int i = 0; i < 5; i++)
  {
    list.Remove(4);
  }

  /**
   * Printing list
   */
  list.Print();

  return 0;
}
