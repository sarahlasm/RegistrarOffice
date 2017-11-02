#include "Student.h"

class Window
{
public:
  Window();
  ~Window();
  void acceptStudent(Student s);
  bool isOccupied;
  void studentLeaves();
  int idleTime;
  int timeDone;
private:
  Student* student;
};

Window::Window()
{
  isOccupied = false;
  student = NULL;
  idleTime = 0;
  timeDone = -1;
}

Window::~Window()
{

}

void Window::acceptStudent(Student s)
{
  student = &s;
  isOccupied = true;
  timeDone = s->timeNeeded;
}

void Window::studentLeaves()
{
  delete student;
  student = NULL;
  isOccupied = false;
}
