#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"

class CHexagon :public CFigure {
private:
	Point Center;
	int sidelength;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo, int id);
	CHexagon(ifstream& fin, int ID); //constructor to be used when loading figure

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the hexagon
	virtual void Save(ofstream& fout); //saves hexagon info
	virtual void Load(ifstream& fin); //loads hexagon info
	virtual void PrintInfo(Output* pOut) const; //prints info of hexagon
	virtual void SetSelected(bool s);
	
	CFigure* CreateCopy() const;  //create a dummy figrue 
	CFigure* Paste(Point, int) const;   //create a new figure at new location

//omar
virtual RNGshape getType(); //return the type of the shape
//
};
#endif
