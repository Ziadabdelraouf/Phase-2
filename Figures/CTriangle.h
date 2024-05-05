#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"

class CTriangle: public CFigure{
	private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo, int id );
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the triangle
	virtual void Save(ofstream& fout);
	virtual void PrintInfo(Output* pOut) const; //prints info of triangle
	virtual void SetSelected(bool s);
//omar
virtual RNGshape getType(); //return the type of the shape
//
};

#endif
