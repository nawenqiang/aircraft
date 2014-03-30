#include "ScoreLayer.h"


ScoreLayer::ScoreLayer(void)
{
}


ScoreLayer::~ScoreLayer(void)
{
}




CCScene* ScoreLayer::scene()
{
	CCScene *scene = CCScene::create();
	ScoreLayer *lay = ScoreLayer::create();

	scene->addChild(lay);

	return scene;
}

bool ScoreLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();

	return true;
}

void ScoreLayer::setUpView()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	//label
	CCLabelTTF *lb = CCLabelTTF::create("Score : 20","arial",24);
	lb->setAnchorPoint(CCPointZero);
	lb->setPosition(CCPointZero);
	this->addChild(lb);
}

