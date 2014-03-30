#pragma once


#include "cocos2d.h"

USING_NS_CC;

class ScoreLayer : public CCLayer
{
public:
	ScoreLayer(void);
	~ScoreLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(ScoreLayer);

public:
	void setUpView();		
};