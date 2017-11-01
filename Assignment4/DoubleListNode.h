#include <iostream>

using namespace std;

template <class T>
class ListNode
{
public:
  ListNode<T>* next;
  ListNode<T>* prev;
  T data;
  ListNode();
  ListNode(T d);
  ~ListNode();
};

template <class T>
ListNode<T>::ListNode()
{
  data = 0;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{
  if (next != NULL)
    delete next;
}

template <class T>
class DoublyLinkedList
{
private:
  unsigned int size;
public:
  ListNode<T>* front;
  ListNode<T>* back;
  DoublyLinkedList();
  ~DoublyLinkedList();
  void insertFront(T data);
  int removeFront();
  void insertBack(T data);
  int removeBack();
  void printList();
  int remove(T key);
  int find(T value);
  int deletePos(int pos);
  bool insertAfter(int pos, T val); //@TODO
  bool isEmpty();
  unsigned int getSize();
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
  size = 0;
  front = NULL;
  back = NULL;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  ListNode<T>* current = front;

  while (current)
  {
      ListNode<T>* next = current->next;
      delete current;
      current = next;
  }
}

template <class T>
void DoublyLinkedList<T>::insertFront(T data)
{

  ListNode<T>* node = new ListNode<T>(data);
  if (size == 0)
    back = node;
  else
  {
    front->prev = node;
    node->next = front;
  }
  front = node;
  ++size;
}

template <class T>
int DoublyLinkedList<T>::removeFront()
{
  T val = front->data;
  if (front->next == NULL)
    back = NULL;
  else
    front->next->prev = NULL;
  front = front->next;

  --size;
  return val;
}

template <class T>
void DoublyLinkedList<T>::printList()
{
  ListNode<T>* curr = front;
  while(curr)
  {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
int DoublyLinkedList<T>::find(T value)
{
  int idx = -1; //index tracker
  ListNode<T>* curr = front;

  while(curr != NULL)
  {
    ++idx;
    if(curr->data == value)
    {
      break;
    }
    else
    {
      curr = curr->next;
    }
  }

  if (curr == NULL)
     idx = -1;
  return idx;
}

template <class T>
int DoublyLinkedList<T>::deletePos(int pos)
{
  int idx = 0;
  ListNode<T>* curr = front;
  ListNode<T>* prev = front;

  while(idx != pos)
  {
    ++idx;
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;
  curr->next = NULL;
  int d = curr->data;
  size--;
  delete curr;
  return d;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
  return size == 0;
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

template <class T>
void DoublyLinkedList<T>::insertBack(T data)
{
  ListNode<T>* node = new ListNode<T>(data);

  if (size == 0)
    front = node;
  else
  {
    back->next = node;
    node->prev = back;
  }
  back = node;
  ++size;

}

template <class T>
int DoublyLinkedList<T>::removeBack()
{
  T val = back->data;
  if (back->prev == NULL)
    front = NULL;
  else
    back->prev->next = NULL;
  back = back->prev;
  --size;
  return val;

}

template <class T>
int DoublyLinkedList<T>::remove(T key)
{
  ListNode<T>* curr = front;
  while(curr->data != key)
  {
    curr = curr->next;
    if (curr == back)
      return 0;
  }

  if (curr == front)
  {
    front = curr->next;
  }
  else
  {
    curr->prev->next = curr->next;
  }

  if (curr == back)
  {
    back = curr->prev;
  }
  else
  {
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  --size;

  int temp = curr->data;
  delete curr;

  return temp;
}

template <class T>
bool DoublyLinkedList<T>::insertAfter(int pos, T val)
{
  int count = 0;
  ListNode<T>* curr = front;
  while (count != pos)
  {
    curr = curr->next;
    count++;
  }
  ListNode<T>* node = new ListNode<T>(val);
  curr->next->prev = node;
  node->next = curr->next;
  curr->next = node;
  node->prev = curr;
  delete curr;
  return 1;

}
