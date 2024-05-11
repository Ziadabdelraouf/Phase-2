#pragma once
#include "BothRNG.h"
class PlayBoth:public BothRNG
{private:
	int score;  // player score
	int x;      // it is the x of selected figure 
	int y;      // it is the y of selected figure 
public:
	PlayBoth(ApplicationManager * pApp);
	void Execute();
	void ReadActionParameters();
};

