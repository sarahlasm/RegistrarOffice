#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int timeN);
  ~Student();
  void increaseTimeWaited();
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
  cout << "object deleted";
}

void Student::increaseTimeWaited()
{
  timeWaited++;
}
