#ifndef XMLFILE_HPP
#define XMLFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "XMLTag.hpp"

class XMLFile
{
public:
	std::string m_path;
	std::string m_contents;
	std::vector<std::string> m_lines;
	XMLTag* m_root;

public:
	XMLFile();
	XMLFile(std::string path);
	void Load(std::string path);
	void PrintLines();
};

#endif