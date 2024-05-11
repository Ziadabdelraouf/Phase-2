#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include <fstream>
class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo, int);
	CRectangle(ifstream& fin, int ID); //constructor to be used when loading from file

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the rectangle
	virtual void Save(ofstream& OutFile); //saves rectangle info to file
	virtual void Load(ifstream& fin); //loads rectangle info from file

	virtual void PrintInfo(Output* pOut) const; //prints info of rectangle

	
	CFigure* CreateCopy() const;  //create a dummy figrue 
	CFigure* Paste(Point, int) const;   //create a new figure at new location
	virtual void SetSelected(bool s); 
//omar
virtual RNGshape getType(); //return the type of the shape
//
};

#endif
