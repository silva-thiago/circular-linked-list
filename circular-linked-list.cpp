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
bool CircularLinkedList<CLL>::empty()
{
  return length == 0;
}

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

template <typename CLL>
void CircularLinkedList<CLL>::push_back(CLL content)
{
  if (empty())
  {
    push_front(content);
    return;
  }

  struct node<CLL> *newNode = new struct node<CLL>;
  newNode->content = content;
  newNode->next = tail->next->next;
  tail->next->next = newNode;
  tail->next = newNode;
  length++;
}

template<typename CLL>
void CircularLinkedList<CLL>::print()
{
  struct node<CLL> *aux = head->next;

  for (int i = 0; i < length; i++)
  {
    std::cout << aux->content << " ";
    aux = aux->next;
  }
  std::cout << std::endl;
}

template<typename CLL>
void CircularLinkedList<CLL>::remove(int index)
{
  if (index < 0 || index >= length)
  {
    std::cout << "Error: Invalid index!" << std::endl;
    return;
  }

  struct node<CLL> * aux = head->next;
  for (int i = 0; i < index - 1; i++)
  {
    aux = aux->next;
  }

  struct node<CLL> *aux2 = aux->next;
  aux->next = aux2->next;
  delete aux2;
  length--;
}
