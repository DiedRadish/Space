#pragma once

#include<string>

#include<CommandLine/ID.h>
namespace Space {
enum ArgvType {
	String = 0,
	Bool = 1,
	Int = 2
};

struct Argv {
	Space::ID ID;
	std::string DefaultValue;

	Space::ArgvType Type;
	bool ArrayType;
	bool AllowDefaultValue;

	Argv(Space::ID tID,
		 std::string tDefaultValue,
		 Space::ArgvType tType,
		 bool tArrayType,
		 bool tAllowDefaultValue) :
		ID(tID),
		DefaultValue(tDefaultValue),
		Type(tType),
		ArrayType(tArrayType),
		AllowDefaultValue(tAllowDefaultValue) {
	}

	bool operator==(std::string s) {
		return this->ID.Name == s;
	}
};
}