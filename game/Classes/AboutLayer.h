#pragma once

#include "cocos2d.h"

USING_NS_CC;

class AboutLayer : CCLayer
{
public:
	AboutLayer(void);
	~AboutLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(AboutLayer);

public:
	void setUpView();
	void setBkIm(const char* bkIm);
	void menuBackCallback(CCObject* pSender);
		
};

