#include "Student.h"

MyNameSpace::Student::Student(std::string UniName, std::string spec, int course, std::string name, std::string surname, int age, int group,
	std::string stname, std::string stsurname, double averBall) :
	Group(UniName, spec, course, name, surname, age, group), averBall(averBall)
{
	h.setName(stname);
	h.setSurname(stsurname);

}
MyNameSpace::Student::Student()
{
	averBall = 0;
}

void MyNameSpace::Student::Show()
{
	std::cout << "Student's name:  ";
	h.Show();
	Group::Show();
	std::cout << "Student's average ball:  ";
	std::cout << averBall << std::endl;
}