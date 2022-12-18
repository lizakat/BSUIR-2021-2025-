#include "Specialization.h"

MyNameSpace::Specialization::Specialization(std::string UniName, std::string spec) :University(UniName), spec(spec) {}
MyNameSpace::Specialization::Specialization() {
	spec = "";
}
MyNameSpace::Specialization::~Specialization() {
	spec.clear();
}
void MyNameSpace::Specialization::Show() {
	std::cout << "University:  ";
	University::Show();
	std::cout << "Specialization:  ";
	std::cout << spec << std::endl;
}