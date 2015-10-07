#include "XMLTag.hpp"

XMLTag::XMLTag() { }

XMLTag::XMLTag(std::string name)
{
	m_name = name;
}

XMLTag::~XMLTag()
{
	for (int i = 0; i < m_children.size(); ++i)
		delete m_children[i];
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

XMLTag* XMLTag::GetChild(std::string name)
{
	for (XMLTag* tag : m_children)
		if (tag->m_name == name)
			return tag;

	return nullptr;
}