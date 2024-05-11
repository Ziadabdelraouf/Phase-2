#pragma once
#include "..\ApplicationManager.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

class FillAction: public Action{
private:
	CFigure* PFig;   //Pointer to the figure that the action will implemented on.
	color color;   //The selected color.
public:
	FillAction(ApplicationManager* papp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	~FillAction();
};

