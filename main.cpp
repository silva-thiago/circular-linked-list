#include "circular-linked-list.hpp"

int main(int argc, char const *argv[])
{
  CircularLinkeList<int> list;

  list.PushBack(150);
  list.PushBack(160);
  list.PushBack(170);
  list.PushBack(180);
  list.PushBack(190);
  
  list.PushFront(100);
  list.PushFront(110);
  list.PushFront(120);
  list.PushFront(130);
  list.PushFront(140);

  for (int i = 0; i < 5; i++)
  {
    list.Remove(4);
  }

  list.Print();

  return 0;
}
