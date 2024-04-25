#include "CSquare.h"

CSquare::CSquare(Point C, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = C;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}