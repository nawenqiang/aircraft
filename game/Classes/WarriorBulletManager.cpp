#include "WarriorBulletManager.h"


WarriorBulletManager::WarriorBulletManager(void)
{
}


WarriorBulletManager::~WarriorBulletManager(void)
{
}

CCScene* WarriorBulletManager::scene()
{
	CCScene *scene = CCScene::create();
	WarriorBulletManager *lay = WarriorBulletManager::create();

	scene->addChild(lay);

	return scene;
}

bool WarriorBulletManager::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	//init member
	m_pBulletArr = CCArray::create();
	m_pBulletArr->retain();

	//schedule
//	this->schedule(schedule_selector(WarriorBulletManager::addNewBullet),0.8f);
	this->schedule(schedule_selector(WarriorBulletManager::moveAllBullet),0.1f);

	return true;
}



void WarriorBulletManager::setUpView()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	//add plist file to CCSpriteFrameCache
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist","bullet.png");

	m_nBulletBatchNode = CCSpriteBatchNode::create("bullet.png");

	//为m_nBulletBatchNode加光晕效果
	ccBlendFunc cb = {GL_SRC_ALPHA,GL_ONE};
	m_nBulletBatchNode->setBlendFunc(cb);
	this->addChild(m_nBulletBatchNode);

}

void WarriorBulletManager::addNewBullet(CCPoint point)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite *sprite = CCSprite::createWithSpriteFrameName("W1.png");
	sprite->setPosition(point);

	m_pBulletArr->addObject(sprite);
	m_nBulletBatchNode->addChild(sprite);
}

void WarriorBulletManager::moveAllBullet(float val)
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCObject *obj;
	CCARRAY_FOREACH(m_pBulletArr,obj)
	{
		CCSprite *sprite = (CCSprite *)obj;
		sprite->setPositionY(sprite->getPositionY()+10);
		if(sprite->getPositionY() > visibleSize.height)
		{
			m_nBulletBatchNode->removeChild(sprite,true);
			m_pBulletArr->removeObject(obj);
		}
	}
}

