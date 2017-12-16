#pragma once

#include<string>

namespace Space
{
struct ID
{
	std::string Name;
	std::string Description;
};
}

inline bool operator==(const Space::ID &first, const Space::ID &second)
{
	return first.Name == second.Name;
}