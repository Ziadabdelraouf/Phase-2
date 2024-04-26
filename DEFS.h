#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
    DRAW_RECT,        //Draw Rectangle
    DRAW_SQR,
    DRAW_TRI,        //TRIANGLE
    DRAW_HEX,        //HEXAGON
    DRAW_CIRCL,        //CIRCLE
    COLOR_BLACK,
    COLOR_YELLOW,
    COLOR_ORANGE,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    //TODO: Add more items names here
    SELECT,            //SELECT ITEMS
    CHANGE_BORDER_COLOR,
    CHANGE_FILLING_COLOR,
    DELETEFIG,            //DELETE FIGURE
    CLEARALL,            //CLEAR FIGURE
    COPYFIG,            //COPY FIGURE
    CUTFIG,                //CUT FIGURE
    PASTEFIG,            //PASTE FIGURE
    SENDBACK_BRINGFRONT,
    PICK_HIDE,
    SAVE,
    LOAD,
    EXIT,            //Exit
    TO_DRAW,        //Switch interface to Draw mode
    TO_PLAY,        //Switch interface to Play mode
    SHAPE,
    COLOR,
    BOTH,
    DRAWMODE,
    EMPTY,            //A click on empty place in the toolbar
    DRAWING_AREA,    //A click on the drawing area
    STATUS            //A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif