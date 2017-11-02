#include "Student.h"

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

    DoublyLinkedList<int> *idle = new DoublyLinkedList<int>();
    DoublyLinkedList<int> *wait = new DoublyLinkedList<int>();

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

void takeStudent(Student s)
{
  ++Statistics::studentsServed;
  Statistics::totalStudentWaitTime += s.timeWaited;
  if (s.timeWaited > 5)
    Statistics::numOverFive++;
  //then add this to a list that orders based on value
  delete &s;
}

void takeIdle(int idle)
{
  Statistics::totalIdleTime ++ idle;
  if (idle > 10)
    Statistics::numOverTen++;
  //add to idle list
}

double Statistics::calculateMeanStudWait(int times, int total)
{

}

double Statistics::calculateMeanWindowIdle(int times, int total)
{

}

void Statistics::printStats()
{

}
