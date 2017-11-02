#include "Student.h"

class Window
{
/*public:
  Window();
  Window(int n);
  ~Window();
  void acceptStudent(Student s);
  //bool isOccupied;
  void studentLeaves(int currTime, int currInput);
  int idleTime;
  //int timeDone;  //what is timeDone?
  int totalWindows;
  Student *windows;
  bool getIsFull();
private:
  Student* student;
  bool isFull;*/
};

Window::Window()
{
  //isOccupied = false;
  //student = NULL;
  idleTime = 0;
  timeDone = -1;
  totalWindows = 0;
  isFull = false;
}

Window::Window(int n)
{
  windows = new Student[n];
  totalWindows = n;
  isFull = false;
  //isOccupied = false;
  //student = NULL;
  //idleTime = 0;
  //timeDone = -1;
}


Window::~Window()
{

}

void Window::acceptStudent(Student s)
{
  student = &s;
  for (int i = 0; i < totalWindows; ++i)
  {
    if (windows[i] == NULL)
    {
      windows[i] = student;
    }
    if (windows[totalWindows - 1 != NULL])
    {
      isFull = true;
    }
  }
  if (isFull)
  {
    //push into queue
  }
  //timeDone = s->timeNeeded;
}

Student Window::studentLeaves(int currTime, int currInput)
{
  for (int i = 0; i < totalWindows; ++i)
  {
    if (windows[i].timeNeeded == (currTime - currInput))
    {
      return Student;
    }
  /*delete student;
  student = NULL;
  isFull = false;*/
}
