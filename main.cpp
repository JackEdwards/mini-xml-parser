#include "XMLFile.hpp"

int main()
{
	XMLFile file("data.xml");
	XMLTag* tag = file.m_root->GetChild("Settings")->GetChild("ScreenSize");

	std::cout << "Width: " << tag->GetChild("Width")->m_value.ToInt();
	std::cout << " Height: " << tag->GetChild("Height")->m_value.ToInt();
	std::cout << std::endl;

	#ifdef _WIN32
		system("pause");
	#endif
}