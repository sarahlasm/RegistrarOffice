/**
@TODO
  - Fix compiler error
  - Currently, only the first student in line has their timeWaited increased when they are forced to
    wait. Ensure others have theirs updated too.
  - Keep track of all the data we need to.
  - Perform data analysis at the end.
  - Fix destructors.
*/

#include "Queue.h"
#include "Window.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    cout << "You must run this program with a command-line file name.\n";
    return -1;
  }
  string fileName = argv[1];
  string input;
  ifstream inFile(fileName);
  Queue<Student>* studentQueue = new Queue<Student>(20);
  getline(inFile, input);
  int numWindows = stoi(input);
  int currTime = 0;
  Window *windows = new Window[numWindows];
  Student *s;
  int currInput = -1; //currInput tracks the next clock tick at which more students will arive
  int totalIdleTime = 0;
  int longestIdleTime = 0;
  int numOverFive = 0;
  int totalStudentWaitTime = 0;
  int longestStudentWaitTime = 0;
  int numOverTen = 0;
  int studentsServed = 0;
  while (true)
  {
    if (currInput == -1)
    {
      getline(inFile, input);
      /*s = new Student(stoi(input));
      studentQueue->insert(*s);*/ //if the next tick is 1, this will make a student object with wait time 1.
      currInput = stoi(input);
    }
    if (currTime == currInput)
    {
      //currInput = -1;
      getline(inFile, input);
      for (int i = 0; i < stoi(input); ++i)
      {
        getline(inFile, input);
        Student* s = new Student(stoi(input));
        studentQueue->insert(*s);
      }
    }
    while (!studentQueue->isEmpty())
    {
      for (int i = 0; i < numWindows; ++i)
      {
        if (windows[i].timeDone == currTime)
        {
          windows[i].studentLeaves();
          windows[i].idleTime = 0;
          windows[i].timeDone = -1;
        }
        if (!windows[i].isOccupied)
        {
          windows[i].acceptStudent((studentQueue->peek()));
          windows[i].timeDone = (studentQueue->peek().timeNeeded) + currTime;
          totalIdleTime += windows[i].idleTime;
          totalStudentWaitTime += ((studentQueue->remove()).timeWaited);
          studentsServed++;
          break;
        }
      }
      studentQueue->peek().increaseTimeWaited();
    }
    currTime++;
  }
}
