/*
  1. The mean student wait time.
  2. The median student wait time.   [maybe a BST??]
  3. The longest student wait time.
  4. The number of students waiting over 10 minutes
  5. The mean window idle time
  6. The longest window idle time
  7. Number of windows idle for over 5 minutes.
*/

class stats
{
  public:
    int totalIdleTime;
    int longestIdleTime;
    int numOverFive;
    int totalStudentWaitTime;
    int longestStudentWaitTime;
    int numOverTen;
    int studentsServed;
    int totalStudents;

    double calculateMeanStudWait(int times, int total);
    double calculateMeanWindowIdle(int times, int total);
    /*void setTotalIdleTime(int t);
    void setNumOverFive(int num);
    void setNumStudents(int num);
    void setNumOverTen(int num);*/
    void printStats();
};

double stats::calculateMeanStudWait(int times, int total)
{

}

double stats::calculateMeanWindowIdle(int times, int total)
{

}

/*void setTotalIdleTime(int t)
{
  totalIdleTime = t;
}

void setNumOverFive(int num)
{
  numOverFive = num;
}

void setNumOverTen(int num)
{
  numOverTen = num;
}

void setNumStudents(int num)
{
  totalStudents = num;
}*/

void stats::printStats()
{

}
