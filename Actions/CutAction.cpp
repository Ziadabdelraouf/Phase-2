#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int temp = pManager->GetNumSelected();
	if (temp > 1) {
		pOut->PrintMessage("Can't copy more than one figure");
	}
	else if (temp == 1) {
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{

			Pfig = pManager->GetSelectedFig();
		}
	}
	else {

		pOut->PrintMessage("No figures selected");
	}
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (!IsCut) {
		pManager->AddClipBoard(Pfig);
        
		Pfig->SetSelected(false);
		tempDraw= pManager->GetColor();

		Pfig->ChngDrawClr(GRAY);
		Pfig->ChngFillClr(GRAY);
		Pfig->Draw(pOut);
	}


}


