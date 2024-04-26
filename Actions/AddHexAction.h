#pragma once
#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H
#include "Action.h"
class AddHexAction:public Action{
private:
	Point C; //Hexagon center
	GfxInfo HexagonGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add Hexagon to the ApplicationManager
	virtual void Execute();
};
#endif
