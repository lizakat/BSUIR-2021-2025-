#include "Group.h"

MyNameSpace::Group::Group(std::string UniName, std::string spec, int course, std::string name, std::string surname, int age, int group) :
	Course(UniName, spec, course), Curator(name, surname, age), group(group) {}
MyNameSpace::Group::Group()
{
	group = 0;
}


void MyNameSpace::Group::Show() {
	Course::Show();
	Curator::Show();
	std::cout << "Group:  ";
	std::cout << group << std::endl;
}