#include "XMLFile.hpp"

int main()
{
	XMLFile file("data.xml");
	file.PrintAllData();

	#ifdef _WIN32
		system("pause");
	#endif
}