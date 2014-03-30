#include "TimeLayer.h"


TimeLayer::TimeLayer(void)
{
	m_nCounter = 0;
}


TimeLayer::~TimeLayer(void)
{
}

CCScene* TimeLayer::scene()
{
	CCScene *scene = CCScene::create();
	TimeLayer *lay = TimeLayer::create();

	scene->addChild(lay);

	return scene;
}

bool TimeLayer::init()
{
	if(!CCLayer::init())
	{
		return false;
	}

	setUpView();
	//schedule
	this->schedule(schedule_selector(TimeLayer::timeCounting),1.0);
	return true;
}

void TimeLayer::timeCounting(float val)
{
	++ m_nCounter;
	//label
	CCLabelTTF *lb = (CCLabelTTF *)this->getChildByTag(15);
	char str[20];
	memset(str,0,sizeof(str));
	sprintf(str,"Time : %d",m_nCounter);
	lb->setString(str);
}

void TimeLayer::setUpView()
{
	//label
	CCLabelTTF *lb = CCLabelTTF::create("Time : 0","arial",24);
	lb->setAnchorPoint(CCPointZero);
	lb->setPosition(CCPointZero);

	this->addChild(lb,0,15);
}
