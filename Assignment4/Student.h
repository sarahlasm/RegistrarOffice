#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int timeN, int timeE);
  ~Student();
  void setTimeWaited(int timeW);
  int timeNeeded;
  int timeWaited;
  int timeEntered;
};

Student::Student()
{
  timeNeeded = 0;
  timeWaited = 0;
}

Student::Student(int timeN, int timeE)
{
  timeNeeded = timeN;
  timeWaited = 0;
  timeEntered = timeE;
}

Student::~Student()
{
}

void Student::setTimeWaited(int timeW)
{
  timeWaited = timeW;
}
