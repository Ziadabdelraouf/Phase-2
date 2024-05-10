#pragma once
#include "ColorRNG.h"

class PlayColor:public ColorRNG
{private:
	int score;  // player score
	int hmark;  // highest score (numbers of shapes to be selected)
	int x;
	int y;
public:
	PlayColor(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
};
