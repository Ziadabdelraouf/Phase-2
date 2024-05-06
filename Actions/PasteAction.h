#pragma once
#include "Action.h"
#include "CutAction.h"
#include "DeleteAction.h"
#include "SelectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
class PasteAction :
    public Action
{
	CFigure* Pfig;
	Point P2 ;
	int x;

public:
    PasteAction(ApplicationManager*);
	// Reads parameters required for action to execute(code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
	
};

