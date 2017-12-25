#pragma once

#include<string>

namespace Space {
struct ID {
	std::string Name;
	std::string Description;

	ID(std::string tName, std::string tDescription) :
		Name(tName), Description(tDescription) {
	}

	operator std::string() {
		return this->Name += std::string(": ") += this->Description;
	}
};
}