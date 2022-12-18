#pragma once

#include "University.h"
namespace MyNameSpace {
	class Specialization :public University
	{
		std::string spec;
	public:
		Specialization(std::string UniName, std::string spec);
		Specialization();
		~Specialization();
		void Show();
	};
}
