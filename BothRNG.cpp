#include "BothRNG.h"
void BothRNG::Execute() {
	pManager->UnselectAll();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (0 != R->getFilledCount()) {
		do {
			srand(time(nullptr));
			rcolor = rand() % 6;
		} while ((rcolor == 0 && 0 == R->getBlackCount()) ||
			(1 == rcolor && 0 == R->getYellowCount()) ||
			(2 == rcolor && 0 == R->getOrangeCount()) ||
			(3 == rcolor && 0 == R->getRedCount()) ||
			(4 == rcolor && 0 == R->getGreenCount()) ||
			(5 == rcolor && 0 == R->getBlueCount()));
		switch (rcolor)
		{
		case pBLACK:
			s1 = "select all black ";
			break;
		case pYELLOW:
			s1 = "select all yellow ";
			break;
		case pORANGE:
			s1 = "select all orange ";
			break;
		case pRED:
			s1 = "select all red ";
			break;
		case pGREEN:
			s1 = "select all green ";
			break;
		case pBLUE:
			s1 = "select all blue ";
			break;
		}
		do {
			srand(time(nullptr));
			rshape = rand() % 5;
		} while ((0 == rshape && 0 == R->getTriTotalCount()) ||
			(1 == rshape && 0 == R->getSqrTotalCount()) ||
			(2 == rshape && 0 == R->getRecTotalCount()) ||
			(3 == rshape && 0 == R->getCircleTotalCount()) ||
			(4 == rshape && 0 == R->getHexTotalCount()));
		switch (rshape)
		{
		case triangle:
			s2 = "triangles";
			break;
		case square:
			s2 = "squares";
			break;
		case rectangle:
			s2 = "rectangles";
			break;
		case circle:
			s2 = "circles";
			break;
		case hexagon:
			s2 = "hexagons";
			break;
		}
		pOut->ClearStatusBar();
		string s3 = s1 + s2;
		pOut->PrintMessage(s1+s2);
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("there is no filled shape");
	}
	return;
}

BothRNG::BothRNG(ApplicationManager* pApp) : Action(pApp) {

}


void BothRNG::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	return;
}