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

// temporary changes by omar
int CFigure::blackCount = 0;      //initialise count of black filled figures
int CFigure::yellowCount = 0;     //initialise count of yellow filled figures
int CFigure::orangeCount = 0;    //initialise count of oragne filled figures
int CFigure::redCount = 0;      //initialise count of red filled figures
int CFigure::blueCount = 0;      //initialise count of blue filled figures
int CFigure::greenCount = 0;    //initialise count of green filled figures

//

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

// temporary by Omar //start
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
}//static members fucntions
//members functions
bool CFigure::IsFilled() {
	return FigGfxInfo.isFilled;
}

//color CFigure::getFillClr() {
//	return FigGfxInfo.FillClr;
//}
// end


