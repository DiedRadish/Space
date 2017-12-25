#pragma once

#include<string>

namespace Space {
enum class InfoCode {
	Success = 1,

	MissingUnit = 2, //缺少单元名
	MissingArgv = 5, //缺少参数名
	MissingValue = 6, //缺少参数值

	UnitNotFound = 3, //单元名错误（表中未找到）
	ArgvNotFound = 4, //参数名错误（表中未找到）

	ArgvRepeated = 7 //参数重复添加
};

struct Info {
	InfoCode Code;
	std::string Message;
private:
	Info() = default;
public:
	Info(InfoCode tCode, std::string tMessage) :Code(tCode), Message(tMessage) {
	}
	~Info() = default;
};
}