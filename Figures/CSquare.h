#pragma once
#ifndef CSquare_H
#define CSquare_H
#include "CFigure.h"
class CSquare:public CFigure{
private:
	Point Center;
	int sidelength;
public:
	CSquare(Point,GfxInfo FigureGfxInfo, int id);
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the square
	virtual void PrintInfo(Output* pOut) const; //prints info of square
	virtual void SetSelected(bool s);
	GfxInfo GetGfxInfo();
	Point GetCenter();
	virtual char FigType() const;
};
#endif
