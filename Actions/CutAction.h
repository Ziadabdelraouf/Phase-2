#pragma once
#include "Action.h"
#include "DeleteAction.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"

class CutAction :
    public Action
{
	static CFigure* Pfig;   //create a pointer to figrue
	CFigure* Previous=NULL;	 //create a temporary pointer to figure and intialize it to NULL
	
	//data members to return previously cut figrue to it state
	static color tempFill;
	static color tempDraw;
	static bool WasFill;
public:
	CutAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	void UnCut();
	
	
};


