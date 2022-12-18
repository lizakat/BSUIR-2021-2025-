#pragma once

#include "Specialization.h"

namespace MyNameSpace {
	class Course :public Specialization
	{
		int course;
	public:
		Course(std::string UniName, std::string spec, int course);
		Course();
		~Course() {}

		void Show();

	};
}
