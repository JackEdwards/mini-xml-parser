#include "XMLFile.hpp"

#include <algorithm>

// Hello from Jack's Macbook!

enum TokenType;
void AddToken(std::string& text, TokenType type, std::vector<std::pair<std::string, TokenType>>& tokens);

enum State
{
	InsideTag,
	OutsideTag
};

enum TokenType
{
	OpeningTagStart,
	ClosingTagStart,
	TagEnd,
	TagName,
	TagContent
};

int main()
{
	XMLFile file("data.xml");
	std::string token;
	std::vector<std::pair<std::string, TokenType>> tokens;
	State state = State::OutsideTag;

	for (size_t i = 0; i < file.m_contents.size(); ++i)
	{
		token += file.m_contents[i];

		switch (state)
		{
		case State::OutsideTag:
			if (token == "<")
			{
				if (file.m_contents[i + 1] == '/')
					continue;

				AddToken(token, TokenType::OpeningTagStart, tokens);
				state = State::InsideTag;
			}
			else if (token == "</")
			{
				AddToken(token, TokenType::ClosingTagStart, tokens);
				state = State::InsideTag;
			}
			else if (file.m_contents[i + 1] == '<')
			{
				AddToken(token, TokenType::TagContent, tokens);
			}

			break;
		case State::InsideTag:
			if (file.m_contents[i + 1] == '>')
			{
				AddToken(token, TokenType::TagName, tokens);
			}
			if (token == ">")
			{
				AddToken(token, TokenType::TagEnd, tokens);
				state = State::OutsideTag;
			}

			break;
		}
	}

	for (int i = 0; i < tokens.size(); ++i)
	{
		std::cout << tokens[i].first << '\n';
	}

	system("pause");
}

void AddToken(std::string& text, TokenType type, std::vector<std::pair<std::string, TokenType>>& tokens)
{
	tokens.push_back(std::make_pair(text, type));
	text = "";
}