#pragma once

namespace Space {
//返回信息
enum class Info {
	Success = 0x0000, //执行成功
	MissingUnit = 0x0001, //缺少单元
	MissingArgv = 0x0007, //缺少参数
	UnitNotFound = 0x0002, //单元未找到
	ArgvNotFound = 0x0003, //参数未找到
	ArgvRepeated = 0x0004, //参数重复
	ValueNotFound = 0x0005, //参数值未找到

	NeedHelp = 0x0006 //需要输出帮助
};
}