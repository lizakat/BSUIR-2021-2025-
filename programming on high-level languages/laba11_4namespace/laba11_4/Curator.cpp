#include "Curator.h"

MyNameSpace::Curator::Curator(std::string name, std::string surname, int age) :Human(name, surname), age(age) {}
MyNameSpace::Curator::Curator() {
	age = 0;
}

void MyNameSpace::Curator::Show() {
	std::cout << "Curator's name:  ";
	Human::Show();
	std::cout << "Curator's age:  ";
	std::cout << age << std::endl;
}