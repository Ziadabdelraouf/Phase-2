#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQR:return  DRAW_SQR;
			case ITM_TRI:return  DRAW_TRI;
			case ITM_HEX:return  DRAW_HEX;
			case ITM_CIRCL:return  DRAW_CIRCL;
			case COLR_BLACK: return COLOR_BLACK;
			case COLR_YELLOW: return COLOR_YELLOW;
			case COLR_ORANGE: return COLOR_ORANGE;
			case COLR_RED: return COLOR_RED;
			case COLR_GREEN: return COLOR_GREEN;
			case COLR_BLUE: return COLOR_BLUE;
			case ITM_SELECT:return  SELECT;
			case ITM_CHANGE_BORDER_COLOR:return  CHANGE_BORDER_COLOR;
			case ITM_CHANGE_FILLING_COLOR: return CHANGE_FILLING_COLOR;
			case ITM_DELETEFIG: return DELETEFIG;
			case ITM_CLEARALL: return CLEARALL;
			case ITM_COPYFIG: return COPYFIG;
			case ITM_CUTFIG: return CUTFIG;
			case ITM_PASTEFIG: return PASTEFIG;
			case ITM_SENDBACK_BRINGFRONT: return SENDBACK_BRINGFRONT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_TO_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PLAY_ITM_SHAPE: return SHAPE;
			case PLAY_ITM_COLOR: return COLOR;
			case PLAY_ITM_BOTH: return BOTH;
			case PLAY_ITM_DRAWMODE: return TO_DRAW;
			case PLAY_ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		else if (y >= (UI.height - UI.StatusBarHeight)) {
			return STATUS;

		}
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}

}
/////////////////////////////////
	
Input::~Input()
{
}
