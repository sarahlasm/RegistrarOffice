#include <iostream>

using namespace std;

class Student
{
public:
  Student(int timeN);
  ~Student();
private:
  int timeNeeded;
  int timeWaited;
};

Student::Student(int timeN)
{
  timeNeeded = timeN;
  timeWaited = 0;
}

Student::~Student()
{
  cout << "object deleted";
}
