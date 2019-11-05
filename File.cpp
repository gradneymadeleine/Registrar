#include "File.h"
#include <fstream>
#include <iostream>

using namespace std;

File::File(string fileName)
{
  filename = fileName;
  num_window = 0;
  num_student = 0;
  time = -1;
  current_student_num = 0;
  is_time = true;
  is_student_num = false;
  is_waiting_time = false;
}

File::~File()
{

}

void File::readFile()
{
  ifstream inFile;
  char c;           //each cahr in each string
  string line = ""; //declare a string variable for each line of teh file

  if (!inFile)
  {
      cout << "there are some problems.";
      exit(1); //if the file is not there, return an error
  }

  inFile.open(filename);//open the file
  getline(inFile, line);
  num_window = stoi(line);

  while(getline(inFile, line)) //while there is a line in the file
  {
    int temp_num;
    temp_num = stoi(line);

    if(is_time)
    {
      time = temp_num;
      timeList.insertBack(time);
      is_time = false;
      is_student_num = true;
    }
    else if(is_student_num)
    {
      num_student += temp_num;
      current_student_num = temp_num;
      is_student_num = false;
      is_waiting_time = true;
    }
    else if(is_waiting_time)
    {
      waitingTimeList.insertBack(temp_num);
      --current_student_num;
      if(current_student_num == 0)
      {
        is_waiting_time = false;
        is_time = true;
      }
    }
  }
}

void File::get_timeList()
{
  for(int i : timeList)
  {
    cout << "time: " << i << endl;
  }
}

void File::get_waitingTimeList()
{
  for(int i : waitingTimeList)
  {
    cout << "waiting time: " << i << endl;
  }
}
