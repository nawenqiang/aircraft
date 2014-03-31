#include "WarriorLayer.h"


WarriorLayer::WarriorLayer(void)
{
	m_pWarrior = NULL;
}


WarriorLayer::~WarriorLayer(void)
{
}


CCScene* WarriorLayer::scene()
{
	CCScene *scene = CCScene::create();
	WarriorLayer *lay = WarriorLayer::create();

	scene->addChild(lay);

	return scene;
}

bool WarriorLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	//enable touch
	this->setTouchEnabled(true);

	return true;
}


void WarriorLayer::setUpView()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//warrior
	m_pWarrior = CCSprite::create("ship01.png",CCRectMake(60.0,0.0,60.0,43.0));
	m_pWarrior->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	this->addChild(m_pWarrior);

	//animation
	CCAnimation *animation = CCAnimation::create();
	animation->setDelayPerUnit(0.3f);

	animation->addSpriteFrame(CCSpriteFrame::create("ship01.png",CCRectMake(60.0,0.0,60.0,43.0)));
	animation->addSpriteFrame(CCSpriteFrame::create("ship01.png",CCRectMake(0.0,0.0,60.0,43.0)));

	CCAnimate *animate = CCAnimate::create(animation);
	m_pWarrior->runAction(CCRepeatForever::create(animate));
}



//void WarriorLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) 
//{
//	CCTouch *touch = (CCTouch *)pTouches->anyObject();
//	CCPoint locInVw = touch->getLocationInView();
//	CCPoint locInGl = CCDirector::sharedDirector()->convertToGL(locInVw);
//
//	CCMoveTo *move = CCMoveTo::create(0.5f,locInGl);
//	m_pWarrior->runAction(move);
//}

void WarriorLayer::registerWithTouchDispatcher(void)
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool WarriorLayer::ccTouchBegan(CCTouch  *pTouches, CCEvent *pEvent)
{
	m_pWarrior->stopAllActions();
	CCMoveTo *move = CCMoveTo::create(0.5f,pTouches->getLocation());
	m_pWarrior->runAction(move);	
	return true;
}

CCPoint WarriorLayer::getWarriorPos()
{
	return m_pWarrior->getPosition();
}
