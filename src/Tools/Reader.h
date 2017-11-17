#pragma once

#include<fstream>
#include<string>

namespace Space {
//将ifstream中的文件读到string中
class Reader {
public:
	std::string texts;

private:
	Reader() = default;
public:
	Reader(std::string filename);
	~Reader() = default;

public:
	std::string getTexts();
};
}