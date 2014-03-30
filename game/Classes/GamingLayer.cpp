#include "GamingLayer.h"
#include "ScoreLayer.h"
#include "TimeLayer.h"
#include "PauseLayer.h"
#include "SimpleAudioEngine.h"


GamingLayer::GamingLayer(void)
{
}


GamingLayer::~GamingLayer(void)
{
}



CCScene* GamingLayer::scene()
{
	CCScene *scene = CCScene::create();
	GamingLayer *lay = GamingLayer::create();

	scene->addChild(lay);

	return scene;
}

bool GamingLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	//schedule
	this->schedule(schedule_selector(GamingLayer::backgroundScrool),0.1f);
	this->schedule(schedule_selector(GamingLayer::addNewBullet),0.5f);

	//score layer
	ScoreLayer *scoreLy = ScoreLayer::create();

	//layer的anchorpoint对position无影响
	scoreLy->setPosition(ccp(10.0,CCDirector::sharedDirector()->getWinSize().height-27));
	this->addChild(scoreLy);

	//time layer
	TimeLayer *timeLy = TimeLayer::create();
	timeLy->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 109,CCDirector::sharedDirector()->getWinSize().height-27));
	this->addChild(timeLy);

	return true;
}

void GamingLayer::setUpView()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	//background
	setBkIm("bg01.jpg");

	//menu pause
	CCMenuItemImage *pauseItem = CCMenuItemImage::create("pause.png","pause.png",this,
		menu_selector(GamingLayer::MenupauseCallBack));
	pauseItem->setAnchorPoint(CCPointZero);
	pauseItem->setPosition(ccp(visibleSize.width - 40,0.0));

	CCMenu *menu = CCMenu::create(pauseItem,NULL);
	menu->setPosition(CCPointZero);
	this->addChild(menu,1,156);	
	
	//add pause layer and hide it
	PauseLayer *pauseLy = PauseLayer::create();
	CCSize pauseLySize = pauseLy->getContentSize();
	pauseLy->setPosition(CCPointZero);
	pauseLy->setVisible(false);
	this->addChild(pauseLy,10,99);

	//warrior 
	m_warrior = WarriorLayer::create();
	m_warrior->setPosition(CCPointZero);
	this->addChild(m_warrior);

	//WarriorBulletManager layer
	m_WarriorBulletMgr = WarriorBulletManager::create();
	this->addChild(m_WarriorBulletMgr,1);
}

void GamingLayer::MenupauseCallBack(CCObject* pSender)
{
	this->getChildByTag(99)->setVisible(true);
	//pause
	CCDirector::sharedDirector()->pause();
	//pause menu
	((CCMenu*)this->getChildByTag(156))->setEnabled(false);
	//background music
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}

}


void GamingLayer::backgroundScrool(float val)
{
	CCSprite *bk1 = (CCSprite *)getChildByTag(11);
	CCSprite *bk2 = (CCSprite *)getChildByTag(12);

	bk1->setPositionY(bk1->getPositionY() - 10.0);
	bk2->setPositionY(bk1->getPositionY() + 576);

	if(bk2->getPositionY() <= 0)
	{
		bk1->setPositionY(0.0);
	}

}

void GamingLayer::setBkIm(const char* bkIm)
{   
	CCSprite *bk1 = CCSprite::create(bkIm);
	CCSprite *bk2 = CCSprite::create(bkIm);

	bk1->setAnchorPoint(CCPointZero);
	bk2->setAnchorPoint(CCPointZero);

	bk1->setPosition(CCPointZero);
	bk2->setPosition(ccp(0.0,576.0));

	this->addChild(bk1,0,11);
	this->addChild(bk2,0,12);
}



void GamingLayer::menuBackCallback(CCObject* pSender)
{
//	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5,HelloWorld::scene()));
}

void GamingLayer::addNewBullet(float val)
{
	m_WarriorBulletMgr->addNewBullet(m_warrior->getWarriorPos());
}
