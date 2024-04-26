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
	//calculates total area of triangle, then the area if the triangle is divided into 3 triangles with the point passed being the shared point between them,
	//if areas are equal then the click is inside and the function returns true value 

	float TotalArea = 0.5*abs(Corner1.x*(Corner2.y-Corner3.y) + Corner2.x*(Corner3.y-Corner1.y) + Corner3.x*(Corner1.y-Corner2.y));
	float A1 = 0.5 * abs(x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y));
	float A2 = 0.5 * abs(Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y));
	float A3 = 0.5 * abs(Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y));
	
	if (TotalArea == A1+A2+A3)
	{
		return true;
	}
	
	return false;
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

