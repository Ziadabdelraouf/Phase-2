#include "ColorRNG.h"
void ColorRNG::Execute() {
	pManager->UnselectAll();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (0 != R->getFilledCount()) {
		pManager->randNumGenBoth(rcolor);
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
