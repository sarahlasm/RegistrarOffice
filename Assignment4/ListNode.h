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
