#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo, int id):CFigure(FigureGfxInfo, id)
{
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
	
	CFigure::RecTotalCount++;
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



void CRectangle::PrintInfo(Output* pOut) const
{
	//prints info of rectangle
	string str = "Rectangle, ID: " + to_string(ID) + ", Start: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "), End: (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + "), Width = " + to_string(abs(Corner2.x - Corner1.x)) + "px, Height = " + to_string(abs(Corner2.y-Corner1.y)) + "px";
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

char CRectangle::GetType()const {
	return Type;
}

Point CRectangle::GetP1(){
	return Corner1;
}

Point CRectangle::GetP2() {
	return Corner2;
}
