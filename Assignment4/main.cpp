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
  Queue<Student> studentQueue(20);// = new Queue<Student>(20);
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
    cout << "Top of the looop\n";
    if (currInput != currTime && !nextTimeSelected) //beginning
    {
      cout << "if1\n";
      nextTimeSelected = true;
      if (getline(inFile, input))
      {
        currInput = stoi(input);
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
    //    currTime++;
      }
      else return 0;
    }
    else if (currTime == currInput) //hits 1
    {
      cout << "if2\n";
      nextTimeSelected = false;
      //currInput = -1;
      if (getline(inFile, input))
      {
        string studentInput;
        for (int i = 0; i < stoi(input); ++i)
        {
          getline(inFile, studentInput);
          Student s(stoi(studentInput), stoi(input));

          for (int j = 0; j <= numWindows; ++j)
          {
            if (j == numWindows)
            {
              cout << "The time is " << currTime << " and a new student is waiting in line.\n";
              studentQueue.insert(s);
              break;
            }
            if (!windows[j].isOccupied)
            {
              cout << "The time is " << currTime << " and the student has gone to window " << j << endl;
              s.setTimeServed(currTime);
              s.setTimeWaited(currTime - s.timeEntered);
              studentQueue.insert(s);
              //windows[j].acceptStudent(studentQueue.remove());
              stats->takeIdle(windows[j].acceptStudent(studentQueue.remove()));
              break;
            }
          }
        }
      }
      else if (!allWindowsEmpty(windows, numWindows))
      {
        cout << "if3\n";
        currTime++;
        break;
      }
      else
      {
        cout << "Cake";
        return 0;

      }

    }
    if (currTime == 20) return -1;
    for (int i = 0; i < numWindows; ++i)
    {
      cout << "Is it time for the student to go? " << (windows[i].student.timeNeeded + windows[i].student.timeServed == currTime) << endl;
      //Student's time runs out, this is definitely sloppy
      if (windows[i].isOccupied && windows[i].student.timeNeeded + windows[i].student.timeServed == currTime)
      {
        /*stats->takeStudent(*/windows[i].studentLeaves(); //@TODO
        cout << "The time is " << currTime << " and a student has just left window " << i << endl;
      }
      if (!windows[i].isOccupied && !studentQueue.isEmpty())
      {
        stats->takeIdle(windows[i].acceptStudent((studentQueue.remove())));
      }
    }
    cout << "This is the end of time " << currTime << endl;

    currTime++;
  }
}
