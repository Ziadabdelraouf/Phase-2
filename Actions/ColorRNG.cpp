#include "ColorRNG.h"
#include "SwitchToPlay.h"

void ColorRNG::Execute() {

	SwitchToPlay* pAct = new SwitchToPlay(pManager);
	pAct->Load();

	delete pAct;
	pAct = NULL;


	pManager->UnselectAll(); //used to prevent possible errors
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (0 != R->getFilledCount()) {
		pManager->randNumGenBoth(rcolor); //generate random number based on the figures in the figure list 
		switch (rcolor)    //the switch is based on RNGcolor in defs.h
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
