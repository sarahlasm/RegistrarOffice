
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

    DoublyLinkedList<int> *wait;

    Statistics();
    ~Statistics();
    void takeStudent(Student s);
    void takeIdle(int idle);
    double calculateMean(int times, int total);
    void increaseTotalWait(int t);
    void increaseTotalIdle(int t);
    /*void setTotalIdleTime(int t);
    void setNumOverFive(int num);
    void setNumStudents(int num);
    void setNumOverTen(int num);*/
    void printStats();
};

Statistics::Statistics()
{
  wait = new DoublyLinkedList<int>();
  studentsServed = 0;
  totalStudentWaitTime = 0;
  totalIdleTime = 0;
  longestIdleTime = 0;
  longestStudentWaitTime = 0;
}

Statistics::~Statistics()
{
  cout << "object deleted" << endl;
}

void Statistics::takeStudent(Student s)
{
  studentsServed++;
  cout << "This student had waited: " << s.timeWaited << endl;
  increaseTotalWait(s.timeWaited);
  if (s.timeWaited > 5)
    numOverFive++;
  if (s.timeWaited > longestStudentWaitTime)
    longestStudentWaitTime = s.timeWaited;
  //then add this to a list that orders based on value
  wait->insertFront(s.timeWaited);
  cout << "Line 67" << endl;
  /*if (wait->front == NULL)
  {
    wait->insertFront(s.timeWaited);
    cout << "Line 68\n";
  }
  //this is the problem child
  /*else
  {
    ListNode<int> *node = new ListNode<int>(s.timeWaited);
    wait->insertFront(s.timeWaited
    /*while (true)//loop until we make a new node
    {
      ListNode<int> *curr = wait->front;
      ListNode<int> *node = new ListNode<int>(s.timeWaited);
      /*if (curr->data <= node->data)
      {
        cout << "if0\n";
        if (curr->next == NULL || curr->next == front)
        {
          cout << "if1\n";
          ListNode<int> *node = new ListNode<int>(s.timeWaited);
          curr->next = node;
          node->prev = curr;
          wait->size++;
          break;
        }
        else
        {
          cout << "else\n";
          curr = curr->next;
        }
      }
      else
      {
        cout << "if2\n";
        if (curr == wait->front || curr->prev == NULL)
        {
          cout << "if3\n";
          wait->insertFront(s.timeWaited);
          curr->prev = wait->front;
          break;
        }
        else
          curr = curr->prev;
      }
    }
  }*/
  cout << "Total wait time " << totalStudentWaitTime << endl;
  //delete &s;
}

void Statistics::takeIdle(int idly)
{
  increaseTotalIdle(idly);
  if (idly > 10)
    numOverTen++;
  if (longestIdleTime < idly)
    longestIdleTime = idly;
}

void Statistics::increaseTotalIdle(int t)
{
  totalIdleTime += t;
}

void Statistics::increaseTotalWait(int t)
{
  totalStudentWaitTime += t;
}

double Statistics::calculateMean(int times, int total)
{
  return (double)total/(double)times;
}

void Statistics::printStats()
{
  cout << "STATISTICS: " << endl;
  cout << "Median student wait time" << endl;
  cout << "Longest student wait time: " << longestStudentWaitTime << endl;
  cout << "Mean student wait time: " << calculateMean(studentsServed, totalStudentWaitTime) << endl;
  cout << "Number of students waiting over 10 minutes: " << numOverTen << endl;
  cout << "Longest idle time: " << longestIdleTime << endl;
  cout << "Mean idle time: "; //FIND NUM windows
  cout << "Number of windows idle over 5 minutes: " << numOverFive << endl;
}
