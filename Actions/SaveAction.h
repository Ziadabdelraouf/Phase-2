#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"


class SaveAction : public Action
{
private:
	string str;
public:
	SaveAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif

