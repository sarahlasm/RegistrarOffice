
/*
  1. The mean student wait time.
  2. The median student wait time.   [maybe a BST??]
  3. The longest student wait time.
  4. The number of students waiting over 10 minutes
  5. The mean window idle time
  6. The longest window idle time
  7. Number of windows idle for over 5 minutes.
*/

//introduce a doubly linked list that keeps track of median/longest

class Statistics
{
  public:
    int totalIdleTime;
    int longestIdleTime;
    int numOverFive;
    int totalStudentWaitTime;
    int longestStudentWaitTime;
    int numOverTen;
    int studentsServed;

    DoublyLinkedList<int> *idle;
    DoublyLinkedList<int> *wait;

    Statistics();
    ~Statistics();
    void takeStudent(Student s);
    void takeIdle(int idle);
    double calculateMean(int times, int total);
    /*void setTotalIdleTime(int t);
    void setNumOverFive(int num);
    void setNumStudents(int num);
    void setNumOverTen(int num);*/
    void printStats();
};

Statistics::Statistics()
{
  idle = new DoublyLinkedList<int>();
  wait = new DoublyLinkedList<int>();
  studentsServed = 0;
  totalStudentWaitTime = 0;
}

Statistics::~Statistics()
{
  cout << "object deleted" << endl;
}

void Statistics::takeStudent(Student s)
{
  studentsServed++;
  totalStudentWaitTime += s.timeWaited;
  if (s.timeWaited > 5)
    numOverFive++;
  //then add this to a list that orders based on value
  if (wait->front == NULL)
  {
    wait->insertFront(s.timeWaited);
  }
  //this is the problem child
  /*else
  {
    while (true)//loop until we make a new node
    {
      ListNode<int> *curr = wait->front;
      if (curr->data <= s.timeWaited)
      {
        if (curr->next == NULL)
        {
          curr->next = new ListNode<int>(s.timeWaited);
          curr->next->prev = curr;
          wait->size++;
          break;
        }
        else
          curr = curr->next;
      }
      else
      {
        if ((curr == wait->front || curr->prev == NULL))
        {
          wait->insertFront(s.timeWaited);
          curr->prev = wait->front;
          break;
        }
        else
          curr = curr->prev;
      }
    }
  }
  cout << "Total wait time " << totalStudentWaitTime << endl;
  //delete &s;*/
}

void Statistics::takeIdle(int idly)
{
  totalIdleTime += idly;
  if (idly > 10)
    numOverTen++;
  //add to idle list//then add this to a list that orders based on value
  if (idle->front == NULL)
  {
    idle->insertFront(idly);
  }
  //this is the problem child
  /*else
  {
    while (true)//loop until we make a new node
    {
      ListNode<int> *curr = wait->front;
      if (curr->data <= idly)
      {
        if (curr->next == NULL)
        {
          curr->next = new ListNode<int>(idly);
          curr->next->prev = curr;
          idle->size++;
          break;
        }
        else
          curr = curr->next;
      }
      else
      {
        if (curr == idle->front || curr->prev == NULL)
        {
          idle->insertFront(idly);
          curr->prev = idle->front;
          break;
        }
        else
          curr = curr->prev;
      }
    }
  }*/
}

double Statistics::calculateMean(int times, int total)
{
  return (double)total/(double)times;
}

void Statistics::printStats()
{

}
