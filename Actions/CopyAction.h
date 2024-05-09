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
class CopyAction :
    public Action
{
private:
	CFigure* Pfig;   //create a pointer to figure
	

public:
	CopyAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

