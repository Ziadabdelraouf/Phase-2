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
	
	CFigure::HexTotalCount++;

}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

bool CHexagon::IsClickInside(int x, int y) const
{
	Point C = Center;
	int Px[6] = { C.x + sidelength, C.x + 0.5 * sidelength, C.x - 0.5 * sidelength, C.x - sidelength, C.x - 0.5 * sidelength, C.x + 0.5 * sidelength };
	int Py[6] = { C.y, C.y - (sqrt(3 / 4.0) * sidelength), C.y - (sqrt(3 / 4.0) * sidelength), C.y, C.y + (sqrt(3 / 4.0) * sidelength), C.y + (sqrt(3 / 4.0) * sidelength) };
	
	int m = Px[2];
	int n = Py[2];
	Point Corner1, Corner2, Corner3;
	float TotalArea, A1, A2, A3;

	Corner1.x = Px[0];
	Corner1.y = Py[0];
	Corner2.x = Px[1];
	Corner2.y = Py[1];
	Corner3.x = Px[5];
	Corner3.y = Py[5];
	TotalArea = 0.5 * abs(Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y));
	A1 = 0.5 * abs(x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y));
	A2 = 0.5 * abs(Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y));
	A3 = 0.5 * abs(Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y));
	
	if (TotalArea == A1 + A2 + A3)
	{
		return true;
	}
	
	Corner1.x = Px[3];
	Corner1.y = Py[3];
	Corner2.x = Px[4];
	Corner2.y = Py[4];
	Corner3.x = Px[2];
	Corner3.y = Py[2];
	TotalArea = 0.5 * abs(Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y));
	A1 = 0.5 * abs(x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y));
	A2 = 0.5 * abs(Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y));
	A3 = 0.5 * abs(Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y));
	
	if (TotalArea == A1 + A2 + A3)
	{
		return true;
	}

	Corner1.x = Px[2];
	Corner1.y = Py[2];
	Corner2.x = Px[5];
	Corner2.y = Py[5];


	if (Corner1.x < Corner2.x) {
		if (x < Corner1.x || x > Corner2.x)
			return false;
	}

	if (Corner2.x < Corner1.x) {
		if (x > Corner1.x || x < Corner2.x)
			return false;
	}

	if (Corner1.y < Corner2.y) {
		if (y < Corner1.y || y > Corner2.y)
			return false;
	}

	if (Corner2.y < Corner1.y) {
		if (y > Corner1.y || y < Corner2.y)
			return false;
	}

	return true;
}

void CHexagon::Save(ofstream& fout)
{
	fout << "HEX\t";
	fout << ID << "\t";

	fout << Center.x << "\t";
	fout << Center.y << "\t";
	
	if (FigGfxInfo.DrawClr == BLUE) {
		fout << "BL\t";
	}
	else if (FigGfxInfo.DrawClr == BLACK) {
		fout << "BK\t";
	}
	else if (FigGfxInfo.DrawClr == GREEN) {
		fout << "GN\t";
	}
	else if (FigGfxInfo.DrawClr == RED) {
		fout << "RD\t";
	}
	else if (FigGfxInfo.DrawClr == YELLOW) {
		fout << "YL\t";
	}
	else if (FigGfxInfo.DrawClr == ORANGE) {
		fout << "OR\t";
	}

	if (!FigGfxInfo.isFilled) {
		fout << "NF";
	}
	else if (FigGfxInfo.FillClr == BLUE) {
		fout << "BL";
	}
	else if (FigGfxInfo.FillClr == BLACK) {
		fout << "BK";
	}
	else if (FigGfxInfo.FillClr == GREEN) {
		fout << "GN";
	}
	else if (FigGfxInfo.FillClr == RED) {
		fout << "RD";
	}
	else if (FigGfxInfo.FillClr == YELLOW) {
		fout << "YL";
	}
	else if (FigGfxInfo.FillClr == ORANGE) {
		fout << "OR";
	}
	fout << "\n";
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
