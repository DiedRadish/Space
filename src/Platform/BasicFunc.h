#pragma once

#include<string>
#include<vector>

namespace Space
{
enum class MsgType {
	Message,
	Warning,
	Error
};
void Print(const std::string Msg, MsgType Type = MsgType::Message);
template<class T>
void Print(const std::vector<T> Msg, MsgType Type = MsgType::Message) {
	Print('[');
	for(auto &t : Msg) {
		Print(t, Type);
	}
	Print(']');
	return;
}
void Print(const char* Msg, MsgType Type = MsgType::Message);
void Print(char* Msg, MsgType Type = MsgType::Message);
void Print(const char Msg, MsgType = MsgType::Message);
template<class T> void Print(T Msg, MsgType Type = MsgType::Message) {
	Print(std::to_string(Msg), Type);
	return;
}
}