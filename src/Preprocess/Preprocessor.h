#pragma once

#include<fstream>
#include<string>

#include<Tools/types.h>

namespace Space {
//预处理
//去除源文件中的文本
class Preprocessor {
private:
	//原始文件
	const std::string texts;

private:
	Preprocessor() = default;
public:
	Preprocessor(std::string t);
	~Preprocessor() = default;

public:
	//返回预处理后的源文件
	std::string scan();
private:
	//得到某个字节
	const byte getByte(size_t pos);
	//验证某字节是否存在
	bool testByte(size_t pos);
};
}
