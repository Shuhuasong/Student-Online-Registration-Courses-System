
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
using namespace std;

#include "MyArray.h"
#include "Instructor.h"
#include "Student.h"
//************************* Course class**************************************
  class Student;
  class Instructor;
  class Course{
  public:
    Course();
    Course(std::string n);
    Course(std::string n, Instructor i);
    std::string getCSName() const;
    void setCSName(std::string n);
    Instructor& getInstructor() const;
    void setInstructor(Instructor& i);
    void addStudent(Student& s); // add a specified student if not already enrolled
    void dropStudent( Student& s); //remove a specified Student (if enrolled)
    void dropInstructor();
    void display() const;


  private:
    std::string name;
    //int capacity{20};
    //int numStudent;
    Instructor *instructor;
    MyArray<Student*> students;
  };

#endif
