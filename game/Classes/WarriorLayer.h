
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
	//void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent); 
	bool ccTouchBegan(CCTouch  *pTouches, CCEvent *pEvent); 
	CCPoint getWarriorPos();
	void registerWithTouchDispatcher(void);

private:
	CCSprite *m_pWarrior;
};