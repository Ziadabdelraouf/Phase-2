#include "ShapeRNG.h"
void ShapeRNG::Execute() {
	pManager->UnselectAll();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (0==pManager->GetFigureCount()) {
		pOut->PrintMessage("Error there is no shapes to start the play mode with");
		return;
	}
	pManager->randNumGenBothS(rshape);
	switch (rshape)
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
