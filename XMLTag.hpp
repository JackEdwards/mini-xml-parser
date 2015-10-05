#ifndef XMLTAG_HPP
#define XMLTAG_HPP

#include <string>
#include <vector>
#include <unordered_map>

class XMLTag
{
public:
	std::string m_name;
	std::string m_value;
	std::unordered_map<std::string, std::string> m_attributes;
	XMLTag* mp_parent;
	std::vector<XMLTag*> m_children;

public:
	XMLTag();
	XMLTag(std::string name);
	void AddChild();
	void AddChild(std::string name);
	void AddChild(std::string name, std::string data);
};

#endif