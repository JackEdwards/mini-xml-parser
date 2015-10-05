#include "XMLFile.hpp"

XMLFile::XMLFile() {}

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
	Parse();
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
			if (m_contents[i + 1] == '>' || m_contents[i + 1] == ' ')
			{
				AddToken(token, TokenType::TagName);
			}
			if (token == ">")
			{
				AddToken(token, TokenType::TagEnd);
				state = State::OutsideTag;
			}
			else if (token == " ")
			{
				token = "";
				state = State::InsideAttribute;
			}

			break;
		case State::InsideAttribute:
			if (m_contents[i + 1] == '=')
			{
				AddToken(token, TokenType::AttributeName);
			}
			if (token == "=")
			{
				AddToken(token, TokenType::EqualsSign);
			}
			else if (token == "\"")
			{
				AddToken(token, TokenType::DoubleQuote);
				state = State::InsideAttributeContent;
			}

			break;
		case State::InsideAttributeContent:
			if (m_contents[i + 1] == '"')
			{
				AddToken(token, TokenType::AttributeContent);
			}
			if (token == "\"")
			{
				AddToken(token, TokenType::DoubleQuote);
				state = State::InsideTag;
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

void XMLFile::Parse()
{
	for (Token token : m_tokens)
	{
		std::cout << token.m_content << " - ";

		switch (token.m_type)
		{
		case TokenType::OpeningTagStart:
			std::cout << "OpeningTagStart\n";
			break;
		case TokenType::ClosingTagStart:
			std::cout << "ClosingTagStart\n";
			break;
		case TokenType::TagEnd:
			std::cout << "TagEnd\n";
			break;
		case TokenType::TagName:
			std::cout << "TagName\n";
			break;
		case TokenType::TagContent:
			std::cout << "TagContent\n";
			break;
		case TokenType::AttributeName:
			std::cout << "AttributeName\n";
			break;
		case TokenType::AttributeContent:
			std::cout << "AttributeContent\n";
			break;
		case TokenType::EqualsSign:
			std::cout << "EqualsSign\n";
			break;
		case TokenType::DoubleQuote:
			std::cout << "DoubleQuote\n";
			break;
		}
	}
}
