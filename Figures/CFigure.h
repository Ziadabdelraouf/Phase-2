#ifndef CFIGURE_H
#define CFIGURE_H
#pragma once
#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected
	GfxInfo FigGfxInfo;	//Figure graphics info
	bool WasCut;
	static int RecTotalCount; //total number of rectangles
	static int RecSelectedCount; //number of selected rectangles
	static int SqrTotalCount;
	static int SqrSelectedCount;
	static int TriTotalCount;
	static int TriSelectedCount;
	static int HexTotalCount;
	static int HexSelectedCount;
	static int CircleTotalCount;
	static int CircleSelectedCount;


public:
	CFigure(GfxInfo FigureGfxInfo, int id);
	virtual void SetSelected(bool s) = 0;	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	bool IsFilled();
	virtual bool IsClickInside(int x, int y) const =0;
	virtual void Draw(Output* pOut) const  = 0 ;   //Draw the figure
	
	GfxInfo GetGfxInfo() const;
	virtual CFigure* Paste(Point NewCnt,int x) const=0;
	virtual CFigure* CreateCopy(CFigure*) const =0;
	virtual bool Wascut() const=0;
	Point GetCenter();
	double GetRaduis() const;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color GetFillClr();
	color GetDrawClr();
	int getRecTotalCount(); //returns total number of rectangles
	int getRecSelectedCount(); //returns number of selected rectangles
	int getSqrTotalCount();
	int getSqrSelectedCount();
	int getTriTotalCount();
	int getTriSelectedCount();
	int getHexTotalCount();
	int getHexSelectedCount();
	int getCircleTotalCount();
	int getCircleSelectedCount();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
};

#endif