#include "Shell.h"

#include<algorithm>
#include<iostream>

#define FIND_MEMBER(Type, Object, Member, Temp) std::find_if(Object.begin(), Object.end(), [&Temp] (const Type t)->bool{return t.Member == Temp;})
#define FIND_MEMBER_WITH_CHECK(Result, Information, Type, Object, Member, Temp) if((Result = FIND_MEMBER(Type, Object, Member, Temp)) == Object.end()) return Information;

Space::Shell::Shell(std::vector<Space::Unit>& t, bool HelpUnit) :UnitList(t), hasDefaultHelpUnit(HelpUnit) {
}

Space::Info Space::Shell::scan(int argc, char * argv[]) {
	/* 初始化 */
	if(argc < 2) {
		return Space::Info::MissingUnit;
	}

	/* 分析 */
	std::string tName(argv[1]); //当前词法单元的名字
	std::vector<Space::Unit>::iterator tUnit; //当前单元
	std::vector<Space::Argv>::iterator tArgv; //当前参数
	std::multimap<std::string, std::string> tData; //要传递给回调函数的参数

	//是否帮助
	if(hasDefaultHelpUnit && tName == "help") {
		return Space::Info::NeedHelp;
	}

	//寻找当前单元
	FIND_MEMBER_WITH_CHECK(tUnit, Space::Info::UnitNotFound, Space::Unit, UnitList, name, tName);

	//分析此单元的参数
	for(int i = 2; i < argc; i++) {
		//初始化本次的词法单元
		tName = argv[i];

		//寻找当前参数
		FIND_MEMBER_WITH_CHECK(tArgv, Space::Info::ArgvNotFound, Space::Argv, tUnit->ArgvList, name, tName);

		//参数重复检查
		if(tArgv->allowRepeat == false && tData.find(tName) != tData.end()) {
			return Space::Info::ArgvRepeated;
		}

		//参数值传递
		if(tArgv->hasValue) {
			//有值时
			if(++i < argc) {
				tData.insert(std::make_pair(tArgv->name, argv[i]));
			}
			else {
				return Space::Info::ValueNotFound;
			}
		}
		else {
			//无值时
			tData.insert(std::make_pair(tArgv->name, std::string()));
		}
	}

	//将没有命令行中没有写出的补上
	for(auto t : tUnit->ArgvList) {
		std::multimap<std::string, std::string>::iterator result = tData.find(t.name); //map中查找的结果

		if(t.allowEmpty == true) {
			//允许为空
			if(result == tData.end()) {
				tData.insert(std::make_pair(t.name, t.def));
			}
		}
		else {
			//不允许为空
			if(result == tData.end()) {
				return Space::Info::MissingArgv;
			}
		}
	}

	return tUnit->Callback(&tData);
}

std::string Space::Shell::help(std::string UnitName) {
	std::string tStr; //临时文本
	if(UnitName.empty()) {
		//输出全部
		for(auto &t : UnitList) {
			//输出单元的提示
			tStr.append(t.name).append(": ").append(t.description).append("\n");
			for(auto &tt : t.ArgvList) {
				//输出参数的提示
				std::string tName;
				tName.append(tt.allowEmpty ? "[" : "<").append(tt.hasValue ? "___" : "").append(tt.allowEmpty ? "]" : ">").append(tt.allowRepeat ? "..." : "");

				tStr.append("\t").append(tName).append(std::string("\0", 8 - tName.size())).append(" ").append(tt.name).append(": ").append(tt.description).append("\n");
			}
		}
	}
	else {
		//输出Unit的
		auto t = *FIND_MEMBER(Space::Unit, UnitList, name, UnitName);
	}
	return tStr;
}