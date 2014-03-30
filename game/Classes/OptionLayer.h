#pragma once

#include "cocos2d.h"

USING_NS_CC;

class OptionLayer : public CCLayer
{
public:
	OptionLayer(void);
	~OptionLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(OptionLayer);

public:
	void setUpView();
	void setBkIm(const char* bkIm);
	void musicTriggerCallback(CCObject* pSender);
	void menuBackCallback(CCObject* pSender);
		
};