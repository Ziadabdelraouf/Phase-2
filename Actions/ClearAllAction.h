#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "SelectAction.h"
#include "../Figures/CFigure.h"


class ClearAllAction: public Action{
private:
	CFigure* pFig;
public:
	ClearAllAction(ApplicationManager* pApp);
	
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

