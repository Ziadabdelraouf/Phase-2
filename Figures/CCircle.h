#pragma once
#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"
class CCircle :public CFigure {
private:
	Point Center;
	int radius;
	Point Radius;
	int radius;
	bool IsCut;
public:
	CCircle(Point, int , GfxInfo FigureGfxInfo, int id);
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the circle
	virtual void Save(ofstream& fout);
	virtual void PrintInfo(Output* pOut) const; //prints info of circle
	virtual void SetSelected(bool s);
//omar
virtual RNGshape getType(); //return the type of the shape
//
	virtual bool Wascut() const;
	virtual CFigure* CreateCopy(CFigure*) const;
	CFigure* Paste(Point, int) const;
	GfxInfo GetGfxInfo() const;
	Point GetCenter() const;
	double GetRaduis() const;
	

};
#endif
