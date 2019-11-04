#include <iostream>
#include <fstream>


using namespace std;

class FileInOut{
public:
  File(); //default constructor
  ~File(); //destructor

  void openFile(string path); //open ifstream
  void closeFile(); //close ifstream
  string readLine(); //reads readLine

  void openOutFile(string path); //open ofstream
  void closeOutFile(); //close ofstream
  void writeLine(string s); //write a line into the file
  void write(string s);


  ifstream in;
  ofstream out;
