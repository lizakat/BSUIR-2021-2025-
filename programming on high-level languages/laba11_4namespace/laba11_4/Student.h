#pragma once

#include "Human.h"
#include"Group.h"

namespace MyNameSpace {
	class Student :public Group
	{
		double averBall;
		Human h;
	public:
		Student(std::string UniName, std::string spec, int course, std::string name, std::string surname, int age, int group,
			std::string stname, std::string stsurname, double averBall);
		Student();
		~Student() {}

		void Show();
	};
}