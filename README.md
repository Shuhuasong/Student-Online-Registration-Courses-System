# Student-Online-Registration-Courses-System
# Aggregation Object-Oriented Design
Template + Operator Overloaded + Inheritance(aggregation)+ Separate Compilation+ Pointer Dynamic Array
Overview
1) Implement the following files using separate compilation:
MyArray.h
Student.cpp
Student.h
Instructor.cpp
Instructor.h
Course.cpp
Course.h
driver.cpp
makefile
2) Your submission must automatically compile from the makefile.
3) Remove any refences to using namespace std from your project. Use the
std:: prefix for all cin, cout, string and endl commands (std::cout).
Additionally, stream objects such as ostream, istream etc. must also
be prefaced with std::.
4. Use the included driver.cpp file.

Aggregation Object-Oriented Design (class details on following pages)
The Instructor, Student and Course classes interact with each other to form
a simple object-oriented database via aggregation. This means that each class
will store objects of the other two via pointers so that all objects have
independent lifetimes. Thus, a Student will continue to exist whether they
add or drop a Course, and a Course would continue to exist whether or not the
Student takes it or drops it.
For example, a Course will have a pointer to an Instructor object and a
MyArray object of pointers to Student objects. A Student will have a MyArray
object of pointers to Course objects. Finally, an Instructor will have a
MyArray object of pointers to Course objects.
Each class will have the ability to add or remove a relationship with other
classes. For example, a Student can drop a Course before the drop date, or a
Course can drop a Student (automated process due to lack of attendance). In
practice it may not make sense for a Course to add a Student. However, a
Course must provide an add Student function so that a Student object can use
this function to add itself to the Course object, and so on.


Forward Declarations
Due to the circular OOP design of this project (Students must be aware of
Courses at the same time that Courses must be aware of Students etc.) you
must forward declare your Instructor, Student and Course classes.
For example, if the definition of class A includes references to B objects
and/or B functions, and the definition of class B includes references to A
objects and/or A functions we must do the following in their respective .h
files:
// A.h file
#include “B.h” // include the B.h file
class B; // forward declaration of B
class A {
};
// B.h file
#include “A.h” // include the A.h file
class A; // forward declaration of A
class B {
};


Class Specifics
MyArray Template Class
This is a safe, partially filled dynamic array template class that must be
declared and defined in a single MyArray.h file (no MyArray.cpp file).
All functions of this class should handle any possible errors that may occur
when interacting with an array. For example, a constructor should not attempt
to create an array of a negative size.
1) data members:
a) data - dynamic array of type T
- plus any other necessary array management variables
2) constructors:
a) default - create an empty array of capacity 10
b) single parameter - create an array of a specified capacity
3) functions:
a) getSize - return the number of elements in the array
b) grow - private grow function (capacity*2)+1
c) getIndex - given a value, return the position or -1 if not found.
d) push_back - add element to the end of the array
e) erase - remove the element at the specified index
f) [] - overloaded [] operator:
accept an index as input, return the element if it exists
4) the big three

Instructor Class
1) data members:
a) name - full name of the Instructor (with title)
b) department - name of the Instructor’s department
b) courses - MyArray object which stores course object pointers
2) constructors:
a) default - create an anonymous Instructor (set name to Staff)
b) single parameter - create an Instructor with name
c) dual parameter - create an Instructor with name and department
3) functions:
a) getName - accessor for name
b) setName - mutator for name
c) getDepartment - accessor for department
d) setDepartment - mutator for department
d) addCourse - add a specified Course (if not already added),
update the Course object to reflect the change
e) dropCourse - remove a specified Course (if teaching course)
update the Course object to reflect the change
f) display - displays the Instructor name, department
and list of Courses


Student Class
1) data members:
a) name - full name of the Student
b) courses - MyArray object which stores Course object pointers
2) constructors:
a) default - create an anonymous Student
b) single parameter - create a Student with a specified name
3) functions:
a) getName - accessor for name
b) setName - mutator for name
d) addCourse - add a specified Course (if not already added),
update the Course object to reflect the change
e) dropCourse - remove a specified Course (if enrolled in course)
update the Course object to reflect the change
f) display - display the Student name and a list of courses,
use the overloaded [] operator from MyArray
g) << - overloaded << operator displays the Student name


Course Class
1) data members:
a) name - Course number/section
b) instructor - Instructor object pointer
b) students - MyArray object which stores Student object pointers
2) constructors:
a) default - create an anonymous Instructor
b) dual parameter - create a course with a name and Instructor
3) functions:
a) getName - accessor for name
b) setName - mutator for name
c) getInstructor - accessor for Instructor, return Instructor object
d) setInstructor - setter for Instructor, accept Instructor object
e) addStudent - add a specified Student (if not already enrolled)
update the Student object to reflect the change
f) dropStudent - remove a specified Student (if enrolled)
update the Student object to reflect the change
g) dropInstructor - replace current Instructor with Staff,
use the default Instructor constructor
update the Instructor object to reflect the change
g) display - display the Instructor name,
use the overloaded << operator from Student
display a list of Courses,
use the overloaded [] operator from MyArray

