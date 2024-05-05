#pragma once
#include "ShapeRNG.h"
class PlayShape:public ShapeRNG
{
private:
	CFigure* temp[200];
	int score;  // player score
	int hmark;  // highest score (numbers of to be selected)
	int x;
	int y;
public:
	PlayShape(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
};
