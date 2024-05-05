#pragma once
#include "Action.h"

class LoadAction : public Action
{
private:
	string str;
public:
	LoadAction(ApplicationManager* pApp);

	//Reads file name
	virtual void ReadActionParameters();

	//Creates file and saves info of figures
	virtual void Execute();

};

