
#include "Instructor.h"


//************************** Instructor Class Implementation ********************

Instructor::Instructor(): Instructor("staff"){ }
Instructor::Instructor(std::string n): name(n){ }
Instructor::Instructor(std::string n, std::string d): name(n), department(d),courses(MyArray<Course*>()){ }
std::string Instructor::getInsName() const {return name;}
void Instructor::setInsName(std::string n) { name = n;}
std::string Instructor::getDepartment() const { return department;}
void Instructor::setDepartment(std::string d) { department = d;}

void Instructor::addCourse(Course& c) { //add a specified course(is not already added)
    //std::cout << " Instructor addCourse Called!!" << std::endl;
  int index = courses.getIndex(&c);
  if(index==-1){
    courses.push_back(&c);
  }else{
    return;
  }

}

void Instructor::dropCourse(Course& c) {
  //  std::cout << " Instructor dropCourse Called!!" << std::endl;
    int index = courses.getIndex(&c);
    if(index==-1){
      std::cout << " **The course is not exist!! " << std::endl;
      return;
  }else{
    courses.erase(index);
    c.dropInstructor( );
  }
}

void Instructor::display() const {
  std::cout << name << "  " << department << std::endl;
  for(int i=0; i<courses.getSize(); i++){
    std::cout << courses[i]->getCSName() << " ";
  }
  std::cout << std::endl;
}
