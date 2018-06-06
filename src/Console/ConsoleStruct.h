#pragma once

#include<map>
#include<string>
#include<functional>
#include<vector>

namespace Space
{
class ConsoleStruct {
public:
	friend class Console;
	class Arg;
	typedef std::function<bool(std::string)> AddArgCallback;
	typedef std::function<void(AddArgCallback)> CommandCallback;
public:
	ConsoleStruct() = default;
	~ConsoleStruct() = default;

public:
	struct Arg {
		std::vector<std::string> Values;
	};
	std::map<std::string, Arg>::iterator ThisArg;
private:
	std::map<std::string, Arg> Args;
	std::map<std::string, CommandCallback> Commands;
public:
	void AddCommand(std::string tName, CommandCallback tCall);
private:
	bool AddArg(std::string tName);
private:
	bool MatchCommand(std::string tName);
	bool MatchArg(std::string tName);
};
}