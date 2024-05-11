#ifndef CFIGURE_H
#define CFIGURE_H
#pragma once
#include "..\defs.h"
#include <fstream>
#include "..\Defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected
	GfxInfo FigGfxInfo;	//Figure graphics info
	bool WasCut;
	//static int IDCount; //id number (constantly incremented to prevent id repetition)
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

//made by omar temporarly 
 
    static int blackCount;
    static int yellowCount;
    static int orangeCount;
    static int redCount;
    static int blueCount;
    static int greenCount;
	static int filledCount;

//

public:
	CFigure(GfxInfo FigureGfxInfo, int id);
	virtual void SetSelected(bool s) = 0;	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	
	virtual bool IsClickInside(int x, int y) const =0;
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
        //omar
        virtual RNGshape getType()=0 ; //return the type of the shape
		static void setAllStaticZero();

        //
	
	
	
	virtual CFigure* Paste(Point NewCnt,int x) const=0;
	virtual CFigure* CreateCopy() const =0;
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	/*void UnFillClr();*/
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
// temporary by omar 
static void incColorCount(int c);
static void incShapeCount(int s);
int getBlackCount();
int getYellowCount();
int getOrangeCount();
int getRedCount();
int getBlueCount();
int getGreenCount();
int getFilledCount();
int getID();
bool IsFilled();
int getFillClr();   //temporary it might be needed or not in the future made by (Omar)
static void decStaticMembers(CFigure *fig);

////
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &fout) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &fin) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar
};

#endif
