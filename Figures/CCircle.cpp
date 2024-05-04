#include "CCircle.h"

CCircle::CCircle(Point C, Point R, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	Point cent = C;
	Point cent1 = cent;
	Point rad = R;

	radius = sqrt((rad.x - cent.x) * (rad.x - cent.x) + (rad.y - cent.y) * (rad.y - cent.y));

	if (radius > (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2) {
		radius = (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2;
		cent1.y = UI.ToolBarHeight + (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2;
	}
	if ((cent.y - radius) < UI.ToolBarHeight) {
		cent1.y = UI.ToolBarHeight + radius;
	}
	else if (cent.y + radius > UI.height - UI.StatusBarHeight)
	{
		cent1.y = UI.height - UI.StatusBarHeight - radius;

	}
	if ((cent.x + radius) > UI.width - 15) {
		cent1.x = UI.width - 15 - radius;
	}
	else if ((cent.x - radius) < 0) {
		cent1.x += -1 * (cent.x - radius);
	}
	
	Center = cent1;
	Radius = R;
	CFigure::CircleTotalCount++;

}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCrc to draw a Circle on the screen	
	pOut->DrawCrc(Center, radius, FigGfxInfo, Selected);
}

bool CCircle::IsClickInside(int x, int y) const
{
	float r1 = radius;
	float r2 = sqrt((Center.x - x)*(Center.x - x) + (Center.y - y)*(Center.y - y));
	if (r2 > r1)
	{
		return false;
	}
	
	return true;
}

void CCircle::Save(ofstream& fout)
{
	fout << "CIR\t";
	fout << ID << "\t";

	fout << Center.x << "\t";
	fout << Center.y << "\t";

	fout << radius << "\t";
	

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

	if (!FigGfxInfo.isFilled)
	{
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

void CCircle::PrintInfo(Output* pOut) const
{
	string str = "Circle, ID: " + to_string(ID) + ", Center : (" + to_string(Center.x) + ", " + to_string(Center.y) + ")" + ", Radius: " + to_string(radius) + "px";
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
