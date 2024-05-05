#include "BorderAction.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h";


BorderAction::BorderAction(ApplicationManager* pApp) :Action(pApp) {
	color = BLACK;
	PFig = pManager->GetSelectedFig();
}
void BorderAction::ReadActionParameters() {



	color = pManager->GetColor();


}
void BorderAction::Execute() {

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int n = pManager->GetNumSelected();
	if (n > 1 || n == 0) {
		string str = "Please select only one figure";
		pManager->PlayAudio("Audio\\SelectOneFigure.wav");
		pOut->PrintMessage(str);

	}
	else {
		pOut->PrintMessage("Select color to change border color");
		pManager->PlayAudio("Audio\\BorderColor.wav");
		ReadActionParameters();
		PFig->ChngDrawClr(color);

	}
}
