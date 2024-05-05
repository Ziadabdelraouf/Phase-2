#include "ShapeRNG.h"
void ShapeRNG::Execute() {
	pManager->UnselectAll();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (0==pManager->GetFigureCount()) {
		pOut->ClearStatusBar();
		pOut->PrintMessage("Error there is no shapes to start the play mode with");
		return;
	}
	do {
		srand(time(nullptr));
		rshape = rand() % 5;
	} while ((0 == rshape && 0 == R->getTriTotalCount()) ||
		(1 == rshape && 0 == R->getSqrTotalCount()) ||
		(2 == rshape && 0 == R->getRecTotalCount()) ||
		(3 == rshape && 0 == R->getCircleTotalCount()) ||
		(4 == rshape && 0 == R->getHexTotalCount()));
	pOut->ClearStatusBar();
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
