#include "Course.h"


MyNameSpace::Course::Course(std::string UniName, std::string spec, int course) :Specialization(UniName, spec), course(course) {}
MyNameSpace::Course::Course() {
	course = 0;
}

void MyNameSpace::Course::Show() {
	Specialization::Show();
	std::cout << "Course:  ";
	std::cout << course << std::endl;
}