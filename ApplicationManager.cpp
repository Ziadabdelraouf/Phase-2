#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCrcAction.h"
#include "Actions\SelectAction.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\CutAction.h"
#include "Actions\FillAction.h"
#include "Actions\BorderAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\SendBackAction.h"
#include "Actions\BringFrontAction.h"
#include "Actions\PasteAction.h"
#include "Actions\ShapeRNG.h"
#include "Actions\SaveAction.h"
#include "Actions\ColorRNG.h"
#include "Actions\BothRNG.h"
#include "Actions\VoiceAction.h"
#include "Actions\LoadAction.h"
#include "Actions\PlayShape.h"
#include "Actions\PlayColor.h"	
#include "Figures\CFigure.h"
#include "Actions\PlayBoth.h"
#include "GUI/UI_Info.h"
#include "Actions\SwitchToPlay.h"
#include "Actions\SwitchToDraw.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;  //Set initially fig num to 0.
	SelectedFigCount = 0;
	FigerIndex = 0;
	Clipboard = NULL;
	SelectedFig = NULL;
	IsCut = false;
	LastAction = CHANGE_FILLING_COLOR;
		

	Color = GREEN;
		
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
			LastAction = CHANGE_FILLING_COLOR;
			break;
		case CHANGE_BORDER_COLOR:
			pAct = new BorderAction(this);
			LastAction = CHANGE_BORDER_COLOR;
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
			break;
		case SHAPE:
			pAct = new PlayShape(this);
	          break;
                case COLOR:
			pAct = new PlayColor(this);
	         break;

		case BOTH:
			pAct = new PlayBoth(this);
	        break;

        case TO_DRAW:
			pAct = new SwitchToDraw(this);
			UI.InterfaceMode = MODE_DRAW;
	        UI.InterfaceMode = MODE_DRAW;
	        break;
        case TO_PLAY:
			pAct = new SwitchToPlay(this);
			UI.InterfaceMode = MODE_PLAY;
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
		case DELETEFIG:
			pAct = new DeleteAction(this);
			break;
		case COPYFIG:
			pAct = new CopyAction(this);
			break;
		case CUTFIG:
			pAct = new CutAction(this);
			break;
		case PASTEFIG:
			pAct = new PasteAction(this);
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
bool ApplicationManager::GetIsCut()
{
	return IsCut;
}
void ApplicationManager::SetIsCut(bool temp)
{
	IsCut = temp;
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
		if (FigList[i] != NULL) {
			if (FigList[i]->IsClickInside(x, y)) {
				return FigList[i];
			}
		}
	}
	
	//If this point (x,y) does not belong to any figure return NULL
	return NULL;
}


////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int id) const //TO BE REMOVED -Yousef
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
	FigCount = (n>=0) ? n:0; //sets actual number of figures
}

////////////////////////////////////////////////////////////////////////////////////
//Used to return the selected figure when only one figure is selected
CFigure* ApplicationManager::GetSelectedFig() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			return FigList[i];  
		}
	}
	return NULL;
}
CFigure** ApplicationManager::GetAllSelected() {
	CFigure* Selected[MaxFigCount];
	for (int i = 0; i < MaxFigCount; i++)
	{
		Selected[i] = NULL;
	}
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			Selected[i] = FigList[i];
	}
	return Selected;
}
void ApplicationManager::AddClipBoard(CFigure*pFig)
{
	Clipboard = pFig;
}
CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
	
}
int ApplicationManager::GetNumSelected() {
	SelectedFigCount = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			SelectedFigCount++;
		}
	}
	return SelectedFigCount;
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::PasteFigure(){
	Action* pAct = NULL;
	pAct = new PasteAction(this);
}

/////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::UnCut() {
	CutAction temporary(this);
	temporary.Uncut();
	
}

void ApplicationManager::Delete()
{
	
	for (int i = 0; i < FigCount; i++){
		
		
		CFigure* R;   // A pointer to Figure
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);
			CFigure::decStaticMembers(FigList[i]);
			R = FigList[i];
			for (int k = i; k < FigCount - 1; k++) {
				FigList[k] = FigList[k + 1]; // Shift elements to the left
			}
			FigCount--;   //decrement figure count
			i--;     //recheck the shifted figure
			delete R;   //delete object
			R = NULL;    //set to NULL
 			
		}

	}
	
	 
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::UnselectAll()
{
	for (int i = 0; i < GetFigureCount(); i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->SetSelected(false); //unselects figure if selected
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Deletes all figures
void ApplicationManager::ClearAll(){
	//Loop at each figure in the figure list and set all pointers to null
	for (int i = 0; i < GetFigureCount(); i++) {
		delete FigList[i];
		FigList[i] = NULL;  
	}
	delete Clipboard;
	Clipboard = NULL;
}

////////////////////////////////////////////////////////////////////////////////////
color ApplicationManager::GetColor() {
	ActionType ActType;
	ActType = GetUserAction();
	switch (ActType)
	{
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
		Color = YELLOW;;
		PlayAudio("Audio\\Yellow.wav");
		pOut->PrintMessage("Yellow");
		break;

	case COLOR_RED:
		Color = RED;;
		PlayAudio("Audio\\Red.wav");
		pOut->PrintMessage("Red");
		break;

	case DELETEFIG:
		Color = LIGHTGOLDENRODYELLOW;
		PlayAudio("Audio\\UnFill.wav");
		pOut->PrintMessage("Unfill the figure...");
		break;

	default: //If the user clicked in anywhaere not the colors the color will set to default.
		if (LastAction == CHANGE_FILLING_COLOR){
			Color = UI.FillColor;
		}
		else
		{
			Color = UI.DrawColor;
		}
	}
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

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SaveAll(ofstream& fout)
{
	for (int i = 0; i < GetFigureCount(); i++) {
		FigList[i]->Save(fout); //calls save function for each figure
	}
}

////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::LoadAll(ifstream& fin)
{
	for (int i = 0; i < GetFigureCount(); i++) {
		FigList[i]->Load(fin); //calls load function for each figure
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Voice action.
void ApplicationManager::PlayAudio(char* FileName){
	//FileName must be .wav file.
	VoiceAction::AudioPlayer(FileName);
}

////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::randNumGenBoth(int& sh,int& c) {
	if (SelectedFig->getFilledCount() == 0) //checks if the filled shapes count is zero
		return;
	int i;
	do {
		srand(time(nullptr));
		i = rand()%FigCount;  //get random number between 0 and figcount-1
	} while (!FigList[i]->IsFilled());
	c = FigList[i]->getFillClr();
	sh = FigList[i]->getType();
	return;
}

void ApplicationManager::randNumGenBothS(int& sh) {
	if (FigCount == 0) //check if the figures count is zero
		return;
	int i;
		srand(time(nullptr));
		i = rand() % FigCount;  //get random number between 0 and figcount-1
	sh = FigList[i]->getType();
	return;
}


void ApplicationManager::randNumGenBoth(int& c) {
	if (SelectedFig->getFilledCount() == 0) //checks if the filled shapes count is zero
		return;
	int i;
	do {
		srand(time(nullptr));
		i = rand() % FigCount; //get random number between 0 and figcount-1
	} while (!FigList[i]->IsFilled());
	c = FigList[i]->getFillClr();
	
	return;
}

////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::getRandNumcount(int shape, int clr) {
	int x=0;
	for (int i = 0; i < FigCount; i++) //loops the figlist and inc the counter when the matching type with matching fill color appears
	{
		if (FigList[i]->IsFilled()) {
			if (FigList[i]->getFillClr()==clr &&FigList[i]->getType()==shape)
			{
				x++;
			}
		}
	}
	return x;
}

////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::usedBeforeDeleteInPlay(CFigure* fig) {
	int j = 0;
	for (j; j < FigCount; j++) //it's only use is to get the index of the fig sent to it
	{
		if (fig==FigList[j])
		{
			break;
		}
	}
	for (int i = j; i < FigCount - 1; i++) {
		FigList[i] = FigList[i + 1]; // it's only use is to push all the figures after the fig to the left once
	}
	FigCount--;
	return;
}

////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<GetFigureCount(); i++)
		if (FigList[i]!=NULL)
		{
			FigList[i]->Draw(pOut); //Call Draw function (virtual member fn)
		}
				
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
		if (FigList[i]!=NULL){
			delete FigList[i];
		}
	delete Clipboard;
	delete SelectedFig;
	delete pIn;
	delete pOut;
}
