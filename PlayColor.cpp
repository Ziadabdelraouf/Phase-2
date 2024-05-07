#include "PlayColor.h"
void PlayColor::Execute() {
	ColorRNG::Execute();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (R->getFilledCount()==0)
	{
		return;
	}
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
		if (rcolor==pManager->GetFigure(x, y)->getFillClr())
		{
			score++;
		}
		//implement delete here
		if (pManager->GetFigure(x, y) != NULL) {
			R = pManager->GetFigure(x, y);
			pManager->usedBeforeDeleteInPlay(R);
			delete R;
			R == NULL;
			pManager->UpdateInterface();
		}
		//
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(hmark) + " and you made " + to_string(hmark - score) + " incorrect picks");
}
void PlayColor::ReadActionParameters() {}


PlayColor::PlayColor(ApplicationManager* pApp) :ColorRNG(pApp) {
	hmark = 0;
	score = 0;
}
