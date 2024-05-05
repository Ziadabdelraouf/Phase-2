#include "RNG.h"
void RNG::shapeRNG() {
	if (0 == rshape) {
		pOut->ClearStatusBar();
		pOut->PrintMessage("Error there is no shapes to start the play mode with");
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
int RNG::colorRNG() {
    srand(time(nullptr));
    rcolor = rand() % 6;
    return rcolor;
}
RNG::RNG() {
    rshape = -1;
    rcolor = -1;
}