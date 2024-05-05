#pragma once
#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"
class CCircle:public CFigure{
private:
	Point Center;
	Point Radius;
	float Rad1;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo, int id);
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the circle
	virtual void PrintInfo(Output* pOut) const; //prints info of circle
	virtual void SetSelected(bool s);
	GfxInfo GetGfxInfo() const;
	Point GetCenter() const;
	double GetRaduis() const;
	virtual char FigType() const;

};
#endif