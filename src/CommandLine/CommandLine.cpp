#include "CommandLine.h"

Space::CommandLine::CommandLine(std::string _Description, bool _HasHelp) :Description(_Description), HasHelp(_HasHelp)
{
}

std::vector<Space::Unit>::iterator Space::CommandLine::AddUnit(Space::ID _id, Space::UnitCallback _cb)
{
	Units.push_back(Space::Unit({_id, {}, _cb}));
	return Units.end()-1;
}

void Space::CommandLine::AddArgv(std::vector<Space::Unit>::iterator _Unit, Space::ID _id, std::string DefaultValue, bool HasValue, bool AllowRepeat, bool AllowEmpty)
{
	_Unit->Argvs.push_back({_id, DefaultValue, HasValue, AllowRepeat, AllowEmpty});
}

Space::Info Space::CommandLine::Scan(std::vector<std::string> _CommandLine)
{
	return Space::Info();
}
