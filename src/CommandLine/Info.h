#pragma once

#include<string>

namespace Space
{
enum class InfoCode
{
	Success = 1
};

struct Info
{
	InfoCode Code;
	std::string Message;
};
}