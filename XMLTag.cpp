#include "XMLTag.hpp"

XMLTag::XMLTag()
{

}

XMLTag::XMLTag(std::string name)
{
	m_name = name;
}

void XMLTag::AddChild(std::string name)
{
	XMLTag* child = new XMLTag(name);
	child->mp_parent = this;
	m_children.push_back(child);
}

void XMLTag::AddChild(std::string name, std::string data)
{
	XMLTag* child = new XMLTag(name);
	child->m_data = data;
	child->mp_parent = this;
	m_children.push_back(child);
}