#include "CopyAction.h"
#include "SelectAction.h"

CopyAction::CopyAction(ApplicationManager* pApp):Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int temp = pManager->GetNumSelected();
	if (pManager->GetNumSelected() > 1) //check number of selected figures
	{  
		pOut->PrintMessage("Can't copy more than one figure");
	}
	
	else if(pManager->GetNumSelected() == 0) {
		pOut->PrintMessage("No figures selected");
	}
	else if (pManager->GetNumSelected() == 1) {
		Pfig = pManager->GetSelectedFig();
		pOut->PrintMessage("figure copied");
	}
	
}

void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Pfig != NULL && pManager->GetNumSelected())
	{
		if (pManager->GetClipboard() != NULL)   //check if another object is in the clipboard and delete it
		{   
			CFigure* Previous = NULL; //create a temporary pointer 
			Previous = pManager->GetClipboard();
			delete Previous;
			Previous = NULL;
		}
			CFigure* Temp = Pfig->CreateCopy();   //create a copy of the selected figure
			pManager->AddClipBoard(Temp);         //add it to the clipboard
			Pfig->SetSelected(false);        
	}
}

	
	
