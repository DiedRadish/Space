set(Space_dir ${SpaceSrcDir}/Space)

set(Space_src
	${Space_dir}/Space.cpp
)
set(Space_h
	${Space_dir}/Space.h
)

add_executable(Space ${Space_src} ${Space_h})
target_link_libraries(Space Console)
target_link_libraries(Space Platform)