#include "XMLFile.hpp"

XMLFile::XMLFile()
{

}

XMLFile::XMLFile(std::string path)
{
	Load(path);
}

void XMLFile::Load(std::string path)
{
	/*std::string line;
	std::ifstream file(path);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			m_lines.push_back(line);
		}
	}
	else
	{
		std::cout << "File: " + path + " could not be opened.\n";
	}

	file.close();*/

	std::ifstream file(path);

	if (file.is_open())
	{
		std::string line;

		while (getline(file, line))
		{
			line += '\n';
			m_contents += line;
		}
	}
	else
	{
		std::cout << "File: " + path + " could not be opened.\n";
	}

	file.close();
}

void XMLFile::PrintLines()
{
	for (std::string line : m_lines)
	{
		std::cout << line << '\n';
	}
}