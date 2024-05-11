#include "PlayColor.h"

void PlayColor::Execute() {
	ColorRNG::Execute(); //execute the code from colorRNG 
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (R->getFilledCount()==0)  //prevent the program from working if there is no filled shapes
	{
		return;
	}
	switch (rcolor) //based on RNGcolor in defs.h
	{ //the switch get the highest score (number of colored shapes with the wanted color)
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
			pIn->GetPointClicked(x, y); //it get where the user clicked
		} while (pManager->GetFigure(x, y) == NULL);
		if (rcolor==pManager->GetFigure(x, y)->getFillClr()) // condition to check if the selected figure is right
		{
			score++; //inc. the score if the condition is right
		}
		//implement delete here
		if (pManager->GetFigure(x, y) != NULL) {
			R = pManager->GetFigure(x, y);
			pManager->usedBeforeDeleteInPlay(R); //used to make the selected figure the last one in figlist and dec the count of figures
			delete R;
			R == NULL;
			pManager->UpdateInterface(); //updates the interface to make the user see that the obj is deleted
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
