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
  while (true)
  {
    if (currInput == -1)
    {
      getline(inFile, input);
      s = new Student(stoi(input));
      studentQueue->insert(*s);
      currInput = stoi(input);
    }
    if (currTime == currInput)
    {
      currInput = -1;
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
        if (!windows[i].isOccupied)
        {
          windows[i].acceptStudent((studentQueue->remove()));
          break;
        }
      }
      studentQueue->peek().increaseTimeWaited();
    }
    currTime++;
  }
}
