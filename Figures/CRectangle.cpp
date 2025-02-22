#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	
	//validation to ensure figure is within draw area

	if (P1.y < UI.ToolBarHeight || P2.y < UI.ToolBarHeight) {
		if (P1.y < P2.y) {
			P2.y += (UI.ToolBarHeight - P1.y);
			P1.y = UI.ToolBarHeight + 3;
		}
		if (P2.y < P1.y) {
			P1.y += (UI.ToolBarHeight - P2.y);
			P2.y = UI.ToolBarHeight + 3;
		}
	}
	if (P1.y >= UI.height - UI.StatusBarHeight || P2.y >= UI.height - UI.StatusBarHeight) {
		if (P1.y > P2.y) {
			P2.y -= UI.height - UI.StatusBarHeight - P1.y;
			P1.y = UI.height - UI.StatusBarHeight - 3;
		}
		if (P2.y > P1.y) {
			P1.y -= UI.height - UI.StatusBarHeight - P2.y;
			P2.y = UI.height - UI.StatusBarHeight - 3;
		}
	}
	Corner1 = P1;
	Corner2 = P2;

	//increments number of rectangles
	CFigure::RecTotalCount++;
}

CRectangle::CRectangle(ifstream& fin, int ID) : CFigure(FigGfxInfo, ID)
{
	Load(fin);
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	

	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);

}

bool CRectangle::IsClickInside(int x, int y) const
{
	//checks if click is inside rectangle or on the sides, returns false if click is not inside rectangle

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


//saves the type, id, corners, draw colour, and fill colour of the figure
void CRectangle::Save(ofstream& fout)
{
	//saves figure type and id
	fout << "REC\t";
	fout << ID << "\t";

	//saves first corner
	fout << Corner1.x << "\t";
	fout << Corner1.y << "\t";

	//saves second corner
	fout << Corner2.x << "\t";
	fout << Corner2.y << "\t";

	//saves draw color
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


	//saves fill color
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

void CRectangle::Load(ifstream& fin)
{
	string Border, Fill;

	//loads corners, border color, and fill color from file
	fin >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Border >> Fill;

	//sets draw color of figure
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
	
	//set fill color of figure
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


void CRectangle::PrintInfo(Output* pOut) const
{
	//prints info of rectangle
	string str = "Rectangle, ID: " + to_string(ID) + ", Start: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "), End: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "), Width = " + to_string(abs(Corner2.x - Corner1.x)) + "px, Height = " + to_string(abs(Corner2.y - Corner1.y)) + "px";
	pOut->PrintMessage(str);
}

void CRectangle::SetSelected(bool s)
{
	Selected = s;
	if (s)
		CFigure::RecSelectedCount++; //increments count of selected rectangles by 1 when a rectangle is selected
	else
		CFigure::RecSelectedCount--; //decrements count of selected rectangles by 1 when a rectangle is deselected
}

CFigure* CRectangle::CreateCopy() const
{
	CRectangle* RR = new CRectangle(Corner1, Corner2, FigGfxInfo, ID);  //create an identical copy that will be stored in Clipboard
	//return figure
	return RR;

	//delete figure (returned as value)
	delete RR;
}
CFigure* CRectangle::Paste(Point NewCorner, int ID) const
{
	//temporary point 
	Point PTemp;

	//calculations to carry dimensions of previous rectangle
	PTemp.x = NewCorner.x + (Corner2.x - Corner1.x); 
	PTemp.y = NewCorner.y + (Corner2.y - Corner1.y);
	CRectangle* RR = new CRectangle(NewCorner,PTemp,  FigGfxInfo, ID);  //Create a new object to be pasted 

	//increment count of rectangles
	CFigure::RecTotalCount++;
	
	//return figure
	return RR;
	//delete figure (returned as value)
	delete RR;
}

//omar
RNGshape CRectangle::getType() {
	return rectangle;
}

//
