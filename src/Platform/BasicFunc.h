#pragma once

#include<string>

namespace Space
{
enum class MsgType {
	Message,
	Warning,
	Error
};
void Print(const std::string Msg, MsgType Type = MsgType::Message);
void Print(const char* Msg, MsgType Type = MsgType::Message);
void Print(char* Msg, MsgType Type = MsgType::Message);
template<class T> void Print(T Msg, MsgType Type = MsgType::Message) {
	Print(std::to_string(Msg), Type);
	return;
}
}