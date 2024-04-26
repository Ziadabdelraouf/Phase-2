#pragma once
#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H
#include "Action.h"

class AddSquareAction:public Action{
private:
	Point C; //Square center
	GfxInfo SquareGfxInfo;
public:
	AddSquareAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
};
#endif
