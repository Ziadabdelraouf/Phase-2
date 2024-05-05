#include "CTriangle.h"

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

	float TotalArea = 0.5*abs(Corner1.x*(Corner2.y-Corner3.y) + Corner2.x*(Corner3.y-Corner1.y) + Corner3.x*(Corner1.y-Corner2.y));
	float A1 = 0.5 * abs(x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y) + Corner3.x * (y - Corner2.y));
	float A2 = 0.5 * abs(Corner1.x * (y - Corner3.y) + x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y));
	float A3 = 0.5 * abs(Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y) + x * (Corner1.y - Corner2.y));
	
	if (TotalArea == A1+A2+A3)
	{
		return true;
	}
	
	return false;
}

void CTriangle::PrintInfo(Output* pOut) const
{
	string str = "Triangle, ID: " + to_string(ID); //add more info
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

char CTriangle::FigType() const
{
	return 'T';
}

