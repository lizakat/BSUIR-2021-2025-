#pragma once

#include"Course.h"
#include "Curator.h"
namespace MyNameSpace {
	class Group :public Course, public Curator
	{
		int group;
	public:
		Group(std::string UniName, std::string spec, int course, std::string name, std::string surname, int age, int group);
		Group();
		~Group() {}

		void Show();
	};
}
