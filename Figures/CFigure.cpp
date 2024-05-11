#include "CFigure.h"
#include "../ApplicationManager.h"

CFigure::CFigure(GfxInfo FigureGfxInfo, int id)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false; //default status is not-selected
	ID = id; //set id of the figure
}
 
//int CFigure::IDCount = 0; //intialise figure id counter
int CFigure::RecTotalCount = 0; //initialise total count of rectangles
int CFigure::RecSelectedCount = 0; //initialise count of selected rectangles
int CFigure::SqrTotalCount = 0; //initialise total count of squares
int CFigure::SqrSelectedCount = 0; //initialise count of selected squares
int CFigure::TriTotalCount = 0; //initialise total count of triangles
int CFigure::TriSelectedCount = 0; //initialise count of selected triangles
int CFigure::HexTotalCount = 0; //initialise total count of hexagons
int CFigure::HexSelectedCount = 0; //initialise count of selected hexagons
int CFigure::CircleTotalCount = 0; //initialise total count of circles
int CFigure::CircleSelectedCount = 0; //initialise count of selected circles

// temporary changes by omar
int CFigure::blackCount = 0;      //initialise count of black filled figures
int CFigure::yellowCount = 0;     //initialise count of yellow filled figures
int CFigure::orangeCount = 0;    //initialise count of oragne filled figures
int CFigure::redCount = 0;      //initialise count of red filled figures
int CFigure::blueCount = 0;      //initialise count of blue filled figures
int CFigure::greenCount = 0;    //initialise count of green filled figures
int CFigure::filledCount = 0;   //initialise count of filled figures 
//

bool CFigure::IsSelected() const
{
	if (!NULL) {
		return Selected;
	}
	else return false;
}

bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled ;
}





void CFigure::ChngDrawClr(color Dclr)
{	
	FigGfxInfo.DrawClr = Dclr;
}


void CFigure::ChngFillClr(color Fclr)
{	
	//    temporary changes by Omar
if (FigGfxInfo.isFilled == true) {  // dec the num of the old fill color if it was filled
	if (BLACK == FigGfxInfo.FillClr)
		blackCount--;
	else if (YELLOW == FigGfxInfo.FillClr)
		yellowCount--;
	else if (ORANGE == FigGfxInfo.FillClr)
		orangeCount--;
	else if (BLUE == FigGfxInfo.FillClr)
		blueCount--;
	else if (GREEN == FigGfxInfo.FillClr)
		greenCount--;
	else if (RED == FigGfxInfo.FillClr)
		redCount--;
}
else {
	filledCount++;
}

if (BLACK == Fclr)                          // inc the num of the fill color for the static member 
	blackCount++;
else if (YELLOW == Fclr)
	yellowCount++;
else if (ORANGE == Fclr)
	orangeCount++;
else if (BLUE == Fclr)
	blueCount++;
else if (GREEN == Fclr)
	greenCount++;
else if (RED == Fclr)
	redCount++;
//
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
	if (LIGHTGOLDENRODYELLOW == Fclr) {
		filledCount--;
		FigGfxInfo.isFilled = false;
	}
}

int CFigure::getRecTotalCount()
{
	return RecTotalCount; //returns total number of rectangles
}

int CFigure::getRecSelectedCount()
{
	return RecSelectedCount; //returns number of selected rectangles
}

int CFigure::getSqrTotalCount()
{
	return SqrTotalCount;
}

int CFigure::getSqrSelectedCount()
{
	return SqrSelectedCount;
}

int CFigure::getTriTotalCount()
{
	return TriTotalCount;
}

int CFigure::getTriSelectedCount()
{
	return TriSelectedCount;
}

int CFigure::getHexTotalCount()
{
	return HexTotalCount;
}

int CFigure::getHexSelectedCount()
{
	return HexSelectedCount;
}

int CFigure::getCircleTotalCount()
{
	return CircleTotalCount;
}

int CFigure::getCircleSelectedCount()
{
	return CircleSelectedCount;
}

// temporary by Omar //start //static members fucntions
int CFigure::getBlackCount() {
	return blackCount;
}
int CFigure::getYellowCount() {
	return yellowCount;
}
int CFigure::getOrangeCount() {
	return orangeCount;
}
int CFigure::getRedCount() {
	return redCount;
}
int CFigure::getBlueCount() {
	return blueCount;
}
int CFigure::getGreenCount() {
	return greenCount;
}
int CFigure::getFilledCount() {
	return filledCount;
}
int CFigure::getID()
{
	return ID;
}
//members functions
color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}

color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}
void CFigure::decStaticMembers(CFigure *fig) {

	switch (fig->getType())
	{
	case triangle:
		TriTotalCount--;
		break;
	case square:
		SqrTotalCount--;
		break;
	case rectangle:
		RecTotalCount--;
		break;
	case circle:
		CircleTotalCount--;
		break;
	case hexagon:
		HexTotalCount--;
		break;
	}
	if (fig->IsFilled())
	{
		filledCount--;
		switch (fig->getFillClr())
		{
		case pBLACK:
			blackCount--;
			break;
		case pYELLOW:
			yellowCount--;
			break;
		case pORANGE:
			orangeCount--;
			break;
		case pRED:
			redCount--;
			break;
		case pGREEN:
			greenCount--;
			break;
		case pBLUE:
			blueCount--;
			break;
		}
	}
	
}


void CFigure::incColorCount(int c) {
	filledCount++;
	switch (c)
	{
	case pBLACK:
		blackCount++;
		break;
	case pYELLOW:
		yellowCount++;
		break;
	case pORANGE:
		orangeCount++;
		break;
	case pRED:
		redCount++;
		break;
	case pGREEN:
		greenCount++;
		break;
	case pBLUE:
		blueCount++;
		break;

	}
}

void CFigure::incShapeCount(int s) {
	switch (s)
	{
	case triangle:
		TriTotalCount++;
		break;
	case square:
		SqrTotalCount++;
		break;
	case rectangle:
		RecTotalCount++;
		break;
	case circle:
		CircleTotalCount++;
		break;
	case hexagon:
		HexTotalCount++;
		break;
	}
}

void CFigure::setAllStaticZero() {
	blackCount = 0;
	yellowCount = 0;
	orangeCount = 0;
	redCount = 0;
	blueCount = 0;
	greenCount = 0;
	filledCount = 0;
	RecTotalCount = 0;
	RecSelectedCount = 0;
	SqrTotalCount = 0;
	SqrSelectedCount = 0;
	TriTotalCount = 0;
	TriSelectedCount = 0;
	HexTotalCount = 0;
	HexSelectedCount = 0;
	CircleTotalCount = 0;
}

int CFigure::getFillClr() {
	if (BLACK==FigGfxInfo.FillClr)
		return 0;
	else if (YELLOW==FigGfxInfo.FillClr )
		return 1;
	else if (ORANGE==FigGfxInfo.FillClr)
		return 2;
	else if (RED == FigGfxInfo.FillClr )
		return 3;
	else if (GREEN == FigGfxInfo.FillClr)
		return 4;
	else if (BLUE == FigGfxInfo.FillClr) {
		return 5;
	}
}
// end


