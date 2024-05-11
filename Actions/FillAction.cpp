#include "FillAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h";


FillAction::FillAction(ApplicationManager* pApp) :Action(pApp){

	color = BLACK;
	PFig = pManager->GetSelectedFig();//Set the pointer to the selected figure.
}
void FillAction::ReadActionParameters() {

	color = pManager->GetColor();//Get the selected color.
}
void FillAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int n = pManager->GetNumSelected();
	//Check for the number of selected figure.
	if (n > 1 ||n == 0) {
		string str = "Please select only one figure";
		pManager->PlayAudio("Audio\\SelectOneFigure.wav");
		pOut->PrintMessage(str);
	}
	else {
		pOut->PrintMessage("Select color to fill");
		pManager->PlayAudio("Audio\\SelectColor.wav");
		ReadActionParameters();//Get the color before fill action.
		PFig->ChngFillClr(color);
		pManager->UnselectAll(); 
		
	}
}

