//############################# Main Function ###############################


#include "MyArray.h"
#include "Instructor.h"
#include "Student.h"
#include "Course.h"



    int main(){
      std::cout << "*****************************Output**************************" << std::endl;
      Instructor i1("Prof. Sss. Ttt.", "Engineering Technology");
      Instructor i2("Prof. Aaa. Ggg.", "Engineering Technology");
      Instructor i3("Prof. Jjj. Sss.", "Engineering Technology");

      Course c1("ET-580/D2", i1);
      Course c2("ET-575/B4", i2);
      Course c3("ET-574/B2", i3);

      Student s1("Boba Fett");
      Student s2("Zam Wesell");
      Student s3("Qui-Gon Jinn");
      Student s4("Mace Windu");
      Student s5("Kit Fisto");
      Student s6("Barriss Offee");
      Student s7("Eeth Koth");
      Student s8("Count Dooku");
      Student s9("Aayla Secura");

      s1.addCourse(c1);
      s1.addCourse(c3);
      s2.addCourse(c3);
      s3.addCourse(c2);
      s3.addCourse(c3);
      s4.addCourse(c1);
      s5.addCourse(c3);
      s5.addCourse(c1);
      s6.addCourse(c3);
      s6.addCourse(c2);
      s7.addCourse(c1);
      s7.addCourse(c2);
      s7.addCourse(c3);
      s8.addCourse(c1);
      s8.addCourse(c2);
      s9.addCourse(c2);
      s9.addCourse(c3);

      c1.display();
      c2.display();
      c3.display();

      s6.display();
      std::cout << std::endl;
      std::cout <<">>  Dropping " << c2.getCSName() << " for " << s6 << std::endl << std::endl;
      s6.dropCourse(c2);
      s6.display();
      std::cout << std::endl;

      std::cout << ">> Dropping the instructor for " << c2.getCSName() << std::endl;
      c2.dropInstructor();
      c2.display();

      i2.display();
      std::cout << std::endl << std::endl;

      return 0;
    }
