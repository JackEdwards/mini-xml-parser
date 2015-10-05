#ifndef XMLFILE_HPP
#define XMLFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "XMLTag.hpp"
#include "Token.hpp"

enum State
{
	InsideTag,
	OutsideTag,
	InsideAttribute,
	InsideAttributeContent
};

class XMLFile
{
public:
	std::string m_path;
	std::string m_contents;
	std::vector<Token> m_tokens;
	XMLTag* const m_root = new XMLTag();

public:
	XMLFile();
	XMLFile(std::string path);
	void Load(std::string path);
	void Lex();
	void AddToken(std::string& text, TokenType type);
	void Parse();
	void PrintData(XMLTag* tag, int depth = 0);
	void PrintAllData();
};

#endif