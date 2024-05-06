#include "PlayShape.h"


PlayShape::PlayShape(ApplicationManager* pApp) :ShapeRNG(pApp){
	hmark = 0;
	score = 0;
}


void PlayShape::Execute(){
	ShapeRNG::Execute();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	switch (rshape)
	{
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
			pIn->GetPointClicked(x, y);
		} while (pManager->GetFigure(x, y)==NULL);
		if (pManager->GetFigure(x, y)->getType()==rshape)
		{
			score++;
		}
		
	}
	pOut->ClearStatusBar();
	pOut->PrintMessage("you scored " + to_string(score) + " out of " + to_string(hmark));
}
void PlayShape::ReadActionParameters(){}
