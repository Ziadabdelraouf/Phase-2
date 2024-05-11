#include "PlayShape.h"
#include "SwitchToPlay.h"

PlayShape::PlayShape(ApplicationManager* pApp) :ShapeRNG(pApp){
	hmark = 0;
	score = 0;
}


void PlayShape::Execute(){
	ShapeRNG::Execute(); //execute the code from shapeRNG
	if (0==pManager->GetFigureCount()) //prevents the program from running if the count of figures is zero
	{
		return;
	}
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	switch (rshape) //based on RNGshape in defs.h
	{ //The switch gets the highest score the user can get (number of figure with the wanted type)
	case triangle:
		hmark = R->getTriTotalCount();
		break;
	case square:
		hmark = R->getSqrTotalCount();
		break;
	case rectangle:
		hmark = R->getRecTotalCount();
		break;
	case circle:
		hmark = R->getCircleTotalCount();
		break;
	case hexagon:
		hmark = R->getHexTotalCount();
		break;
	}
	for (int i = 0; i < hmark; i++)
	{
		do {
			pIn->GetPointClicked(x, y); //gets user click location
		} while (pManager->GetFigure(x, y)==NULL);
		if (pManager->GetFigure(x, y)->getType()==rshape) //check that the figure clicked is right 
		{
			score++; //inc. the score if the user clicked right
		}
		//implement delete here
		if (pManager->GetFigure(x, y) != NULL) {
			R = pManager->GetFigure(x, y);
			pManager->usedBeforeDeleteInPlay(R); //make the obj last at the figlist before deleting
			delete R;
			R == NULL;
			pManager->UpdateInterface(); //update the interface so deleted obj don't appear
		}
		//
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(hmark)+" and you made "+to_string(hmark-score)+" incorrect picks");
}
void PlayShape::ReadActionParameters(){}
