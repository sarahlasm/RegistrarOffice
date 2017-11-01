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
  while (getline(inFile, input))
  {
    currTime = stoi(input);
    getline(inFile, input);
    for (int i = 0; i < stoi(input); ++i)
    {
      getline(inFile, input);
      s = new Student(stoi(input));
      studentQueue->insert(*s);
    }
    while (!studentQueue->isEmpty())
    {
      for (int i = 0; i < numWindows; ++i)
      {
        if (!windows[i].isOccupied)
        {
<<<<<<< HEAD
          windows[i].acceptStudent(s);
=======
          windows[i].acceptStudent((studentQueue->remove()));
>>>>>>> b331baa5ba2285a0f70f2b52bf0166877ddaef6c
          break;
        }
      }
    }

  }
}
