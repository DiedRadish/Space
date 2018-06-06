#include"Console.h"

#include<algorithm>

#include"Platform/BasicFunc.h"

Space::Console::Console(std::string tInput, Space::ConsoleStruct tStruct) {
	Input = tInput;
	Struct = tStruct;
	TokenPos = (std::size_t) - 1; //It's right. When call Next() it will add 1 and the TokenPos will be 0.
	TokenSize = Input.size();
	ParsePos = 0;
	ParseFlag = true;

	Lex();
	Parse();
	return;
}

bool Space::Console::Next(char EndChar) {
	TokenPos++;
	if(TokenPos >= TokenSize) {
		return false;
	}
	else {
		ThisChar = Input[TokenPos];
		std::size_t nPos = TokenPos + 1;
		if(nPos >= TokenSize) {
			NextChar = EndChar;
		}
		else {
			NextChar = Input[TokenPos + 1];
		}
		return true;
	}
}

void Space::Console::AddToken(Token::TokenType tType, std::string tName) {
	Tokens.push_back({tName, tType});
	return;
}

bool Space::Console::Lex() {
	while(Next()) {
		std::string Name;
		if(ThisChar == ' ') {
			while(NextChar == ' ' && Next());
		}
		else if(ThisChar == '-') {
			Name += ThisChar;
			while(NextChar != ' ' && Next()) {
				Name += ThisChar;
			}
			AddToken(Token::TokenType::Param, Name);
		}
		else if(ThisChar == '\"') {
			while(Next()) {
				if(ThisChar == '\"' && NextChar == '\"') {
					Name += '\"';
					Next();
				}
				else if(ThisChar == '\"') {
					break;
				}
				else {
					Name += ThisChar;
				}
			}
			AddToken(Token::TokenType::Value, Name);
		}
		else {
			Name += ThisChar;
			while(NextChar != ' ' && Next()) {
				Name += ThisChar;
			}
			AddToken(Token::TokenType::Value, Name);
		}
	}
	return true;
}

bool Space::Console::Match(Token::TokenType tType) {
	if(ParsePos >= Tokens.size()) {
		return false;
	}
	if(Tokens[ParsePos].Type == tType) {
		ParsePos++;
		return true;
	}
	else {
		return false;
	}
}

bool Space::Console::MatchCommandName() {
	if(Match(Token::TokenType::Value)) {
		if(Struct.MatchCommand(Tokens[ParsePos - 1].Name)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Space::Console::MatchArgName() {
	if(Match(Token::TokenType::Param)) {
		if(Struct.MatchArg(Tokens[ParsePos - 1].Name)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Space::Console::MatchArgValue() {
	if(Match(Token::TokenType::Value)) {
		Struct.ThisArg->second.Values.push_back(Tokens[ParsePos - 1].Name);
		return true;
	}
	else {
		return false;
	}
}

bool Space::Console::Check(bool(Console::* tCall)(), bool Ignore) {
	bool tFlag = ParseFlag;
	if(tFlag) {
		tFlag = (this->*tCall)();
	}
	else {
		tFlag = false;
	}
	if(!Ignore) {
		ParseFlag = tFlag;
	}
	return tFlag;
}

bool Space::Console::Parse() {
	Check(&Console::MatchCommandName);
	while(ParsePos < Tokens.size() && ParseFlag) {
		Check(&Console::MatchArgName);
		Check(&Console::MatchArgValue);
		while(Check(&Console::MatchArgValue, true));
	}
	return ParseFlag;
}