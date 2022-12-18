#include "Student.h"

int main() {
	
	std::string crname, crsurname, uname, stname, stsurname, spec;
	int num, crs, ag;
	double ball;

	std::cout << "Enter Student's name" << std::endl;
	std::cin >> stname;
	std::cout << "Enter Student's surname" << std::endl;
	std::cin >> stsurname;
	std::cout << "Enter University's name: " << std::endl;
	std::cin >> uname;
	std::cout << "Enter Specialization:" << std::endl;
	std::cin >> spec;
	std::cout << "Enter Course:" << std::endl;
	std::cin >> crs;
	std::cout << "Enter Group's number:" << std::endl;
	std::cin >> num;
	std::cout << "Enter Curator's name:" << std::endl;
	std::cin >> crname;
	std::cout << "Enter Curator's suurname:" << std::endl;
	std::cin >> crsurname;
	std::cout << "Enter Curator's age:" << std::endl;
	std::cin >> ag;
	std::cout << "Enter Student's average ball:" << std::endl;
	std::cin >> ball;
	

	MyNameSpace::Student st(uname, spec, crs, crname, crsurname, ag, num, stname, stsurname, ball);
	std::cout << std::endl;
	st.Show();
	return 0;
}
