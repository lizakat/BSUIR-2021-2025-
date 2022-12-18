#include "University.h"


MyNameSpace::University::University(std::string UniName) :UniName(UniName) {}
MyNameSpace::University::University() {
	UniName = "";
}
MyNameSpace::University::~University()
{
	UniName.clear();
}
void MyNameSpace::University::Show() {
	std::cout << UniName << std::endl;
}
