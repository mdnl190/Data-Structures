/*Lab 9a, Associative Array Program
Programmer: Mary Latif
Editor(s) used: Code::Blocks 13.12
Compiler(s) used: GNU GCC Compiler*/
#include "AssociativeArray.h"
#include "AssociativeArray.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
using namespace std;

struct TermSection {
  string term;
  string section;
};

bool operator==(const TermSection& x, const TermSection& y){
  if (x.term == y.term && x.section == y.section) return true;
  return false;
}

int main()
{
  AssociativeArray<string, TermSection> myArray;

  //header
  cout << "Lab 9a, Associative Array Program \nProgrammer: Mary Latif" << endl;
  cout << "Editor(s) used: Code::Blocks 13.12\nCompiler(s) used: GNU GCC Compiler\n" << endl;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  //open file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  for (int i = 0; i < 100 && fin.good(); i++)
  {
      // read the line
      string line;
      getline(fin, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;

      // parse the line
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; // invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));

      TermSection temp = {term, section};
      myArray[temp] = course;
  }
  fin.close();

  //object copy testing
  AssociativeArray<string, TermSection>copy(myArray);
  cout << "Object Copy Testing" << endl;
  cout << "I expect the size of the array to be: " << myArray.size() << endl;
  cout << "\tActual size: " << copy.size() << endl;
  assert(copy.size() == myArray.size());
  cout << "I expect the capacity to be: " << myArray.capacity() << endl;
  cout << "\tActual capacity: " << copy.capacity() << endl;
  assert(copy.capacity() == myArray.capacity());
  cout << "I expect the third key section to be: " << myArray.keys().at(3).section << endl;
  cout << "Actual section: " << copy.keys().at(3).section << endl << endl;
  assert(myArray.keys().at(3).section == copy.keys().at(3).section);

  //object assignment testing
  AssociativeArray<string, TermSection>copy2; copy2 = myArray;
  cout << "Object Assignment Testing" << endl;
  cout << "I expect the size of the array to be: " << myArray.size() << endl;
  cout << "\tActual size: " << copy2.size() << endl;
  assert(copy2.size() == myArray.size());
  cout << "I expect the capacity to be: " << myArray.capacity() << endl;
  cout << "\tActual capacity: " << copy2.capacity() << endl;
  assert(copy2.capacity() == myArray.capacity());
  cout << "I expect the third key section to be: " << myArray.keys().at(3).section << endl;
  cout << "Actual section: " << copy2.keys().at(3).section << endl << endl;
  assert(myArray.keys().at(3).section == copy2.keys().at(3).section);

  //open file
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  for (int i = 0; i < 100 && fin.good(); i++)
  {
      // read the line
      string line;
      getline(fin, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;

      // parse the line
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; // invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));

      TermSection temp = {term, section};
      myArray.deleteKey(temp);
  }
  fin.close();

  //more function testing
  cout << "More Function Testing" << endl;
  cout << "Now I expect the original array to be empty." << endl;
  cout << "\tActual size: " << myArray.size() << endl;
  assert(0 == myArray.size());
  vector<TermSection>index = copy.keys();
  cout << "I expect there the containskey(index[2]) to be true." << endl;
  cout << "\tActual result: ";
  copy.containsKey(index[2]) ? cout << "true" : cout << "false"; cout << endl;
  assert(copy.containsKey(index[2]) == true);
  copy.deleteKey(index[2]);
  cout << "Now I expect there the containskey(index[2]) to be fa;se." << endl;
  cout << "\tActual result: ";
  copy.containsKey(index[2]) ? cout << "true" : cout << "false"; cout << endl;
  assert(copy.containsKey(index[2]) == false);
  cout << "I expect there to be a value at {" << index[2].term << ", " << index[2]. section << "}" << endl;
  cout << "\tActual Result: " << copy[index[2]] << endl;
  assert (!copy[index[2]].empty());
  copy.clear();
  cout << "After clearing the copy array, I expect it to be empty." << endl;
  cout << "\tActual size: " << copy.size() << endl;
  assert(0 == copy.size());
}
