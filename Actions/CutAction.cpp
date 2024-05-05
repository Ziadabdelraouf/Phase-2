#include "CutAction.h"
color CutAction::tempDraw = BLACK;
color CutAction::tempFill = BLACK;
bool CutAction::WasFill = false;
CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetNumSelected() > 1) {
		pOut->PrintMessage("Can't copy more than one figure");
		
	}
	else if (pManager->GetNumSelected() == 1 && !pManager->GetIsCut()) {
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{

			Pfig = pManager->GetSelectedFig();
			pOut->PrintMessage("Cut");
			pManager->SetIsCut(true);
			
		}
	}
	else if (pManager->GetNumSelected() == 1 && pManager->GetIsCut()) {
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{
			Pfig = pManager->GetClipboard();
			Pfig->ChngDrawClr(tempDraw);
			if (WasFill) {
				Pfig->ChngFillClr(tempFill);
				
			}
		
			
			Pfig->Draw(pOut);
			pOut->PrintMessage("Cut1");
			Pfig = pManager->GetSelectedFig();

		}
	}
	else if(pManager->GetNumSelected()==0) {

		pOut->PrintMessage("No figures selected");
	}
}

void CutAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (pManager->GetNumSelected()==1) {
		Pfig->SetSelected(false);
		tempDraw = Pfig->GetDrawClr();
		if (Pfig->IsFilled()) {
			tempFill = Pfig->GetFillClr();
			WasFill = true;

		}
		
		
	
		Pfig->ChngDrawClr(GRAY);
		/*Pfig->ChngFillClr(GRAY);*/
		pManager->AddClipBoard(Pfig);
		
	}

}


