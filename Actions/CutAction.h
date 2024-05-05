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
	SelectAction* pSelct;
	 CFigure* Pfig;
	bool IsCut ;
	static color tempFill;
	static color tempDraw;
	static bool WasFill;
public:
	CutAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	void UnCut();
	
	
};


