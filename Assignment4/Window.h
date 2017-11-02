#include "Student.h"

using namespace std;

/*
  This class holds Student objects until time is up then passes them to statistics.
  If the window is empty it will count up its own idle time.
  Once the window is filled it will send its idle time to Statistics.

*/
class Window
{
  public:
    Window();
    ~Window();
    int acceptStudent(Student s);
    Student removeStudent();

    bool isOccupied;
    Student *s;
    int idleTime;

};

Window::Window()
{
  isOccupied = false;
  s = NULL;
  idleTime = 0;
}

Window::~Window()
{

}

int Window::acceptStudent(Student stud)
{
  s = stud;
  isOccupied = true;
  int temp = idleTime;
  idleTime = 0;
  return temp;
}

Student Window::removeStudent()
{
  Student *stud = &s;
  delete s;
  s = NULL;
  isOccupied = false;
  return stud;
}
