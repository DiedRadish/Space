#pragma once
#include<string>

namespace Space {
//参数的描述
struct Argv {
	std::string name; //参数名
	std::string description; //参数描述
	std::string def; //默认值
	bool hasValue; //有无参数值
	bool allowRepeat; //允许重复
	bool allowEmpty; //允许不填

private:
	Argv() = default;
public:
	Argv(std::string _name, std::string _description, std::string _def, bool _hasValue, bool _allowRepeat, bool _allowEmpty) :
		name(_name), description(_description), def(_def), hasValue(_hasValue), allowRepeat(_allowRepeat), allowEmpty(_allowEmpty) {
	}
	~Argv() = default;
};
}