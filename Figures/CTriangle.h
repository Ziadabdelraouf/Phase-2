#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"

class CTriangle : public CFigure {
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo, int id);
	CTriangle(ifstream& fin, int ID);

	virtual void Draw(Output* pOut) const;
	virtual bool IsClickInside(int x, int y) const; //checks if click is inside the triangle
	virtual void Save(ofstream& fout);
	virtual void Load(ifstream& fin);

	virtual void PrintInfo(Output* pOut) const; //prints info of triangle
	virtual void SetSelected(bool s);
	
	CFigure* CreateCopy() const;  //create a dummy figrue 
	CFigure* Paste(Point, int) const;   //create a new figure at new location

//omar
virtual RNGshape getType(); //return the type of the shape
//
};

#endif
