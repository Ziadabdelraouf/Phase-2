#include "ShapeRNG.h"
#include "SwitchToPlay.h"

void ShapeRNG::Execute() {
	SwitchToPlay* pAct = new SwitchToPlay(pManager);
	pAct->Load();

	delete pAct;
	pAct = NULL;
	
	pManager->UnselectAll(); //prevents potential errors
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (0==pManager->GetFigureCount()) { //prevents program from running if there is no shapes and inform the user
		pOut->PrintMessage("Error there is no shapes to start the play mode with"); 
		return;
	}
	pManager->randNumGenBothS(rshape); //generate random number for shapes based on the existing figures
	switch (rshape)  //based on RNGshpae in defs.h
	{
	case triangle:
		pOut->PrintMessage("Select all triangles");
		break;
	case square:
		pOut->PrintMessage("Select all squares");
		break;
	case rectangle:
		pOut->PrintMessage("Select all rectangles");
		break;
	case circle:
		pOut->PrintMessage("Select all circles");
		break;
	case hexagon:
		pOut->PrintMessage("Select all hexagons");
		break;
	}
	return;
}

ShapeRNG::ShapeRNG(ApplicationManager* pApp) : Action(pApp){
}


void ShapeRNG::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	return;
}
