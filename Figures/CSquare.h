#pragma once
#ifndef CSquare_H
#define CSquare_H
#include "CFigure.h"
class CSquare:public CFigure{
private:
	Point Center;
public:
	CSquare(Point,GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};
#endif