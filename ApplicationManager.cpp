#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCrcAction.h"
#include "Actions\SelectAction.h"
#include "Actions\FillAction.h"
#include "Actions\BorderAction.h"
#include "Actions\ClearAllAction.h"

#include "Figures\CFigure.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFigCount = 0;
	FigerIndex = 0;

	Color = BLACK;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case DRAW_SQR:
			pAct = new AddSquareAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCL:
			pAct = new AddCrcAction(this);
			break;
		case CHANGE_FILLING_COLOR:
			pAct = new FillAction(this);
			break;
		case CHANGE_BORDER_COLOR:
			pAct = new BorderAction(this);
			break;
		case CLEARALL:
			pAct = new ClearAllAction(this);
			break;
		case COLOR_BLACK:
			Color = BLACK;
			break;
		case COLOR_BLUE:
			Color = BLUE;
			break;
		case COLOR_GREEN:
			Color = GREEN;
			break;
		case COLOR_ORANGE:
			Color = ORANGE;
			break;
		case COLOR_YELLOW:
			Color = YELLOW;
			break;
		case COLOR_RED:
			Color = RED;
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it
	for (int i = FigCount-1; i >=0 ; i--) {
		if (FigList[i]->IsClickInside(x, y)){
			return FigList[i];
		}
	}
	
	//If this point (x,y) does not belong to any figure return NULL
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int id) const
{
	if (id <= FigCount)
		return FigList[id]; //return pointer to figure if found
	else
		return NULL; //return NULL if figure not found
}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigureCount() const
{
	return FigCount; //returns actual number of figures
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetFigCount(int n) {
	FigCount = (n>=0) ? n:0;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetSelectedFig() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			return FigList[i];
		}
	}
}
int ApplicationManager::GetNumSelected()  {
	SelectedFigCount = 0;
	for (int i = 0; i < FigCount; i++){
		if (FigList[i]->IsSelected()) {
			SelectedFigCount++;
		}
	}
	return SelectedFigCount;
}
////////////////////////////////////////////////////////////////////////////////////
color ApplicationManager::GetColor() {
	return Color;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<GetFigureCount(); i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////

//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
}
