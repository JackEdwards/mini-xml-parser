#include "XMLFile.hpp"

int main()
{
	XMLFile file("data2.xml");
	XMLTag* tag = file.m_root->GetFirstChild("Map");
	std::vector<XMLTag*> tags = tag->GetChildren("Tile");

	for (XMLTag* tag : tags)
		std::cout << "X: " << tag->m_attributes["x"].ToInt() << " Y: " << tag->m_attributes["y"].ToInt() << '\n';

	#ifdef _WIN32
		system("pause");
	#endif
}