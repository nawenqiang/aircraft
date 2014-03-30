
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class TimeLayer : public  CCLayer
{
public:
	TimeLayer(void);
	~TimeLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(TimeLayer);

public:
	void setUpView();	
	void timeCounting(float val);

private:
	int m_nCounter;
};