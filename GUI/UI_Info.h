#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_SQR,
	ITM_TRI,
	ITM_HEX,
	ITM_CIRCL,
	COLR_BLACK,
	COLR_YELLOW,
	COLR_ORANGE,
	COLR_RED,
	COLR_GREEN,
	COLR_BLUE,
	ITM_SELECT,
	ITM_CHANGE_BORDER_COLOR,
	ITM_CHANGE_FILLING_COLOR,
	ITM_DELETEFIG,
	ITM_CLEARALL,
	ITM_COPYFIG,
	ITM_CUTFIG,
	ITM_PASTEFIG,
	ITM_SENDBACK_BRINGFRONT,
	ITM_SAVE,
	ITM_LOAD,
	ITM_TO_PLAY,
	ITM_EXIT,
	DRAW_ITM_COUNT
};		//no. of menu items ==> This should be the last line in this enum
	


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here

	PLAY_ITM_SHAPE,
	PLAY_ITM_COLOR,
	PLAY_ITM_BOTH,
	PLAY_ITM_DRAWMODE,
	PLAY_ITM_EXIT,
	PLAY_ITM_COUNT   //no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		LineUnderTBWidth,	//line Under the Toolbar Pen Width
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color bkgToolBar;       //tool bar color
	int PenWidth;			//width of the pen that draws shapes
	//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif