#include "Student.h"

class Window
{
public:
  Window();
  ~Window();
  int acceptStudent(Student s);
  bool isOccupied;
  Student studentLeaves();
  int idleTime;
  //int timeDone;
  Student* student;
};

Window::Window()
{
  isOccupied = false;
  student = NULL;
  idleTime = 0;
  //timeDone = -1;
}

Window::~Window()
{

}

int Window::acceptStudent(Student s)
{
  student = &s;
  isOccupied = true;
  int temp = idleTime;
  idleTime = 0;
  return temp;
}

Student Window::studentLeaves()
{
  //student = NULL;
  isOccupied = false;
  return *student;
}
