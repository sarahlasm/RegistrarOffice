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
#include "Statistics.h"
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
  Window *windows = new Window(numWindows);
  Student *s;
  Statistics stats = new Statistics();
  int currInput = -1; //currInput tracks the next clock tick at which more students will arive
  while (true)
  {
    if (currInput == -1) //beginning
    {
      getline(inFile, input);
      /*s = new Student(stoi(input));
      studentQueue->insert(*s);*/ //if the next tick is 1, this will make a student object with wait time 1.
      currInput = stoi(input);
    }
    if (currTime == currInput) //hits 1
    {
      //currInput = -1;
      getline(inFile, input);
      for (int i = 0; i < stoi(input); ++i)
      {
        getline(inFile, input);
        Student* s = new Student(stoi(input));
        s.timeNeeded += currInput;
        for (int j = 0; j < numWindows; ++j)
        {
          if (!windows[j].isOccupied)
          {
            stats.takeIdle(windows[j].acceptStudent(s));
          }
          else
            studentQueue->insert(*s);
        }
        delete &s; //necessary to get rid of this student object?
      }
    }
    while (!studentQueue->isEmpty())
    {

      for (int i = 0; i < numWindows; ++i)
      {
        if (windows[i].timeNeeded == currTime)
        {
          stats.takeStudent(windows[i].studentLeaves());
        }
        if (!windows[i].isOccupied)
        {
          stats.takeIdle(windows[i].acceptStudent((studentQueue->remove())));
          break;
        }
      }
      while(studentQueue->peek() != NULL) //this doesn't catch the last one though i dont think
      {
        studentQueue->peek().increaseTimeWaited();
      }
    }
    currTime++;
  }
}
