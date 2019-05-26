
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <iomanip>

#include "MyArray.h"
#include "Course.h"

using namespace std;

//************************* Instructor class**************************************
class Course;
class Instructor{
public:
  Instructor();
  Instructor(std::string n);
  Instructor(std::string n, std::string d);
  std::string getInsName() const;
  void setInsName(std::string n);
  std::string getDepartment() const;
  void setDepartment(std::string d);

  void addCourse(Course& c);//add a specified course(is not already added)
  void dropCourse(Course& c); //remove a specified course (if teaching course)
  void display() const;  // display the instructor name, departmetn, and list of Course
private:
  std::string name; //Full name + title
  std::string department;
  MyArray<Course*> courses; //MyArray Object which stores course object pointer
};

#endif
