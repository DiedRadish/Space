#include"Console.h"

#include<algorithm>

#include"Platform/BasicFunc.h"

Space::Console::Console(std::string tInput, Space::ConsoleStruct tStruct):Console() {
	Input = tInput;
	Struct = tStruct;
	Pos = (std::size_t) - 1; //It's right. When call Next() it will add 1 and the Pos will be 0.
	Size = Input.size();

	Lex();
	for(auto& t : Tokens) {
		Print(t.Name);
	}
	return;
}

//void Space::Console::Input(std::string Cmd) {
//	char tL, nL;
//	std::size_t i = 0;
//
//	auto Set = [&]() {
//		tL = Cmd[i];
//		nL = (i + 1) < Cmd.size() ? Cmd[i + 1] : ' ';
//	};
//	auto Next = [&]()->bool {
//		i++;
//		if(i >= Cmd.size()) {
//			return false;
//		}
//		Set();
//		return true;
//	};
//
//	Set();
//	std::vector<std::string> Args;
//	for(; i < Cmd.size(); Next()) {
//		std::string Arg;
//		Arg.reserve(Args.size());
//		if(tL == ' ') {
//			while(nL == ' ' && Next()) {
//			}
//		}
//		else if(tL == '-') {
//			Arg += tL;
//			while(nL != ' ' && Next()) {
//				Arg += tL;
//			}
//			Args.push_back(Arg);
//		}
//		else if(tL == '\"') {
//			while(Next()) {
//				if(tL == '\"' && nL == '\"') {
//					Arg += '\"';
//					Next();
//				}
//				else if(tL == '\"') {
//					break;
//				}
//				else {
//					Arg += tL;
//				}
//			}
//			Args.push_back(Arg);
//		}
//		else {
//			Arg += tL;
//			while(nL != ' ' && Next()) {
//				Arg += tL;
//			}
//			Args.push_back(Arg);
//		}
//	}
//
//	Print(std::string("Command: ") + Cmd);
//	if(Args.size() > 0) {
//		if((Commands.find(Args[0])) != Commands.end()) {
//			Args.resize(Commands[Args[0]].ArgCount + 1);
//			if(!Commands[Args[0]].Callback(std::vector<std::string>(Args.begin() + 1, Args.end()))) {
//				Print("Error: Command.");
//			}
//		}
//		else {
//			Print("Error: Command name.");
//		}
//	}
//	else {
//		Print("Error: Arg size.");
//	}
//}

//bool Space::Console::AddCommand(std::string tCommandName, std::map<std::string, Arg> tArgs,
//								Command::Callback tCall) {
//	if(Commands.find(tCommandName) != Commands.end()) {
//		return false;
//	}
//	Commands[tCommandName] = Command({tArgs, tCall});
//	return true;
//}
//
//bool Space::Console::RemoveCommand(std::string tCommandName) {
//	if(Commands.find(tCommandName) == Commands.end()) {
//		return false;
//	}
//	Commands.erase(tCommandName);
//	return true;
//}

//std::string Space::Console::CommandHelp() {
//	std::string t;
//	for(auto &c : Commands) {
//		t += c.first;
//		t += '\n';
//	}
//	t.erase(t.end() - 1);
//	return t;
//}

void Space::Console::AddToken(Token::TokenType tType, std::string tName) {
	Tokens.push_back({tType, tName});
	return;
}

void Space::Console::Lex() {
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
}

bool Space::Console::Next(char EndChar) {
	Pos++;
	if(Pos >= Size) {
		return false;
	}
	else {
		ThisChar = Input[Pos];
		std::size_t nPos = Pos + 1;
		if(nPos >= Size) {
			NextChar = EndChar;
		}
		else {
			NextChar = Input[Pos + 1];
		}
		return true;
	}
}