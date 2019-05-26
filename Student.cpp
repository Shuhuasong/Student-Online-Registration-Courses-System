
#include "Student.h"

//************************** Student Class Implementation ********************

  Student::Student(): Student(" "){  }
  Student::Student(std::string n): fullname(n),courses(MyArray<Course*>()){ }

  std::string Student::getStuName() const{
    return fullname;
  }
  void Student::setStuName(std::string n){
    fullname = n;
  }

  void Student::addCourse(Course& c) { //add a specified course(is not already added)
    //  std::cout << " Student addcourse Called!!" << std::endl;
    int index = courses.getIndex(&c);
    if(index==-1){
      courses.push_back(&c);
      c.addStudent(*this);
    }else{
      return;
    }

  }

  void Student::dropCourse(Course& c) {
    //  std::cout << " Student dropCourse Called!!" << std::endl;
      int index = courses.getIndex(&c);
      if(index!=-1){
        courses.erase(index);
        c.dropStudent(*this);
      }else{
        std::cout<< " This course is not exit! " << std::endl;
        return;
      }
  }

  /*void Student::dropCourse(const Course& c) {  //what is difference between these two methods
    if(c.getCSName()!= " "){
       c = Course();   //????
       c.dropStudent(this);
    }
  }  */


  /*void Student::removeGrade(int index){
    //int index = grades.getIndex(g);
    for(int i=index; i<numgrade;i++){
      grades.data[i] = grades.data[i+1];
    }
    numgrade--;
  }*/


  void Student::display() const{
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << " Student: "<< fullname << " " << std::endl;
    std::cout << " Courses: ";
    for(int i=0; i<courses.getSize(); i++){
      std::cout << courses[i]->getCSName() << "  ";
    }
    std::cout << std::endl;
  }

   std::ostream& operator <<(std::ostream& outstream, const Student& s){
     outstream << " " << s.fullname << std::endl;
     return outstream;
   }
