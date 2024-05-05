#include "PlayColor.h"
void PlayColor::Execute() {
	int j = 0;
	ColorRNG::Execute();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	switch (rcolor)
	{
	case pBLACK:
		hmark = R->getBlackCount();
		break;
	case pYELLOW:
		hmark = R->getYellowCount();
		break;
	case pORANGE:
		hmark = R->getOrangeCount();
		break;
	case pRED:
		hmark = R->getRedCount();
		break;
	case pGREEN:
		hmark = R->getGreenCount();
		break;
	case pBLUE:
		hmark = R->getBlueCount();
		break;
	}
	
	for (int i = 0; i < hmark; i++)
	{
		do {
			pIn->GetPointClicked(x, y);
		} while (pManager->GetFigure(x, y) == NULL);
		if (pManager->GetFigure(x, y)->getFillClr() == rcolor)
		{
			score++;
		}

		temp[j++] = pManager->GetFigure(x, y);

	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(hmark));
}
void PlayColor::ReadActionParameters() {}


PlayColor::PlayColor(ApplicationManager* pApp) :ColorRNG(pApp) {
	hmark = 0;
	score = 0;
}