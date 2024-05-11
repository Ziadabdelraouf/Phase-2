#pragma once
#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"
class CCircle :public CFigure {
private:
	Point Center;
	int radius;
	Point Radius;
	
	bool IsCut;
public:
	CCircle(Point, int , GfxInfo FigureGfxInfo, int id);
	CCircle(ifstream& fin, int ID);

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the circle
	virtual void Save(ofstream& fout);
	virtual void Load(ifstream& fin);
	virtual void PrintInfo(Output* pOut) const; //prints info of circle
	virtual void SetSelected(bool s);
//omar
virtual RNGshape getType(); //return the type of the shape
//
	
	CFigure* CreateCopy() const;
	CFigure* Paste(Point, int) const;
	
};
#endif
