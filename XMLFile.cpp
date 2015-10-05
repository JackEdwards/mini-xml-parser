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
	Lex();
}

void XMLFile::Lex()
{
	std::string token;
	State state = State::OutsideTag;

	for (size_t i = 0; i < m_contents.size(); ++i)
	{
		if (m_contents[i] == '\n' || m_contents[i] == '\t')
			continue;

		token += m_contents[i];

		switch (state)
		{
		case State::OutsideTag:
			if (token == "<")
			{
				if (m_contents[i + 1] == '/')
					continue;

				AddToken(token, TokenType::OpeningTagStart);
				state = State::InsideTag;
			}
			else if (token == "</")
			{
				AddToken(token, TokenType::ClosingTagStart);
				state = State::InsideTag;
			}
			else if (m_contents[i + 1] == '<')
			{
				AddToken(token, TokenType::TagContent);
			}

			break;
		case State::InsideTag:
			if (m_contents[i + 1] == '>')
			{
				AddToken(token, TokenType::TagName);
			}
			if (token == ">")
			{
				AddToken(token, TokenType::TagEnd);
				state = State::OutsideTag;
			}

			break;
		}
	}
}

void XMLFile::AddToken(std::string& text, TokenType type)
{
	m_tokens.push_back(Token(text, type));
	text = "";
}