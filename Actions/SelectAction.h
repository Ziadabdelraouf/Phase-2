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

	//Reads click of user 
	virtual void ReadActionParameters();	
	
	//Selects figure and prints suitable information
	virtual void Execute();
};

#endif

