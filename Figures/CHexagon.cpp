#include "CHexagon.h"

CHexagon::CHexagon(Point C, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	Center = C;
	sidelength = 2 * UI.ToolBarHeight;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsClickInside(int x, int y) const
{
	return true;
}

void CHexagon::PrintInfo(Output* pOut) const
{
	string str = "Hexagon, ID: " + to_string(ID) + ", Center: (" + to_string(Center.x) + ", " + to_string(Center.y) + "), SideLength = " + to_string(sidelength) + "px";
	pOut->PrintMessage(str);
}

void CHexagon::SetSelected(bool s)
{
	Selected = s;
	if (s)
		CFigure::HexSelectedCount++; //increments count of selected hexagons by 1 when a hexagon is selected
	else
		CFigure::HexSelectedCount--; //decrements count of selected hexagons by 1 when a hexagon is deselected
}
