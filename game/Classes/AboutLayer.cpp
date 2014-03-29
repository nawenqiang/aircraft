#include "AboutLayer.h"
#include "HelloWorldScene.h"

AboutLayer::AboutLayer(void)
{
}


AboutLayer::~AboutLayer(void)
{
}

CCScene* AboutLayer::scene()
{
	CCScene *scene = CCScene::create();
	AboutLayer *lay = AboutLayer::create();

	scene->addChild(lay);

	return scene;
}

bool AboutLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	return true;
}



void AboutLayer::setUpView()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	setBkIm("loading.png");

	//title
	CCSprite *sprite = CCSprite::create("menuTitle.png",CCRectMake(0.0,34.0,130.0,38.0));
	sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height-50));

	this->addChild(sprite);

	//text
	CCLabelBMFont *lb = CCLabelBMFont::create("this game is recoded by MyObject-C","arial-14.fnt");
	lb->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

	this->addChild(lb);
	//back label
    CCLabelTTF* backLb = CCLabelTTF::create("back", "Arial", 24);

	CCMenuItemLabel *lable = CCMenuItemLabel::create(backLb,this,menu_selector(AboutLayer::menuBackCallback));
	lable->setPosition(ccp(visibleSize.width - backLb->getContentSize().width/2,backLb->getContentSize().height/2));

	CCMenu *menu = CCMenu::create(lable,NULL);
	menu->setPosition(CCPointZero);

	this->addChild(menu);
	
}
void AboutLayer::setBkIm(const char* bkIm)
{   
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite *sprite = CCSprite::create(bkIm);
	sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

	this->addChild(sprite);
}

void AboutLayer::menuBackCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5,HelloWorld::scene()));
}
