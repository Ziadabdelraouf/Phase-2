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


	Pfig = pManager->GetClipboard();
	if (Pfig==NULL) {
		pOut->PrintMessage("NO figure to paste");

	}
	else {

		//Ask user to click on a figure

		pOut->PrintMessage("Paste Tool: Choose A center");
		pIn->GetPointClicked(P2.x, P2.y);
		FigCount = pManager->GetFigureCount();
	}
	
	
	
	
	
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Pfig!=NULL)  // if cclipboard not empty
	
	{
		CFigure* Pasted = Pfig->Paste(P2, FigCount);  //create a pasted version of the figure in clipboard
		pManager->AddFigure(Pasted);  // add the psted to clipboard
		pOut->PrintMessage("Pasted");  // print messange


		if (pManager->GetIsCut()) //check if the clipboard is from cut or copy
		{
			pManager->UnselectAll();  //unselect all figures (to prevent deleting other figures by mistake)

			pManager->UnCut();  //calls uncut function
			pManager->SetIsCut(false);  //set that the clipboard is not from cut anymore
		}
		pManager->UpdateInterface();
	}
	
}


