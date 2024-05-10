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
	CRectangle(ifstream& fin, int ID);

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the rectangle
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& fin);

	virtual void PrintInfo(Output* pOut) const; //prints info of rectangle

	
	virtual CFigure* CreateCopy() const;
	 CFigure* Paste(Point, int) const;
	virtual void SetSelected(bool s); 
//omar
virtual RNGshape getType(); //return the type of the shape
//
};

#endif
