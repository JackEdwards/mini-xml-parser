#ifndef XMLTAG_HPP
#define XMLTAG_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "XMLValue.hpp"

class XMLTag
{
public:
	std::string m_name;
	//std::string m_value;
	XMLValue m_value;
	std::unordered_map<std::string, std::string> m_attributes;
	XMLTag* mp_parent;
	std::vector<XMLTag*> m_children;

public:
	XMLTag();
	XMLTag(std::string name);
	void AddChild(XMLTag* tag);
	XMLTag* GetFirstChild();
	XMLTag* GetChildWithName(std::string query);
};

#endif