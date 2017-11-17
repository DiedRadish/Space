#pragma once
#include<vector>

#include<Shell/Unit.h>
#include<Shell/Info.h>

namespace Space {
//处理命令行
class Shell {
private:
	Shell() = default;
public:
	Shell(std::vector<Space::Unit>& t, bool HelpUnit = true);
	~Shell() = default;
private:
	std::vector<Space::Unit>& UnitList;
	bool hasDefaultHelpUnit;

public:
	//进行分析
	Space::Info scan(int argc, char* argv[]);

public:
	//输出帮助文本
	std::string help(std::string UnitName = "");
};
}
