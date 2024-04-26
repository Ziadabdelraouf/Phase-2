#include "CCircle.h"

CCircle::CCircle(Point C, Point R, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	Center = C;
	Radius = R;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCrc to draw a Circle on the screen	
	pOut->DrawCrc(Center, Radius, FigGfxInfo, Selected);
}

bool CCircle::IsClickInside(int x, int y) const
{
	float r1 = sqrt((Center.x - Radius.x)*(Center.x - Radius.x) + (Center.y - Radius.y)* (Center.y - Radius.y));
	float r2 = sqrt((Center.x - x)*(Center.x - x) + (Center.y - y)*(Center.y - y));
	if (r2 > r1)
	{
		return false;
	}
	
	return true;
}

void CCircle::PrintInfo(Output* pOut) const
{
	string str = "Circle, ID: " + to_string(ID) + ", Center : (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(str);
}

void CCircle::SetSelected(bool s)
{
	Selected = s;
	if (s)
		CFigure::CircleSelectedCount++; //increments count of selected squares by 1 when a square is selected
	else
		CFigure::CircleSelectedCount--; //decrements count of selected squares by 1 when a square is deselected
}
