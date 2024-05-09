#pragma once
#include "Action.h"
class SwitchToDraw : public Action
{
public:
	SwitchToDraw(ApplicationManager* pApp); //conistructor

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
};

