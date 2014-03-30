#include "OptionLayer.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"


OptionLayer::OptionLayer(void)
{
}


OptionLayer::~OptionLayer(void)
{
}


CCScene* OptionLayer::scene()
{
	CCScene *scene = CCScene::create();
	OptionLayer *lay = OptionLayer::create();

	scene->addChild(lay);

	return scene;
}

bool OptionLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	return true;
}

void OptionLayer::setUpView()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//background
	setBkIm("loading.png");

	//title
	CCSprite *title = CCSprite::create("menuTitle.png",CCRectMake(0.0,0.0,135.0,35.0));
	title->setPosition(ccp(visibleSize.width/2,visibleSize.height-50));

	this->addChild(title);

	//add music toggle
	CCMenuItemToggle *musicTrigger = CCMenuItemToggle::createWithTarget(this,menu_selector(OptionLayer::musicTriggerCallback),CCMenuItemFont::create("Music : 0n"),
		CCMenuItemFont::create("Music : Off"),NULL);
	
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		musicTrigger->setSelectedIndex(0);
	}
	else
	{
		musicTrigger->setSelectedIndex(1);
	}
	musicTrigger->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

    CCLabelTTF* backLb = CCLabelTTF::create("back", "Arial", 24);

	CCMenuItemLabel *lable = CCMenuItemLabel::create(backLb,this,menu_selector(OptionLayer::menuBackCallback));
	lable->setPosition(ccp(visibleSize.width - backLb->getContentSize().width/2,backLb->getContentSize().height/2));

	CCMenu *menu = CCMenu::create(musicTrigger,lable,NULL);
	menu->setPosition(CCPointZero);

	this->addChild(menu);
	
}
void OptionLayer::setBkIm(const char* bkIm)
{   
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite *sprite = CCSprite::create(bkIm);
	sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

	this->addChild(sprite);
}

void OptionLayer::musicTriggerCallback(CCObject* pSender)
{
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		CCUserDefault::sharedUserDefault()->setBoolForKey("backmusic",false);
	}
	else
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/mainMainMusic.mp3",true);      
		CCUserDefault::sharedUserDefault()->setBoolForKey("backmusic",true);
	}
}

void OptionLayer::menuBackCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5,HelloWorld::scene()));
}