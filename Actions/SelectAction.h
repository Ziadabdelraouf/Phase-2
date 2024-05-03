#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"


class SelectAction:public Action
{
private:
	Point P1;
	CFigure* pFig;
public:
	//Constructor for SelectAction class
	SelectAction(ApplicationManager* pApp); 


	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
	
	


	
	//Execute action (code depends on action type)
	virtual void Execute();

};

#endif

