#include "CSquare.h"

CSquare::CSquare(Point C, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	Center = C;
	sidelength = 4 * UI.ToolBarHeight;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::Drawsquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::IsClickInside(int x, int y) const
{
	//add conditions to return false if click is outside square

	return true;
}

void CSquare::PrintInfo(Output* pOut) const
{
	string str = "Square, ID: " + to_string(ID) + ", Center: (" + to_string(Center.x) + ", " + to_string(Center.y) + "), SideLength = " + to_string(sidelength) + "px";
	pOut->PrintMessage(str);
}

void CSquare::SetSelected(bool s)
{
	Selected = s;
	if (s)
		CFigure::SqrSelectedCount++; //increments count of selected squares by 1 when a square is selected
	else
		CFigure::SqrSelectedCount--; //decrements count of selected squares by 1 when a square is deselected
}