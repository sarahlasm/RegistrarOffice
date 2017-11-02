#include "ListNode.h"

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
  T removeFront();
  void insertBack(T data);
  T removeBack();
  void printList();
  T remove(T key);
  int find(T value);
  T deletePos(int pos);
  bool insertAfter(int pos, T val); //@TODO
  bool isEmpty();
  unsigned int getSize();
};
