
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
using namespace std;

#include "MyArray.h"
#include "Course.h"


//************************* Student class**************************************
    class Course;
    class Student{
    public:
      Student();
      Student(std::string n);
      std::string getStuName() const;
      void setStuName(std::string n);
      //double getGPA() const;
      void addCourse(Course& c); // add a specifed Course(if not already added)
      void dropCourse(Course& c);  //remove a specified Course (if enrolled in course)
      void display() const;  //display the Student name and a list of courses, use the overloaded [] operator from MyArray

      friend std::ostream& operator <<(std::ostream& outstream, const Student& s);
    private:
      std::string fullname;
      MyArray<Course*> courses;
    };


#endif
