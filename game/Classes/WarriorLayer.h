
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class WarriorLayer : public  CCLayer
{
public:
	WarriorLayer(void);
	~WarriorLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(WarriorLayer);

public:
	void setUpView();	
	void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent); 
	CCPoint getWarriorPos();
private:
	CCSprite *m_pWarrior;
};