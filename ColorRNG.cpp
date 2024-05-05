#include "ColorRNG.h"
void ColorRNG::Execute() {
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
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all black filled shapes");
			break;
		case pYELLOW:
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all yellow filled shapes");
			break;
		case pORANGE:
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all orange filled shapes");
			break;
		case pRED:
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all red filled shapes");
			break;
		case pGREEN:
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all green filled shapes");
			break;
		case pBLUE:
			pOut->ClearStatusBar();
			pOut->PrintMessage("pick all blue filled shapes");
			break;
		}
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("there is no filled shape");
	}
	return;
}

ColorRNG::ColorRNG(ApplicationManager* pApp) : Action(pApp) {

}


void ColorRNG::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	return;
}