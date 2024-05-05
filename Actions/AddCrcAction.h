#pragma once
#ifndef ADD_Crc_ACTION_H
#define ADD_Crc_ACTION_H
#include "Action.h"
class AddCrcAction: public Action{
private:
	Point C; //Circle center
	Point R; //Circle radius
	int radius;
	GfxInfo CircleGfxInfo;
public:
	AddCrcAction(ApplicationManager* pApp); //conistructor

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
};
#endif