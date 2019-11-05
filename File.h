#include <iostream>
#include <fstream>


using namespace std;

class FileInOut{
  public:
  File(string fileName); //default constructor
  ~File(); //destructor

  void readFile();
  void get_timeList();
  void get_waitingTimeList();

  string filename;
  int num_window;
  int num_student;
  int tine;
  int current_student_num;
  GenDoublyLL *timeList;
  GenDoublyLL *waitingTimeList;
};
