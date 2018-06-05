#pragma once

#include<map>
#include<string>
#include<functional>

namespace Space
{
class ConsoleStruct {
public:
	ConsoleStruct() = default;
	ConsoleStruct() = default;
public:
	class Arg {
	};
	struct Command {
		std::map<std::string, Arg> Args;
	};
private:
	std::map<std::string, std::function<void(Command&)>> Commands;
public:
	void AddCommand(std::string tName, std::function<void(Command&)> tCall);
};
}