#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"

class CHexagon:public CFigure{
private:
	Point Center;
	int sidelength;
	
public:
	CHexagon(Point, GfxInfo FigureGfxInfo, int id);
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the hexagon
	virtual void Save(ofstream& fout);
	virtual void PrintInfo(Output* pOut) const; //prints info of hexagon
	virtual void SetSelected(bool s);
//omar
virtual RNGshape getType(); //return the type of the shape
//
};
#endif
