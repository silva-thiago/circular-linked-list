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

template <typename CLL>
void CircularLinkedList<CLL>::push_front(CLL content)
{
  struct node<CLL> *newNode = new struct node<CLL>;
  newNode->content = content;

  if (empty())
  {
    tail->next = newNode;
    newNode->next = newNode;
  }
  else
  {
    newNode->next = newNode;
    tail->next->next = newNode;
  }
  head->next = newNode;
  length++;
}
