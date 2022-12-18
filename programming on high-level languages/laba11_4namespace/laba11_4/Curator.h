#pragma once

#include"Human.h"
namespace MyNameSpace {
	class Curator :public Human
	{
		int age;
	public:
		Curator(std::string name, std::string surname, int age);
		Curator();
		~Curator() {}

		void Show();
	};
}

