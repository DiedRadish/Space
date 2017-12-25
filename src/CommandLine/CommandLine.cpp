#include "CommandLine.h"

#include<algorithm>

Space::CommandLine::CommandLine(std::string _Description, bool _HasHelp) :Description(_Description), HasHelp(_HasHelp) {
}

std::vector<Space::Unit>::iterator Space::CommandLine::AddUnit(Space::ID tID, Space::UnitCallback tCallback) {
	Units.push_back(Space::Unit(tID, {}, tCallback));
	return --Units.end();
}

bool Space::CommandLine::AddArgv(std::vector<Space::Unit>::iterator tUnit,
								 Space::ID tID,
								 std::string tDefaultValue,
								 Space::ArgvType tType,
								 bool tArrayType,
								 bool tAllowDefaultValue) {
	tUnit->Argvs.push_back(Space::Argv(tID, tDefaultValue, tType, tArrayType, tAllowDefaultValue));
	return true;
}

Space::Info Space::CommandLine::Scan(const std::vector<std::string>& CmdLine) {
	std::string nName;
	if(CmdLine.size() < 2) {
		return Space::Info(Space::InfoCode::MissingUnit, "Cannot find unit name.");
	}

	nName = CmdLine[1];
	if(nName == "help") {
		return Space::Info(Space::InfoCode::Success, HelpMessage());
	}

	//由于上边进行了验证，所以CmdLine[1]保证存在
	std::vector<Space::Unit>::iterator nUnit = std::find(Units.begin(), Units.end(), nName);
	if(nUnit == Units.end()) {
		return Space::Info(Space::InfoCode::UnitNotFound, "Unit cannot find.");
	}

	std::multimap < std::string, std::string > tMap;
	for(int i = 2; i < CmdLine.size(); ++i) {
		nName = CmdLine[i];

		if(nName == "-help") {
			return Space::Info(Space::InfoCode::Success, HelpMessage(nUnit));
		}

		std::vector<Space::Argv>::iterator nArgv = std::find(nUnit->Argvs.begin(), nUnit->Argvs.end(), nName);
		if(nArgv == nUnit->Argvs.end()) {
			return Space::Info(Space::InfoCode::ArgvNotFound, "Argv cannot find.");
		}

		if(tMap.find(nName) != tMap.end() && !nArgv->ArrayType) {
			return Space::Info(Space::InfoCode::ArgvRepeated, "Too much argv.");
		}

		if(nArgv->HasValue) {
			if(i + 1 >= CmdLine.size()) {
				return Space::Info(Space::InfoCode::MissingValue, "Cannot find value.");
			}
			tMap.insert(std::make_pair(nName, CmdLine[i + 1]));
			i++;
		}
		else {
			tMap.insert(std::make_pair(nName, ""));
		}
	}
	for(auto &nArgv : nUnit->Argvs) {
		auto n = tMap.find(nName);
		if(n == tMap.end()) {
			if(nArgv.AllowEmpty) {
				tMap.insert(std::make_pair(nArgv.ID.Name, nArgv.DefaultValue));
			}
			else {
				return Space::Info(Space::InfoCode::MissingArgv, "Cannot find argv.");
			}
		}
	}
	return nUnit->Callback(tMap);
}

std::string Space::CommandLine::HelpMessage(std::vector<Space::Unit>::iterator tUnit) {
	std::string tMsg;

	tMsg += (std::string)tUnit->ID += '\n';

	for(auto& nArgv : tUnit->Argvs) {
		tMsg += std::string("\t");

		tMsg.append(nArgv.AllowEmpty ? "[" : "<")
			.append(nArgv.HasValue ? "  " : "")
			.append(nArgv.AllowEmpty ? "]" : ">")
			.append(nArgv.AllowRepeat ? ".." : "");

		tMsg += "\t";

		tMsg += (std::string)nArgv.ID += '\n';
	}
	return tMsg;
}

std::string Space::CommandLine::HelpMessage() {
	std::string tMsg;

	tMsg += this->Description += '\n';

	std::vector<Space::Unit>::iterator nUnit = this->Units.begin();
	while(nUnit < this->Units.end()) {
		tMsg += HelpMessage(nUnit) += '\n';
		nUnit++;
	}

	return tMsg;
}