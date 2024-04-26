#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->Drawtri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::IsClickInside(int x, int y) const
{
	//add conditions to return false if click outside
	return true;
}

void CTriangle::PrintInfo(Output* pOut) const
{
	string str = "Triangle, ID: " + to_string(ID); //add more info
	pOut->PrintMessage(str);
}

void CTriangle::SetSelected(bool s)
{

	Selected = s;
	if (s)
		CFigure::TriSelectedCount++; //increments count of selected triangles by 1 when a triangles is selected
	else
		CFigure::TriSelectedCount--; //decrements count of selected triangles by 1 when a triangles is deselected
}

