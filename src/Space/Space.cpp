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
	Space::Console cl(argv[1]);

	return 0;
}