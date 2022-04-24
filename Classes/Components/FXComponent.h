#ifndef FX_COMPONENT_H__
#define FX_COMPONENT_H__

#include <vector>
#include "cocos2d.h"
#include "Components/Enums.h"

class FXComponent final
{
public:
	FXComponent(bool FXOn)
	{
#ifdef _DEBUG
		cocos2d::log("[FXComponent] Constructor");
#endif
		_FXOn = FXOn;
	}

	~FXComponent()
	{
#ifdef _DEBUG
		cocos2d::log("[FXComponent] Destructor");
#endif
	}	

	std::vector<FXS> _FXs;

	bool _FXOn;
};

#endif // !FX_COMPONENT_H__