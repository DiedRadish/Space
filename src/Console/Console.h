#pragma once

#include<functional>
#include<iostream>
#include<map>
#include<string>
#include<vector>

#include"ConsoleStruct.h"

namespace Space
{
class Console {
private:
	Console() = default;
public:
	Console(std::string tInput, ConsoleStruct tStruct);
	~Console() = default;

	/* Base */
public:
	std::string Input;

	/* Command */
private:
	ConsoleStruct Struct;
	//std::string CommandHelp();

	/* Lexical Analysis*/
private:
	struct Token {
		std::string Name;
		enum class TokenType {
			Param,
			Value
		};
		TokenType Type;
	};
	std::vector<Token> Tokens;
private:
	void AddToken(Token::TokenType tType, std::string tName);
	void Lex();
private:
	std::size_t Pos, Size;
	char ThisChar, NextChar;
	bool Next(char EndChar = '\0');

	/* Syntax Analysis*/
	class Node {
	public:
		std::string Name;
		std::vector<Node*> Children;
	public:
		~Node() {
			for(auto& t : Children) {
				delete t;
			}
		}
	};
};
}
