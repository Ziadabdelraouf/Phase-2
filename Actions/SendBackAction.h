#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include "../Figures/CFigure.h"
class SendBackAction :public Action{
public:
	SendBackAction(ApplicationManager* papp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
};

