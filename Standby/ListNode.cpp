#include "ListNode.h"

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
