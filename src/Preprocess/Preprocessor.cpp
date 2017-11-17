#include<Preprocess/Preprocessor.h>

#include<Preprocess/states.h>

Space::Preprocessor::Preprocessor(std::string t) : texts(t) {
	Preprocessor::Preprocessor();
}

std::string Space::Preprocessor::scan() {
	//存放处理后的文件
	std::string temp;

	//遍历文件查找注释，文本

	//是否开始读取
	bool started = false;
	for(size_t i = 0 /*当前位置*/; testByte(i); i++) {
		//可以保证i不越界
		byte ch = getByte(i);

		//switch(ch) {
		//default:
		//	break;
		//}
		//文本
		if(getByte(i) == '\"') {
			while(testByte(++i)) {
				if(getByte(i) == '\"') {
					//去除文本要将单引号删掉
					++i;
					break;
				}
			}
		}

		//单行注释
		else if(getByte(i) == '/' && getByte(i + 1) == '/') {
			while(testByte(++i)) {
				if(getByte(i) == '\n') {
					//去除注释不能将换行符删掉。。。
					break;
				}
			}
		}

		//多行注释
		else if(getByte(i) == '/' && getByte(i + 1) == '*') {
			while(testByte(++i)) {
				if(getByte(i) == '*' && getByte(i + 1) == '/') {
					++i;
					break;
				}
			}
		}

		temp += getByte(i);
	}
	return temp;
}

const byte Space::Preprocessor::getByte(size_t pos) {
	if(!testByte(pos)) {
		//！！待定！！
		return '\0';
	}
	return texts[pos];
}

bool Space::Preprocessor::testByte(size_t pos) {
	if(pos > texts.size() || pos < 0) {
		return false;
	}
	return true;
}