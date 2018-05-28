template <typename CLL>
CircularLinkedList<CLL>::CircularLinkedList()
{
  head = new struct node<CLL>;
  head->next = nullptr;
  tail = new struct node<CLL>;
  tail->next = nullptr;
  length = 0;
}

template <typename CLL>
CircularLinkedList<CLL>::~CircularLinkedList() {}