#pragma once

#include "cocos2d.h"
#include "WarriorBulletManager.h"
#include "WarriorLayer.h"

USING_NS_CC;

class GamingLayer : public CCLayer
{
public:
	GamingLayer(void);
	~GamingLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(GamingLayer);

public:
	void setUpView();
	void setBkIm(const char* bkIm);
	void menuBackCallback(CCObject* pSender);
	void backgroundScrool(float val);
	void MenupauseCallBack(CCObject* pSender);
	void addNewBullet(float val);
private:
	WarriorBulletManager *m_WarriorBulletMgr;
	WarriorLayer *m_warrior;
};