
#include "cocos2d.h"

USING_NS_CC;

class PauseLayer : public CCLayerColor
{
public:
	PauseLayer(void);
	~PauseLayer(void);

	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(PauseLayer);

public:
	void setUpView();
	void MenuresumeCallBack(CCObject* pSender);
};