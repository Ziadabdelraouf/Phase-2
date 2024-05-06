#pragma once
#include "BothRNG.h"
class PlayBoth:public BothRNG
{private:
	int score;  // player score
	int x;
	int y;
public:
	PlayBoth(ApplicationManager * pApp);
	void Execute();
	void ReadActionParameters();
};

