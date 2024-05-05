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
	if (temp > 1) {
		pOut->PrintMessage("Can't copy more than one figure");
	}
	
	else {
		pOut->PrintMessage("No figures selected");
	}
	
	
}

void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Pfig != NULL && pManager->GetNumSelected()) {
		

			Pfig = pManager->GetSelectedFig();
			pOut->PrintMessage("figure cpoied");
			pManager->AddClipBoard(Pfig);
			Pfig->SetSelected(false);
		}
	}
	
	
