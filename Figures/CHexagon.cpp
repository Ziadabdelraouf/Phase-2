#include "CHexagon.h"
#include <fstream>
#include "..\ApplicationManager.h"
CHexagon::CHexagon(Point C, GfxInfo FigureGfxInfo, int id) :CFigure(FigureGfxInfo, id)
{
	sidelength = 2 * UI.ToolBarHeight;

	//validation to ensure hexagon is within drawing area

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

	//increment number of hexagons
	CFigure::HexTotalCount++;

}

CHexagon::CHexagon(ifstream& fin, int ID) : CFigure(FigGfxInfo, ID)
{
	sidelength = 2 * UI.ToolBarHeight;
	Load(fin);
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}


//checks if click is inside hexagon by dividing it into a square and 2 triangles
bool CHexagon::IsClickInside(int x, int y) const
{
	Point C = Center;
	//points are stored in two arrays
	int Px[6] = { C.x + sidelength, C.x + 0.5 * sidelength, C.x - 0.5 * sidelength, C.x - sidelength, C.x - 0.5 * sidelength, C.x + 0.5 * sidelength };
	int Py[6] = { C.y, C.y - (sqrt(3 / 4.0) * sidelength), C.y - (sqrt(3 / 4.0) * sidelength), C.y, C.y + (sqrt(3 / 4.0) * sidelength), C.y + (sqrt(3 / 4.0) * sidelength) };
	

	Point Corner1, Corner2, Corner3;
	float TotalArea, A1, A2, A3;


	//algorithm using geometry to check if click is inside the triangle on the right
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
	
	//algorithm using geometry to check if click is inside the triangle on the left
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

	//algorithm using geometry to check if click is inside the square in the middle
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


//saves the type, id, centre, draw colour, and fill colour of the figure
void CHexagon::Save(ofstream& fout)
{
	//saves figure type and id
	fout << "HEX\t";
	fout << ID << "\t";

	//saves centre
	fout << Center.x << "\t";
	fout << Center.y << "\t";
	
	//saves draw colour
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

	//saves fill colour
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

void CHexagon::Load(ifstream& fin)
{
	string Border, Fill;
	
	//loads centre, border colour, and fill colour
	fin >> Center.x >> Center.y >> Border >> Fill;

	//sets draw colour
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
	
	//sets fill color
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
//omar
RNGshape CHexagon::getType() {
	return hexagon;    
}


CFigure* CHexagon::CreateCopy() const
{
	CHexagon* HH = new CHexagon(Center, FigGfxInfo, ID);  //create an identical copy that will be stored in Clipboard
	return HH ;
	delete HH;
}



CFigure* CHexagon::Paste(Point NewCnt,int ID) const
{
	CHexagon* HH = new CHexagon(NewCnt,FigGfxInfo,ID);  //Create a new object to be pasted 


	CFigure::HexTotalCount++;
	return HH;
	delete HH;
}




