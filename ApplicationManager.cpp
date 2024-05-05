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
#include "Actions\SendBackAction.h"
#include "Actions\BringFrontAction.h"
#include "ShapeRNG.h"
#include "Actions\SaveAction.h"
#include "ColorRNG.h"
#include "BothRNG.h"
#include "Actions\VoiceAction.h"
#include "Actions\LoadAction.h"
#include "PlayShape.h"

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
		case SENDBACK:
			pAct = new SendBackAction(this);
			break;
		case BRINGFRONT:
			pAct = new BringFrontAction(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case AUDIOPLAYER:
			pAct = new VoiceAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);

		case COLOR_BLACK:
			Color = BLACK;
			PlayAudio("Audio\\Black.wav");
			pOut->PrintMessage("Black");
			break;
		case COLOR_BLUE:
			Color = BLUE;
			PlayAudio("Audio\\Blue.wav");
			pOut->PrintMessage("Blue");
			break;
		case COLOR_GREEN:
			Color = GREEN;
			PlayAudio("Audio\\Green.wav");
			pOut->PrintMessage("Green");
			break;
		case COLOR_ORANGE:
			Color = ORANGE;
			PlayAudio("Audio\\Orange.wav");
			pOut->PrintMessage("Orange");
			break;
		case COLOR_YELLOW:
			Color = YELLOW;
			PlayAudio("Audio\\Yellow.wav");
			pOut->PrintMessage("Yellow");
			break;
		case COLOR_RED:
			Color = RED;
			PlayAudio("Audio\\Red.wav");
			pOut->PrintMessage("Red");
			break;
		case SHAPE:
			pAct = new PlayShape(this);
	         break;
        case COLOR:
			pAct = new ColorRNG(this);
	    break;
		case BOTH:
			pAct = new BothRNG(this);
	    break;
case TO_DRAW:
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	UI.InterfaceMode = MODE_DRAW;
	break;
case TO_PLAY:
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();
	UI.InterfaceMode = MODE_PLAY;
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
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetNumSelected()  {
	SelectedFigCount = 0;
	for (int i = 0; i < FigCount; i++){
		if (FigList[i]->IsSelected()) {
			SelectedFigCount++;
		}
	}
	return SelectedFigCount;
}
void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < GetFigureCount(); i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
	}
}
void ApplicationManager::ClearAll()
{
	for (int i = 0; i < GetFigureCount(); i++) {
		if(FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
		FigList[i] = NULL;
	}
}
////////////////////////////////////////////////////////////////////////////////////
color ApplicationManager::GetColor() {
	return Color;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::Swaping(int Op) {
	//Check the number of the selected figures
	if (GetNumSelected() > 1 || GetNumSelected() == 0) {
		string str = "please select only one figure";
		PlayAudio("Audio\\SelectOneFigure.wav");
		pOut->PrintMessage(str);
	}
	else {
		//Op: the number of the operation(1:Bring front, 2:send back)
		CFigure* pFig = GetSelectedFig(); //Geting the selected figure
		int x=0;
		//Loop to get the index of the selected figure
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i]->IsSelected()) {
				x = i;
			}
		}
		//Bring Front
		if (Op == 1) {
			for (int i = x; i < FigCount; i++) {
				FigList[i] = FigList[i + 1];
				if (i == FigCount - 1) {
					break;
				}
			}
			FigList[(FigCount - 1)] = pFig; //Replace the selceted figure to its new index
			pOut->PrintMessage("Bring selected figure to front.....");
			PlayAudio("Audio\\BringToFront.wav");
		}
		//Send Back
		else if (Op == 2) {
			pFig = GetSelectedFig();
			for (int i = x; i > 0; i--) {
				FigList[i] = FigList[i - 1];
				if (i == 1) {
					break;
				}
			}
			FigList[0] = pFig;//Replace the selceted figure to its new index
			pOut->PrintMessage("Sending selected figure back...");
			PlayAudio("Audio\\sendBack.wav");
		}
		
	}
}

void ApplicationManager::SaveAll(ofstream& fout)
{
	for (int i = 0; i < GetFigureCount(); i++) {
		FigList[i]->Save(fout);
	}
}

void ApplicationManager::PlayAudio(char* a){
	VoiceAction::AudioPlayer(a);
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
