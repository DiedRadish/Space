#pragma once

#include<vector>
#include<string>

#include<CommandLine/Unit.h>

namespace Space
{
class CommandLine
{
private:
	CommandLine() = default;
public:
	CommandLine(std::string _Description, bool _HasHelp);
	~CommandLine() = default;

private:
	std::vector<Space::Unit> Units;
	std::string Description;
	bool HasHelp;

public:
	std::vector<Space::Unit>::iterator AddUnit(Space::ID _id, Space::UnitCallback _cb);
	void AddArgv(std::vector<Space::Unit>::iterator _Unit, Space::ID _id,
		 std::string DefaultValue, bool HasValue, bool AllowRepeat, bool AllowEmpty);

public:
	Space::Info Scan(std::vector<std::string> _CommandLine);
};
}