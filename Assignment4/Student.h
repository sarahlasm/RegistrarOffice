#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int timeN);
  ~Student();
  void increaseTimeWaited();
  int getTimeNeeded();
  int getTimeWaited();
  int timeNeeded;
  int timeWaited;
};

Student::Student()
{
  timeNeeded = 0;
  timeWaited = 0;
}

Student::Student(int timeN)
{
  timeNeeded = timeN;
  timeWaited = 0;
}

Student::~Student()
{
}

void Student::increaseTimeWaited()
{
  timeWaited++;
}

int Student::getTimeNeeded()
{
  return timeNeeded;
}

int Student::getTimeWaited()
{
  return timeWaited;
}
