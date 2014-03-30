#pragma once

#include "cocos2d.h"

USING_NS_CC;

class Dlog
{
public:
	Dlog(void);
	~Dlog(void);
public:
	const static bool isLog = true;
	static void d(const char* str);
};
