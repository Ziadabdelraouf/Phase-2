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
	else if (temp == 1) {
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{

			Pfig=pManager->GetSelectedFig();
		}
	}
	else {
		
		pOut->PrintMessage("No figures selected");
	}
	
	
}

void CopyAction::Execute()
{
	ReadActionParameters();
	pManager->AddClipBoard(Pfig);
}
