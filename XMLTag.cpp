#include "XMLTag.hpp"

XMLTag::XMLTag() { }

XMLTag::XMLTag(std::string name)
{
	m_name = name;
}

void XMLTag::AddChild(XMLTag* tag)
{
	tag->mp_parent = this;
	m_children.push_back(tag);
}

XMLTag* XMLTag::GetFirstChild()
{
	if (m_children.size() > 0)
		return m_children[0];
	
	return nullptr;
}

XMLTag* XMLTag::GetChildWithName(std::string query)
{
	for (XMLTag* tag : m_children)
		if (tag->m_name == query)
			return tag;

	return nullptr;
}