#include<Tools/Reader.h>
#include<string>

Space::Reader::Reader(std::string filename) :Reader() {
	//以二进制方式打开
	std::ifstream file(filename, std::ios::binary);

	//将文件读入string中（我承认代码是EffectiveSTL上的）
	texts = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

std::string Space::Reader::getTexts() {
	return texts;
}