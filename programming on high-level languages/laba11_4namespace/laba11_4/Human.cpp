#include "Human.h"


MyNameSpace::Human::Human(std::string name, std::string surname) : name(name), surname(surname) {}
MyNameSpace::Human::Human() {
	name = "";
	surname = "";
}
MyNameSpace::Human::~Human() {
	name.clear();
	surname.clear();
}
void MyNameSpace::Human::setName(std::string n) {
	this->name = n;
}
void MyNameSpace::Human::setSurname(std::string s) {
	this->surname = s;
}
void MyNameSpace::Human::Show() {
	std::cout << surname << " " << name << std::endl;
}