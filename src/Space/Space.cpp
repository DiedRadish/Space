#include<iostream>

#include<Space/Space.h>

int main(int argc, char* argv[]) {
	/* 输出命令行 */
	for(int i = 0; i < argc; i++) {
		std::cout << argv[i] << '\0';
	}
	std::cout << std::endl;

	/* 初始化 */
	std::vector<Space::Unit> t;
	t.push_back(Space::Unit("build", "Compile the file.", {
		Space::Argv("-", "File name.", "", true, true, false),
		Space::Argv("-o", "Set the name of out file.", "a.space", true, false, true),
		Space::Argv("-I", "Set the include file.", "", true, true, true)
	}, BuildUnit));
	t.push_back(Space::Unit("tool", "Tools of Space.", {
		Space::Argv("/temp1", "Test1.", "", false, false, true),
		Space::Argv("/temp2", "Test2.", "12312323213", true, true, true),
		Space::Argv("/temp3", "Test3.", "", false, false, false)
	}, ToolUnit));

	Space::Shell s(t);

	/* 输出结果 */
	auto re = s.scan(argc, argv);
	if(re == Space::Info::NeedHelp) {
		std::cout << s.help();
		re = Space::Info::Success;
	}
	std::cout << std::endl << "Result:" << (int)re;
}

//进行构建的模块
Space::Info BuildUnit(std::multimap<std::string, std::string>* ArgvMap) {
	//Space::Reader r("C:/Users/diedr/Documents/Projects/Space/samples/temp.Space");
	//Space::Preprocessor pre(r.getTexts());
	//std::cout << pre.scan();

	auto printArgv = [ArgvMap](std::string name) {
		auto temp = ArgvMap->equal_range(name);
		std::multimap<std::string, std::string>::iterator beg = temp.first, end = temp.second, t;
		for(t = beg; t != end; t++) {
			std::cout << t->second << std::endl;
		}
		std::cout << std::endl;
	};

	printArgv("-");
	printArgv("-o");
	printArgv("-I");
	return Space::Info::Success;
}

//其他模块
Space::Info ToolUnit(std::multimap<std::string, std::string>* ArgvMap) {
	auto printArgv = [ArgvMap](std::string name) {
		auto temp = ArgvMap->equal_range(name);
		std::multimap<std::string, std::string>::iterator beg = temp.first, end = temp.second, t;
		for(t = beg; t != end; t++) {
			std::cout << t->second << std::endl;
		}
		std::cout << std::endl;
	};

	printArgv("/temp1");
	printArgv("/temp2");
	printArgv("/temp3");

	return Space::Info::Success;
}