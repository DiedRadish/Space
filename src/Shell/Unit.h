#pragma once
#include<string>
#include<vector>
#include<map>

#include<Shell/Argv.h>
#include<Shell/Info.h>

namespace Space {
//各个单元的回调函数
typedef Space::Info(*UnitCallBack)(std::multimap<std::string, std::string>*);

//单元的描述
struct Unit {
	std::string name; //单元名
	std::string description; //单元描述
	std::vector<Space::Argv> ArgvList;//参数列表
	Space::UnitCallBack Callback; //回调函数

private:
	Unit() = default;
public:
	Unit(std::string _name, std::string _description, std::vector<Space::Argv> _ArgvList, Space::UnitCallBack _Callback) :
		name(_name), description(_description), ArgvList(_ArgvList), Callback(_Callback) {
	}
	~Unit() = default;
};
}