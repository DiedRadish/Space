#pragma once

#include<string>
#include<map>
#include<vector>

#include<CommandLine/Argv.h>
#include<CommandLine/Info.h>

namespace Space {
typedef Space::Info(*UnitCallback)(std::multimap<std::string, std::string>&);

struct Unit {
	Space::ID ID;

	std::vector<Space::Argv> Argvs;
	Space::UnitCallback Callback;

	Unit(Space::ID tID, std::vector<Space::Argv> tArgvs, Space::UnitCallback tCallback) :
		ID(tID), Argvs(tArgvs), Callback(tCallback) {
	}

	bool operator==(const std::string& t) const {
		return t == this->ID.Name;
	}
};
}