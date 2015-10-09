#include "XMLFile.hpp"

int main()
{
	XMLFile file("data2.xml");
	XMLTag* tag = file.m_root->GetFirstChild("Map");
	std::vector<XMLTag*> tags = tag->GetChildren("Tile");

	for (XMLTag* tag : tags)
		std::cout << "X: " << tag->m_attributes["x"].ToInt() << " Y: " << tag->m_attributes["y"].ToInt() << '\n';

	/*XMLFile file;
	file.Load("data2.xml");
	XMLTag* root = file.m_root->GetFirstChild("Resources");
	std::vector<XMLTag*> tags = root->GetChildren("Texture");

	for (XMLTag* tag : tags)
	{
		std::cout << "Path: " << tag->m_attributes["path"].ToString() << "Name: " << tag->m_attributes["name"].ToString() << '\n';
	}*/

	#ifdef _WIN32
		system("pause");
	#endif
}