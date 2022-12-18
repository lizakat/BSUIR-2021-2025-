#pragma once

#include<string>
#include<iostream>
namespace MyNameSpace {
	class University
	{
		std::string UniName;
	public:
		University(std::string UniName);
		University();
		~University();

		void Show();

	};
}
