#include "CutAction.h"
color CutAction::tempDraw = BLACK;
color CutAction::tempFill = BLACK;
bool CutAction::WasFill = false;
CFigure* CutAction::Pfig = NULL;
CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetNumSelected() > 1) //check selected figure count
	{ 
		pOut->PrintMessage("Can't copy more than one figure");
		
	}
	else if (pManager->GetNumSelected() == 1 && !pManager->GetIsCut()) //in case this is the first cut action
	{
		if (pManager->GetClipboard() != NULL) {
			Previous = pManager->GetClipboard();
			delete Previous;
			Previous = NULL;
		}
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{
			
			
			Pfig = pManager->GetSelectedFig(); //return selected figure
			
			pManager->SetIsCut(true);     //set that the figure in the clipboard is cut not copied (used again in Paste)
			
		}
	}
	else if (pManager->GetNumSelected() == 1 && pManager->GetIsCut()) //if the clipboard is from a cut 
	{
		
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{
			//restore the orginal info of the figure
			Pfig->ChngDrawClr(tempDraw);
			if (WasFill) {
				Pfig->ChngFillClr(tempFill);
				
			}
			Pfig = pManager->GetSelectedFig();
			
		}
		if (pManager->GetClipboard() != NULL)
		{
			//deallocate previous clipboard
			Previous = pManager->GetClipboard();
			delete Previous;
			Previous = NULL;
		}
	}
	else if(pManager->GetNumSelected()==0) {

		pOut->PrintMessage("No figures selected");
	}
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (pManager->GetNumSelected()==1) 
	{
		Pfig->SetSelected(false);
		
		//Store the info of the figure
		tempDraw = Pfig->GetDrawClr();
		if (Pfig->IsFilled()) {
			tempFill = Pfig->GetFillClr();
			WasFill = true;

		}
		//Create a copy of the figure and add it to clipboard
		CFigure* Temp = Pfig->CreateCopy();
		pManager->AddClipBoard(Temp);

		//Change the fill and draw color of figure to gray
		Pfig->ChngDrawClr(GRAY);
		if (Pfig->IsFilled()) {
			Pfig->ChngFillClr(GRAY);
		}
			pOut->PrintMessage("Cut");
		pManager->UpdateInterface();
		
		
		
	}

}

void CutAction::UnCut(){

	//set the figure as selected 
	Pfig->SetSelected(true);  //ssets previously cut object as selected


	pManager->Delete();  //calls delete function
}

