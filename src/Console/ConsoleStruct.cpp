#include "ConsoleStruct.h"

void Space::ConsoleStruct::AddCommand(std::string tName, CommandCallback tCall) {
	Commands[tName] = tCall;
	return;
}

bool Space::ConsoleStruct::AddArg(std::string tName) {
	if(Args.find(tName) != Args.end()) {
		return false;
	}
	else {
		Args[tName] = Arg();
		return true;
	}
}

bool Space::ConsoleStruct::MatchCommand(std::string tName) {
	auto t = Commands.find(tName);
	if(t != Commands.end()) {
		t->second(std::bind(&ConsoleStruct::AddArg, this, std::placeholders::_1));
		return true;
	}
	else {
		return false;
	}
}

bool Space::ConsoleStruct::MatchArg(std::string tName) {
	auto t = Args.find(tName);
	if(t != Args.end()) {
		ThisArg = t;
		return true;
	}
	else {
		return false;
	}
}