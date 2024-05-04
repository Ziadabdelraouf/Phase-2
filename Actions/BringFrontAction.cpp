#include "BringFrontAction.h"
#include "Action.h"
#include "../ApplicationManager.h"
#include "SelectAction.h"

BringFrontAction::BringFrontAction(ApplicationManager* papp) :Action(papp) {
}

void BringFrontAction::ReadActionParameters() {

}

void BringFrontAction::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int n = pManager->GetNumSelected();
	int place = 0;
	if (n > 1 || n == 0) {
		string str = "You can't swap more than on figure, please select one figure";
		pOut->PrintMessage(str);
		pManager->PlayAudio("Audio\\SwapingError.wav");

	}
	else {
		for (int i = 0; i < pManager->GetFigureCount(); i++) {
			pFig = pManager->GetFigure(i);
			if (pFig->IsSelected()) {
				place = i;
				break;
			}
		}
		pFig = pManager->GetFigure(place);
		pManager->Swaping(pFig, place,1);
		pOut->PrintMessage("Bring selected figure to front.....");
		pManager->PlayAudio("Audio\\BringToFront.wav");
	}
}