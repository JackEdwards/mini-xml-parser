#include "XMLFile.hpp"

int main()
{
	XMLFile file("data.xml");

	for (int i = 0; i < file.m_tokens.size(); ++i)
		std::cout << file.m_tokens[i].m_content << '\n';

	system("pause");
}