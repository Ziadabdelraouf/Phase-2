#include "PasteAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
PasteAction::PasteAction(ApplicationManager*pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on a figure

	pOut->PrintMessage("Paste Tool: Choose A center");
	pIn->GetPointClicked(P2.x, P2.y);
	Pfig = pManager->GetClipboard();
	x=pManager->GetFigureCount();
	
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	CFigure* Pasted=Pfig->Paste(P2, x);
	pManager->AddFigure(Pasted);
	
	pOut->PrintMessage("Pasted");
	if (pManager->GetIsCut()) {
		pManager->UnselectAll();
		Pfig->SetSelected(true);
		pManager->Delete();
		pManager->SetIsCut(false);
	}
	pManager->UpdateInterface();
}


