
  #include "Course.h"

//************************** Course Class Implementation ********************

     Course::Course(): Course(" "){}
     Course::Course(std::string n): name(n) {}
     Course::Course(std::string n, Instructor i): name(n), students(MyArray<Student*>()){ instructor = &i; }
     std::string Course::getCSName() const { return name; }
     void Course::setCSName(std::string n) { name = n;}
     Instructor& Course::getInstructor() const { return *instructor; }
     void Course::setInstructor(Instructor& i) { *instructor = i;}

     void Course::addStudent(Student& s) { // add a specified student if not already enrolled
        // std::cout << " Course AddStudent Called!!" << std::endl;
       int index = students.getIndex(&s);
       if(index==-1){
         students.push_back(&s);
       }
     }

     void Course::dropStudent(Student& s){  //remove a specified Student (if enrolled)
        //  std::cout << " Course dropStudent Called!!" << std::endl;
       int index = students.getIndex(&s);
       if(index!=-1){
         students.erase(index);
       }else{
         std::cout << " The student is not exist " << std::endl;
         return;
       }
     }

     void Course::dropInstructor(){
      // std::cout << " Course dropInstructor Called!!" << std::endl;
         if(instructor->getInsName()!= "staff"){
            instructor->dropCourse(*this);   //????
            instructor = new Instructor();
         }
     }

     void Course::display() const {
       std::cout << "--------------------------------------------------------------"<< std::endl;
       std::cout << "--------------------------------------------------------------"<< std::endl;

       std::cout << name << " - " << instructor->getInsName() << std::endl;
       for(int i=0; i<students.getSize(); i++){
         std::cout << i+1 << " : " << students[i]->getStuName() << " "<< std::endl;
       }
     }
