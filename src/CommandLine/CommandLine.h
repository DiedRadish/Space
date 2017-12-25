#pragma once

#include<vector>
#include<string>

#include<CommandLine/Unit.h>

namespace Space {
class CommandLine {
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
	std::vector<Space::Unit>::iterator AddUnit(Space::ID tID, Space::UnitCallback tCallback);
	bool AddArgv(std::vector<Space::Unit>::iterator tUnit, Space::ID tID,
				 std::string tDefaultValue,
				 Space::ArgvType tType,
				 bool tArrayType,
				 bool tAllowDefaultValue);

public:
	Space::Info Scan(const std::vector<std::string>& CmdLine);

public:
	std::string HelpMessage(const std::vector<Space::Unit>::iterator tUnit);
	std::string HelpMessage();
};
}