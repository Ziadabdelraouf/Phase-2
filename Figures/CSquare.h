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
	CSquare(ifstream& fin, int ID);

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the square
	virtual void Save(ofstream& fout);
	virtual void Load(ifstream& fin);

	virtual void PrintInfo(Output* pOut) const; //prints info of square
	virtual void SetSelected(bool s);
	GfxInfo GetGfxInfo();
	Point GetCenter();
	virtual bool Wascut() const;
	virtual CFigure* CreateCopy(CFigure*) const;
	CFigure* Paste(Point, int) const;
	
//omar
virtual RNGshape getType(); //return the type of the shape
//
};
#endif
