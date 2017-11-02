
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
    double calculateMeanStudWait(int times, int total);
    double calculateMeanWindowIdle(int times, int total);
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
  else
  {
    ListNode<int> *curr = wait->front;
    while(true)
    {
      if (curr->data <= s.timeWaited)
      {
        curr->next = new ListNode<int>(s.timeWaited);
        curr = curr->next;
      }
      else if (curr->data > s.timeWaited)
      {
        if (curr == wait->front)
        {

        }
      }
    }
  }
  delete &s;
}

void Statistics::takeIdle(int idle)
{
  totalIdleTime += idle;
  if (idle > 10)
    numOverTen++;
  //add to idle list
}

double Statistics::calculateMeanStudWait(int times, int total)
{
  return 0; //so it compiles
}

double Statistics::calculateMeanWindowIdle(int times, int total)
{
  return 0; //so it compiles
}

void Statistics::printStats()
{

}
