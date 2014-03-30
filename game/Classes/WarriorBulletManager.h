
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class WarriorBulletManager : public  CCLayer
{
public:
	WarriorBulletManager(void);
	~WarriorBulletManager(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(WarriorBulletManager);

public:
	void setUpView();	
	void addNewBullet(CCPoint point);
	void moveAllBullet(float val);

private:
	CCSpriteBatchNode *m_nBulletBatchNode;
	CCArray *m_pBulletArr;
};