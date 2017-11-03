/**
@TODO
  - Keep track of all the data we need to.
  - Perform data analysis at the end.
  - Fix destructors.
  - Do students ever leave when they're done?
*/

#include "Queue.h"
#include "Window.h"
#include "Statistics.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
allWindowsEmpty
Returns true if all windows are empty
*/
bool allWindowsEmpty(Window windows[], int numWindows)
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i].isOccupied)
      return false;
  }
  return true;
}

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
  Statistics* stats = new Statistics();
  bool nextTimeSelected = false;
  int currInput = -1; //currInput tracks the next clock tick at which more students will arive
  while (true)
  {
    if (currInput != currTime && !nextTimeSelected) //beginning
    {
      nextTimeSelected = true;
      if (getline(inFile, input))
      {
      /*s = new Student(stoi(input));
      studentQueue->insert(*s);*/ //if the next tick is 1, this will make a student object with wait time 1.
        currInput = stoi(input);
      //  cout << currInput;
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
        currTime++;
        break;
      }
      else return 0;
    }
    if (currTime == currInput) //hits 1
    {
      nextTimeSelected = false;
      //currInput = -1;
      if (getline(inFile, input))
      {
        string studentInput;
        for (int i = 0; i < stoi(input); ++i)
        {
          getline(inFile, studentInput);
          Student* s = new Student(stoi(studentInput), stoi(input));
          s->timeNeeded += currInput;
          for (int j = 0; j <= numWindows; ++j)
          {
            cout << j << " " << endl;
            if (j == numWindows)
            {
              cout << "The time is " << currTime << " and a new student is waiting in line.\n";
              studentQueue->insert(*s);
              break;
            }
            if (!windows[j].isOccupied)
            {
              cout << "The time is " << currTime << " and the student has gone to window " << j << endl;
              studentQueue->insert(*s);
              studentQueue->peek().setTimeWaited(currTime - studentQueue->peek().timeEntered);
              stats->takeIdle(windows[j].acceptStudent(studentQueue->remove()));
              break;
            }
          }
        }
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
        currTime++;
        break;
      }
      else return 0;
    }
    while (!studentQueue->isEmpty())
    {

      for (int i = 0; i < numWindows; ++i)
      {
        //Student's time runs out, this is definitely sloppy
        if (windows[i].student->timeNeeded == currTime)
        {
          stats->takeStudent(windows[i].studentLeaves());
        }
        if (!windows[i].isOccupied)
        {
          stats->takeIdle(windows[i].acceptStudent((studentQueue->remove())));
          break;
        }
      }
    }
    currTime++;
    cout << "I've reached the end of the loop! Hooray! xoxo\n";
  }
}
