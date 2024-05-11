#include "CCircle.h"

CCircle::CCircle(Point C, int r, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id){
	Point cent = C;
	Point cent1 = cent;
	radius = r;
	
	//validation to make sure circle is drawn within drawing area
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

	//increment number of circles by 1
	CFigure::CircleTotalCount++;

}

CCircle::CCircle(ifstream& fin, int ID) : CFigure(FigGfxInfo, ID)
{
	Load(fin);
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

//saves the type, id, centre, draw colour, and fill colour of the figure
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

void CCircle::Load(ifstream& fin)
{
	string Border, Fill;
	fin >> Center.x >> Center.y >> radius >> Border >> Fill;
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

CFigure* CCircle::CreateCopy() const
{
	CCircle* CC = new CCircle(Center, radius, FigGfxInfo, ID);  //create an identical copy that will be stored in Clipboard
	return CC;
	delete CC;
}
CFigure* CCircle::Paste(Point NewCnt, int ID) const
{
	Point PTemp;
	PTemp.x = NewCnt.x + radius;
	PTemp.y = NewCnt.y;
	CCircle* CC = new CCircle(NewCnt, radius, FigGfxInfo, ID); //Create a new object to be pasted 
   CFigure::CircleTotalCount++;
	return CC;
	delete CC;
}

//omar
RNGshape CCircle::getType() {
	return circle;
}

//
