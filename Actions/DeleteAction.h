#pragma once
#ifndef DELETE_ACTION_H
#define DELETE_RECT_ACTION_H
#include "Action.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Action.h"
#include "..\Figures\CFigure.h"

class DeleteAction :
    public Action
{
private:
	SelectAction* pSelct;
	CFigure** Pfig;
	
public:
    DeleteAction(ApplicationManager*pApp);

	virtual void ReadActionParameters() ;

	virtual void Execute();

};
#endif
