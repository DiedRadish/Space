set(Console_dir ${SpaceSrcDir}/Console)

set(Console_src
	${Console_dir}/Console.cpp
	${Console_dir}/ConsoleStruct.cpp
)
set(Console_h 
	${Console_dir}/Console.h
	${Console_dir}/ConsoleStruct.h
)

add_library(Console STATIC ${Console_src} ${Console_h})