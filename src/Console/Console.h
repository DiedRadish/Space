#pragma once

#include<functional>
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<exception>

#include"ConsoleStruct.h"

namespace Space
{
class Console {
private:
	Console() = default;
public:
	Console(std::string tInput, ConsoleStruct tStruct);
	~Console() = default;
private:
	std::string Input;
	ConsoleStruct Struct;

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
	std::size_t TokenPos, TokenSize;
	char ThisChar, NextChar;
	bool Next(char EndChar = '\0');
private:
	void AddToken(Token::TokenType tType, std::string tName);
	bool Lex();

	/* Syntax Analysis*/
private:
	std::size_t ParsePos;
	bool ParseFlag;
	bool Match(Token::TokenType tType);
	bool MatchCommandName();
	bool MatchArgName();
	bool MatchArgValue();
	bool Check(bool(Console::*tCall)(), bool Ignore = false);
	bool Parse();
};
}
