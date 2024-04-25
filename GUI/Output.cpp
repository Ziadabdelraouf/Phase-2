#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	//SHAPES
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\Menu_Sqr.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hex.jpg";
	MenuItemImages[ITM_CIRCL] = "images\\MenuItems\\Menu_Circ.jpg";
	//COLOR
	MenuItemImages[COLR_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[COLR_YELLOW] = "images\\MenuItems\\Yellow.jpg";
	MenuItemImages[COLR_ORANGE] = "images\\MenuItems\\Orange.jpg";
	MenuItemImages[COLR_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages[COLR_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[COLR_BLUE] = "images\\MenuItems\\Blue.jpg";
	//TOOLS
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_CHANGE_BORDER_COLOR] = "images\\MenuItems\\Border.jpg";
	MenuItemImages[ITM_CHANGE_FILLING_COLOR] = "images\\MenuItems\\Filling.jpg";
	MenuItemImages[ITM_DELETEFIG] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Clear.jpg";
	MenuItemImages[ITM_COPYFIG] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_CUTFIG] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_PASTEFIG] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_SENDBACK_BRINGFRONT] = "images\\MenuItems\\bring-to-front.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MenuItems\\Play.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::clearToolBar() const {
	pWind->SetPen(UI.bkgToolBar, 1);
	pWind->SetBrush(UI.bkgToolBar);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	clearToolBar();
	string playModeImages[PLAY_ITM_COUNT];
	playModeImages[PLAY_ITM_SHAPE] = "images\\Menuitems\\pickshape.jpg";
	playModeImages[PLAY_ITM_COLOR] = "images\\Menuitems\\pickcolor.jpg";
	playModeImages[PLAY_ITM_BOTH] = "images\\Menuitems\\pickboth.jpg";
	playModeImages[PLAY_ITM_DRAWMODE] = "images\\Menuitems\\Draw.jpg";
	playModeImages[PLAY_ITM_EXIT] = "images\\Menuitems\\Menu_Exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(playModeImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, UI.LineUnderTBWidth);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

//void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
//{
//	color DrawingClr;
//	if(selected)	
//		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
//	else			
//		DrawingClr = RectGfxInfo.DrawClr;
//	
//	pWind->SetPen(DrawingClr,1);
//	drawstyle style;
//	if (RectGfxInfo.isFilled)	
//	{
//		style = FILLED;		
//		pWind->SetBrush(RectGfxInfo.FillClr);
//	}
//	else	
//		style = FRAME;
//
//	
//	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
//	
//}
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
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
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSquare(Point C, GfxInfo SquareGfxInfo, bool selected) const
{
	const int sidelength = 4 * UI.ToolBarHeight;	//pre-set sidelength for square
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
	Point P1;
	Point P2;
	P1.x = C.x - sidelength / 2;
	P1.y = C.y - sidelength / 2;
	P2.x = C.x + sidelength / 2;
	P2.y = C.y + sidelength / 2;


	DrawRect(P1, P2, SquareGfxInfo, selected);

}
void Output::Drawtri(Point p1, Point p2, Point p3, GfxInfo triGfxInfo, bool selected) const {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = triGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (triGfxInfo.isFilled) {
		style = FILLED;
		pWind->SetBrush(triGfxInfo.FillClr);
	}
	else
		style = FRAME;
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

	pWind->DrawTriangle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, style);
}

void Output::DrawHex(Point C, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int sidelength = 2 * UI.ToolBarHeight;
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
	int const Px[6] = { C.x + sidelength, C.x + 0.5 * sidelength, C.x - 0.5 * sidelength, C.x - sidelength, C.x - 0.5 * sidelength, C.x + 0.5 * sidelength };
	int const Py[6] = { C.y, C.y - (sqrt(3 / 4.0) * sidelength), C.y - (sqrt(3 / 4.0) * sidelength), C.y, C.y + (sqrt(3 / 4.0) * sidelength), C.y + (sqrt(3 / 4.0) * sidelength) };
	pWind->DrawPolygon(Px, Py, 6, style);
}


void Output::DrawCrc(Point cent, Point rad, GfxInfo crcGfxInfo, bool selcrc) {
	Point cent1, cent2;
	int  radius;
	color crc;
	if (selcrc) {
		crc = UI.HighlightColor;
	}
	else {
		crc = crcGfxInfo.DrawClr;
	}
	pWind->SetPen(crc, 1);
	drawstyle ds;
	if (crcGfxInfo.isFilled)
	{
		ds = FILLED;
		pWind->SetBrush(crcGfxInfo.FillClr);
	}
	else
		ds = FRAME;

	cent1.x = cent.x;
	cent1.y = cent.y;
	radius = sqrt((rad.x - cent.x) * (rad.x - cent.x) + (rad.y - cent.y) * (rad.y - cent.y));
	if (radius > (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2) {
		radius = (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2;
		cent1.y = UI.ToolBarHeight + (UI.height - UI.ToolBarHeight - UI.StatusBarHeight) / 2;
	}

	pWind->DrawCircle(cent1.x, cent1.y, radius, ds);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

