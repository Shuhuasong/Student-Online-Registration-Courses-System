# variables
CXXFLAGS := -std=c++11

# executable file to create and its dependancies
prog.exe : driver.o Instructor.o Student.o Course.o
	g++ -std=c++11 -o prog driver.o Instructor.o Student.o Course.o

# file dependencies
driver.o : MyArray.h Instructor.h Student.h Course.h
	g++ -std=c++11 -c driver.cpp
Instructor.o : MyArray.h Course.h
	g++ -std=c++11 -c Instructor.cpp
Student.o : MyArray.h Student.h
	g++ -std=c++11 -c Student.cpp
Course.o :  Student.h Course.h
 	g++ -std=c++11 -c Course.cpp

# files to remove
clean:
	rm driver.o Instructor.o Student.o Course.o
	rm prog
