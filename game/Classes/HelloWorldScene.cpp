#include "HelloWorldScene.h"
#include "AboutLayer.h"
#include "SimpleAudioEngine.h"
#include "OptionLayer.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

 //   // add a label shows "Hello World"
 //   // create and initialize a label
 //   
 //   CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
 //   
 //   // position the label on the center of the screen
 //   pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
 //                           origin.y + visibleSize.height - pLabel->getContentSize().height));

 //   // add the label as a child to this layer
 //   this->addChild(pLabel, 1);


    setUpView();

    return true;
}

void HelloWorld::setUpView()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	this->setBackGroundImage("loading.png");
	//logo
	CCSprite *logo = CCSprite::create("logo.png");
	logo->setAnchorPoint(ccp(0.5,1.0));
	logo->setPosition(ccp(visibleSize.width/2,visibleSize.height-10));
	this->addChild(logo);

	//menu
	CCSprite *newGameNormal = CCSprite::create("menu.png",CCRectMake(0,0,126,33));
	CCSprite *newGamePressed = CCSprite::create("menu.png",CCRectMake(0,33,126,33));
	CCSprite *newGameDisabled = CCSprite::create("menu.png",CCRectMake(0,66,126,33));
	CCMenuItemSprite *newGame = CCMenuItemSprite::create(newGameNormal,newGamePressed,newGameDisabled);

	CCSprite *optionNormal = CCSprite::create("menu.png",CCRectMake(126,0,126,33));
	CCSprite *optionPressed = CCSprite::create("menu.png",CCRectMake(126,33,126,33));
	CCSprite *optionDisabled = CCSprite::create("menu.png",CCRectMake(126,66,126,33));
	CCMenuItemSprite *option = CCMenuItemSprite::create(optionNormal,optionPressed,optionDisabled,menu_selector(HelloWorld::MenuoptionCallBack));

	CCSprite *aboutNormal = CCSprite::create("menu.png",CCRectMake(256,0,126,33));
	CCSprite *aboutPressed = CCSprite::create("menu.png",CCRectMake(256,33,126,33));
	CCSprite *aboutDisabled = CCSprite::create("menu.png",CCRectMake(256,66,126,33));
	CCMenuItemSprite *about = CCMenuItemSprite::create(aboutNormal,aboutPressed,aboutDisabled,menu_selector(HelloWorld::MenuaboutCallBack));

	CCMenu *menu = CCMenu::create(newGame,option,about,NULL);
	menu->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	menu->alignItemsVerticallyWithPadding(10);
	this->addChild(menu);
}

void HelloWorld::setBackGroundImage(const char* imName)
{ 
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	// add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create(imName);

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
}


void HelloWorld::MenuaboutCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5,AboutLayer::scene()));
}

void HelloWorld::MenuoptionCallBack(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5,OptionLayer::scene()));
}

void HelloWorld::onEnter()
{
	CCLayer::onEnter();
	bool isPlayed;
	isPlayed = CCUserDefault::sharedUserDefault()->getBoolForKey("backmusic");
	//add music
	if(isPlayed)
	{
		if(!CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/mainMainMusic.mp3",true);      
		}
	}
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
