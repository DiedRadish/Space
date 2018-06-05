#include"BasicFunc.h"

#include<iostream>

void Space::Print(const std::string Text, Space::MsgType Type) {
	if(Type == Space::MsgType::Message) {
		std::cout << "Message: ";
	}
	else if(Type == Space::MsgType::Warning) {
		std::cout << "Warning: ";
	}
	else if(Type == Space::MsgType::Error) {
		std::cout << "Error: ";
	}
	std::cout << Text << std::endl;
	return;
}

void Space::Print(const char* Msg, MsgType Type) {
	Print(std::string(Msg), Type);
	return;
}

void Space::Print(char* Msg, MsgType Type) {
	Print(std::string(Msg), Type);
	return;
}