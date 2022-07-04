#pragma once
#include "Action.h"

class SwithchToPlayMode : public Action
{
public:
	SwithchToPlayMode(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SwithchToPlayMode();
};


