#include "DoubleListNode.h"

template <class T>
class Queue
{
public:
    Queue(int maxSize);
    ~Queue();
    void insert(T data);
    T remove();
    T peek();

    bool isFull();
    bool isEmpty();

    int head;
    int tail;
    int max;

    int numElements;

    unsigned int getSize();

    DoublyLinkedList<T>* myQueue;
};

template <class T>
Queue<T>::Queue(int maxSize)
{
  max = maxSize;
  head = 0;
  tail = -1;
  numElements = 0;
  myQueue = new DoublyLinkedList<T>();
}

template <class T>
Queue<T>::~Queue()
{
  delete myQueue;
}

template <class T>
void Queue<T>::insert(T data )
{
  if (!isFull())
  {
    myQueue->insertAfter(tail++, data);
    if (tail == max && *(myQueue->front->data) == NULL)
      tail = -1;
  }
  else
    cerr << "Your queue is full. You cannot add more.\n";
}

template <class T>
T Queue<T>::remove()
{
  if (!isEmpty())
  {
    T temp = head;
    ++head;
    --numElements;
    return temp;
    if (head == max && myQueue->front->data == NULL)
      head = 0;
  }
  else
    cerr << "Your queue is empty. You cannot remove more.\n";
}

template <class T>
T Queue<T>::peek()
{
  return head;
}

template <class T>
bool Queue<T>::isFull()
{
  return numElements == max;
}

template <class T>
bool Queue<T>::isEmpty()
{
  return numElements == 0;
}
