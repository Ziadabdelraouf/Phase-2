#include "CSquare.h"

CSquare::CSquare(Point C, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	sidelength = 4 * UI.ToolBarHeight;
	if (C.x < sidelength / 2) {
		C.x = sidelength / 2;
	}

	if (C.x > UI.width - 15 - (sidelength / 2)) {
		C.x = UI.width - 15 - (sidelength / 2);
	}

	if (C.y < UI.ToolBarHeight + sidelength / 2) {
		C.y = UI.ToolBarHeight + sidelength / 2 + 2;
	}
	else if (C.y > UI.height - UI.StatusBarHeight - sidelength / 2) {
		C.y = UI.height - UI.StatusBarHeight - sidelength / 2;
	}
	Center = C;

	CFigure::SqrTotalCount++;

}

CSquare::CSquare(ifstream& fin, int ID) : CFigure(FigGfxInfo, ID)
{
	Load(fin);
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::Drawsquare to draw a square on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::IsClickInside(int x, int y) const
{
	//add conditions to return false if click is outside square
	Point Corner1, Corner2;
	Point C = Center;

	Corner1.x = C.x - sidelength / 2;
	Corner1.y = C.y - sidelength / 2;
	Corner2.x = C.x + sidelength / 2;
	Corner2.y = C.y + sidelength / 2;
	
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

void CSquare::Save(ofstream& fout)
{
	fout << "SQR\t";
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

void CSquare::Load(ifstream& fin)
{
	string Border, Fill;
	fin >> Center.x >> Center.y >> Border >> Fill;
	if (Border == "BL") {
		FigGfxInfo.DrawClr = BLUE;
	}
	else if (Border == "BK") {
		FigGfxInfo.DrawClr = BLACK;
	}
	else if (Border == "GN") {
		FigGfxInfo.DrawClr = GREEN;
	}
	else if (Border == "RD") {
		FigGfxInfo.DrawClr = RED;
	}
	else if (Border == "YL") {
		FigGfxInfo.DrawClr = YELLOW;
	}
	else if (Border == "OR") {
		FigGfxInfo.DrawClr = ORANGE;
	}
	FigGfxInfo.isFilled = true;
	if (Fill == "NF") {
		FigGfxInfo.isFilled = false;
	}
	else if (Fill == "BL") {
		FigGfxInfo.FillClr = BLUE;
	}
	else if (Fill == "BK") {
		FigGfxInfo.FillClr = BLACK;
	}
	else if (Fill == "GN") {
		FigGfxInfo.FillClr = GREEN;
	}
	else if (Fill == "RD") {
		FigGfxInfo.FillClr = RED;
	}
	else if (Fill == "YL") {
		FigGfxInfo.FillClr = YELLOW;
	}
	else if (Fill == "OR") {
		FigGfxInfo.FillClr = ORANGE;
	}

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

GfxInfo CSquare::GetGfxInfo()
{
	return FigGfxInfo;
}

Point CSquare::GetCenter()
{
	return Center;
}

bool CSquare::Wascut() const
{
	return WasCut;
}

CFigure* CSquare::CreateCopy(CFigure*) const
{
	CSquare* SS = new CSquare(Center, FigGfxInfo, ID);
	return SS;
}


CFigure* CSquare::Paste(Point NewCnt, int ID) const
{

	CSquare* SS = new CSquare(NewCnt, FigGfxInfo, ID);

	CFigure::SqrTotalCount++;
	return SS;
}


//omar
RNGshape CSquare::getType() {
	return square;
}

//
