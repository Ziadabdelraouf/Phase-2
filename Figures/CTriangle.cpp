#include "CTriangle.h"
#include <fstream>
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	if (p1.y < UI.ToolBarHeight || p2.y < UI.ToolBarHeight || p3.y < UI.ToolBarHeight) {
		if (p1.y < p2.y && p1.y < p3.y) {
			int temp = UI.ToolBarHeight - p1.y;
			p1.y = UI.ToolBarHeight;
			p2.y += temp;
			p3.y += temp;
		}
		else if (p2.y < p1.y && p2.y < p3.y) {
			int temp = UI.ToolBarHeight - p2.y;
			p2.y = UI.ToolBarHeight;
			p1.y += temp;
			p3.y += temp;
		}
		else if (p3.y < p1.y && p3.y < p2.y) {
			int temp = UI.ToolBarHeight - p3.y;
			p3.y = UI.ToolBarHeight;
			p1.y += temp;
			p2.y += temp;
		}
	}
	if (p1.y > (UI.height - UI.StatusBarHeight) || p2.y > (UI.height - UI.StatusBarHeight) || p3.y > (UI.height - UI.StatusBarHeight)) {
		if (p1.y > p2.y && p1.y > p3.y) {
			int temp = p1.y - (UI.height - UI.StatusBarHeight);
			p1.y = UI.height - UI.StatusBarHeight - 2;
			p2.y -= temp;
			p3.y -= temp;
		}
		else if (p2.y > p1.y && p2.y > p3.y) {
			int temp = p2.y - (UI.height - UI.StatusBarHeight);
			p2.y = UI.height - UI.StatusBarHeight - 2;
			p1.y -= temp;
			p3.y -= temp;
		}
		else if (p3.y > p1.y && p3.y > p2.y) {
			int temp = p3.y - (UI.height - UI.StatusBarHeight);
			p3.y = UI.height - UI.StatusBarHeight - 2;
			p1.y -= temp;
			p2.y -= temp;
		}
	}


	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;

	CFigure::TriTotalCount++;

}

CTriangle::CTriangle(ifstream& fin, int ID) : CFigure(FigGfxInfo, ID)
{
	Load(fin);
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

	float TotalArea = 0.5 * abs(Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y));
	float A1 = 0.5 * abs(x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y));
	float A2 = 0.5 * abs(Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y));
	float A3 = 0.5 * abs(Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y));

	if (TotalArea == A1 + A2 + A3)
	{
		return true;
	}

	return false;
}

void CTriangle::Save(ofstream& fout)
{
	fout << "TRI\t";
	fout << ID << "\t";

	fout << Corner1.x << "\t";
	fout << Corner1.y << "\t";

	fout << Corner2.x << "\t";
	fout << Corner2.y << "\t";

	fout << Corner3.x << "\t";
	fout << Corner3.y << "\t";

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

void CTriangle::Load(ifstream& fin)
{
	string Border, Fill;

	fin >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> Border >> Fill;
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

		
void CTriangle::PrintInfo(Output* pOut) const
{
	string str = "Triangle, ID: " + to_string(ID) + ", Corner1: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) +"), Corner2: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "), Corner3: (" + to_string(Corner3.x) + ", " + to_string(Corner3.y) + ")"; //add more info
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
 //omar
RNGshape CTriangle::getType() {
	return triangle;
}

bool CTriangle::Wascut() const
{
	return WasCut;
}

CFigure* CTriangle::CreateCopy(CFigure*) const
{
	CTriangle* TT = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo, ID);
	return TT;
}

CFigure* CTriangle::Paste(Point NewCorner, int ID) const
{
	Point PTemp1, PTemp2;
	PTemp1.x = NewCorner.x + (Corner2.x - Corner1.x);
	PTemp1.y = NewCorner.y + (Corner2.y - Corner1.y);
	PTemp2.x = NewCorner.x + (Corner3.x - Corner1.x);
	PTemp2.y = NewCorner.y + (Corner3.y- Corner1.y);
	CTriangle* TT = new CTriangle(NewCorner,PTemp1,PTemp2, FigGfxInfo, ID);

	CFigure::TriTotalCount++;
	return TT;
}

//CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo, int id)
  //
