#include"Space.h"

#include"Console/Console.h"

#include"Platform/Platform.h"
#include"Platform/BasicFunc.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		Space::Print("Args size error!", Space::MsgType::Warning);
		return 0;
	}
	Space::Print(argv[1]);
	Space::ConsoleStruct cs;
	cs.AddCommand("build",
				  [](Space::ConsoleStruct::AddArgCallback t) {
					  t("-o");
					  t("-t");
				  }
	);
	Space::Console cl(argv[1], cs);

	return 0;
}