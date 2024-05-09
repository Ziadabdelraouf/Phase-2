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

	//Reads file name
	virtual void ReadActionParameters();

	void SaveFigures(ofstream& fout);

	//Creates file and saves info of figures
	virtual void Execute();

};

#endif

