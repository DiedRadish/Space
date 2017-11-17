#pragma once
namespace Space {
class A {
public:
	virtual bool hasValue() = 0;
	virtual int getValue() = 0;
};

class BfromA :public A {
public:
	int v;
	BfromA(int i) {
		v = i;
	}
	bool hasValue() {
		return true;
	}

	int getValue() {
		return v;
	}
};

class CfromA :public A {
public:
	bool hasValue() {
		return false;
	}

	int getValue() {
		return 8616;
	}
};
}