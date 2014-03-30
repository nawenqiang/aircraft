#include "PauseLayer.h"
#include "SimpleAudioEngine.h"


PauseLayer::PauseLayer(void)
{
}


PauseLayer::~PauseLayer(void)
{
}

CCScene* PauseLayer::scene()
{
	CCScene *scene = CCScene::create();
	PauseLayer *lay = PauseLayer::create();

	scene->addChild(lay);

	return scene;
}

bool PauseLayer::init()
{
	if(!CCLayerColor::initWithColor(ccc4(0,0,0,50)))
	{
		return false;
	}

	setUpView();

	return true;
}

void PauseLayer::setUpView()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	//menu
	CCMenuItemImage *resumeItem = CCMenuItemImage::create("play.png","play.png",this,
		menu_selector(PauseLayer::MenuresumeCallBack));
	resumeItem->setPosition(visibleSize.width/2,visibleSize.height/2);

	CCMenu *menu = CCMenu::create(resumeItem,NULL);
	menu->setPosition(CCPointZero);

	this->addChild(menu);	
}

void PauseLayer::MenuresumeCallBack(CCObject* pSender)
{
	CCLayer *farther = (CCLayer *)this->getParent();
	//hide pause layer
	farther->getChildByTag(99)->setVisible(false);
	//enable pause menu
	((CCMenu*)farther->getChildByTag(156))->setEnabled(true);
	//resume
	CCDirector::sharedDirector()->resume();
	//background music
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
}
