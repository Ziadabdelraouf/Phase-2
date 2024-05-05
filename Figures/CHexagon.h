#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"

class CHexagon :public CFigure {
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
	GfxInfo GetGfxInfo()const;
	Point GetCenter();
	virtual bool Wascut() const;
	virtual CFigure* CreateCopy(CFigure*) const;
	CFigure* Paste(Point, int) const;

};
#endif
