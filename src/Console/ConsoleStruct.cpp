#include "ConsoleStruct.h"

void Space::ConsoleStruct::AddCommand(std::string tName, std::function<void(Command&)> tCall) {
	Commands[tName] = tCall;
	return;
}