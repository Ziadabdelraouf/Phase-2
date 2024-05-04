#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "SelectAction.h"
#include "../Figures/CFigure.h"


class SaveAction: public Action{
private:
	CFigure* pFig;
	string str;
public:
	SaveAction(ApplicationManager* pApp);
	
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

