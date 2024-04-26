#include "CFigure.h"


CFigure::CFigure(GfxInfo FigureGfxInfo, int id)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false; //default status is not-selected
	ID = id; //set id of the figure
}
 
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

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
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
