#include "BorderAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h";


BorderAction::BorderAction(ApplicationManager* pApp) :Action(pApp) {

	color = BLACK;
	PFig = pManager->GetSelectedFig();   //Set the pointer to the selected figure.
}
void BorderAction::ReadActionParameters() {

	color = pManager->GetColor();  //Get the selected color.
}
void BorderAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int n = pManager->GetNumSelected();  
	//Check for the number of selected figure.
	if (n > 1 || n == 0) {
		pManager->PlayAudio("Audio\\SelectOneFigure.wav");
		pOut->PrintMessage("Please select only one figure");

	}
	else {
		pOut->PrintMessage("Select color to change border color: ");
		pManager->PlayAudio("Audio\\BorderColor.wav");
		ReadActionParameters();  //Get the color before change border color action.
		if (color == UI.FillColor) {
			color = UI.DrawColor;
		}
		PFig->ChngDrawClr(color);
		pManager->UnselectAll();  //Unselect the figure to show the action.
	}
}
