#ifndef XMLTAG_HPP
#define XMLTAG_HPP

#include <string>
#include <vector>

class XMLTag
{
public:
	std::string m_name;
	std::string m_data;
	XMLTag* mp_parent;
	std::vector<XMLTag*> m_children;

public:
	XMLTag();
	XMLTag(std::string name);
	void AddChild(std::string name);
	void AddChild(std::string name, std::string data);
};

#endif