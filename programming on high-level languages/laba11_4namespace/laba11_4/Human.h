#pragma once
#include<iostream>
#include<string>

namespace MyNameSpace {
	class Human
	{
		std::string name;
		std::string surname;

	public:
		Human(std::string name, std::string surname);
		Human();
		~Human();
		void setName(std::string n);
		void setSurname(std::string s);
		void Show();
	};
}

