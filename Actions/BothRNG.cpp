#include "BothRNG.h"
#include "SwitchToPlay.h"

void BothRNG::Execute() {

	SwitchToPlay* pAct = new SwitchToPlay(pManager);
	pAct->Load();

	delete pAct;
	pAct = NULL;


	pManager->UnselectAll();     //prevents potential errors
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (0 != R->getFilledCount()) {
		pManager->randNumGenBoth(rshape, rcolor); //get random generated number for shape and color
		num = pManager->getRandNumcount(rshape, rcolor); //get the number of figure with specific characteristics 
		switch (rshape)  //based on RNGshape in defs.h
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
		switch (rcolor)   //based on RNGcolor in defs.h
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
		pOut->ClearStatusBar();
		pOut->PrintMessage(s1 + s2);
	}
	else {
		pOut->ClearStatusBar();
		pOut->PrintMessage("there is no filled shape");
	}
	return;
}

BothRNG::BothRNG(ApplicationManager* pApp) : Action(pApp) {
	num = 0;
}


void BothRNG::ReadActionParameters() {
}
