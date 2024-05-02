#include "CHexagon.h"

CHexagon::CHexagon(Point C, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	sidelength = 2 * UI.ToolBarHeight;
	if (C.x < sidelength) {
		C.x = sidelength;
	}

	if (C.x > UI.width - 15 - (sidelength)) {
		C.x = UI.width - 15 - (sidelength);
	}

	if (C.y < UI.ToolBarHeight + (sqrt(3 / 4.0) * sidelength)) {
		C.y = UI.ToolBarHeight + (sqrt(3 / 4.0) * sidelength) + 2;
	}
	else if (C.y > UI.height - UI.StatusBarHeight - (sqrt(3 / 4.0) * sidelength)) {
		C.y = UI.height - UI.StatusBarHeight - (sqrt(3 / 4.0) * sidelength);
	}
	Center = C;
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
