#pragma once

#include<string>

#include<CommandLine/ID.h>
namespace Space
{
struct Argv
{
	Space::ID ID;
	std::string DefaultValue;

	bool HasValue;
	bool AllowRepeat;
	bool AllowEmpty;
};
}