#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo, int );
	virtual void Draw(Output* pOut) const; 
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the rectangle
	virtual void PrintInfo(Output* pOut) const; //prints info of rectangle
	virtual void Save(ofstream& OutFile);
	virtual void SetSelected(bool s); 
};

#endif