/**
 * @file circular-linked-list.cpp
 * @brief Developed circular linked list class in C++
 * @author Thiago Silva
 * @since 28/05/2018
 * @date 28/05/2018
 * 
 * @section Description
 *  
 * This class contains the basis of a circular linked list.
 */

/**
 * @brief Constructor
 */
template <typename CLL>
CircularLinkedList<CLL>::CircularLinkedList()
{
  /** @details The "head" is a pointer to the first element in the list.
   * As the list is empty, the head points to NULL.
   */
  head = new struct node<CLL>;
  head->next = nullptr;
  /** @Details The "tail" is a pointer to the last element in the list.
   * As the list is empty, the tail points to NULL.
   */
  tail = new struct node<CLL>;
  tail->next = nullptr;
  length = 0;
}

/**
 * @brief Desctructor
 */
template <typename CLL>
CircularLinkedList<CLL>::~CircularLinkedList() {}

/**
 * @brief Function that checks if the list is empty
 */
template <typename CLL>
bool CircularLinkedList<CLL>::empty()
{
  return length == 0;
}

/**
 * @brief Function that adds a new node at the top of the list
 */
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

/**
 * @brief Function that adds a new node at the end of the list
 */
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

/**
 * @brief Function to print the list nodes
 */
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

/**
 * @brief Function to remove the nodes from the list
 */
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
