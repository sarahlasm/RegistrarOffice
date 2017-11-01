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
private:
  Student* student;
};

Window::Window()
{
  isOccupied = false;
  student = NULL;
  idleTime = 0;
}

Window::~Window()
{

}

void Window::acceptStudent(Student s)
{
  student = &s;
  isOccupied = true;
}

void Window::studentLeaves()
{
  student = NULL;
  isOccupied = false;
}
