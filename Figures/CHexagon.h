#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"

class CHexagon :public CFigure {
private:
	Point Center;
	int sidelength;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo, int id);
	CHexagon(ifstream& fin, int ID);

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the hexagon
	virtual void Save(ofstream& fout);
	virtual void Load(ifstream& fin);
	virtual void PrintInfo(Output* pOut) const; //prints info of hexagon
	virtual void SetSelected(bool s);
	
	virtual CFigure* CreateCopy() const;
	CFigure* Paste(Point, int) const;

//omar
virtual RNGshape getType(); //return the type of the shape
//
};
#endif
