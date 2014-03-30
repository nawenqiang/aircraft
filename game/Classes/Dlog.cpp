#include "Dlog.h"


Dlog::Dlog(void)
{
}


Dlog::~Dlog(void)
{
}

void Dlog::d(const char* str)
{
	if(isLog)
	{
		CCLog("Log====>%s",str);
	}
}
