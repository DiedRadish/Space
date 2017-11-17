#pragma once

#include<Shell/Shell.h>
#include<Preprocess/Preprocessor.h>
#include<Tools/Reader.h>

Space::Info BuildUnit(std::multimap<std::string, std::string>*);
Space::Info ToolUnit(std::multimap<std::string, std::string>* ArgvMap);
