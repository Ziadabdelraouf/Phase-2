#ifndef CRECT_H
#define CRECT_H
#include "CFigure.h"

class CTriangle : public CFigure {
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo, int id);
	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the triangle
	virtual void Save(ofstream& fout);
	virtual void PrintInfo(Output* pOut) const; //prints info of triangle
	virtual void SetSelected(bool s);
	virtual bool Wascut() const;
	virtual CFigure* CreateCopy(CFigure*) const;
	 CFigure* Paste(Point, int) const;
};

#endif