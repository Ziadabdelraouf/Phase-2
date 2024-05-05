#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	// -- Constructor
	Output();		

	// -- Creation of Window
	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	Input* CreateInput() const; //creates a pointer to the Input object	

	// -- Input and Clear Functions
	void clearToolBar() const; //clears the tool bar
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void Drawtri(Point p1, Point p2, Point p3, GfxInfo triGfxInfo, bool selected) const; //Draw a circle 
	void DrawSquare(Point C, GfxInfo SquareGfxInfo, bool selected = false) const; //Draw a square
	void DrawHex(Point C, GfxInfo HexGfxInfo, bool selected = false) const; //Draw a hexagon
	void DrawCrc(Point cent, int rad, GfxInfo crcGfxInfo, bool); //Draw a circle

	// -- Displaying Messages
	void PrintMessage(string msg) const;	//Print a message on Status bar

	// -- Getters
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	// -- Destructor
	~Output();
};

#endif