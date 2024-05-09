#include "CutAction.h"
color CutAction::tempDraw = BLACK;
color CutAction::tempFill = BLACK;
bool CutAction::WasFill = false;
CFigure* CutAction::Pfig = NULL;
CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{

}

void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetNumSelected() > 1) { //check selected figure count
		pOut->PrintMessage("Can't copy more than one figure");
		
	}
	else if (pManager->GetNumSelected() == 1 && !pManager->GetIsCut()) {
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{

			//delete element from clipboard (bkml sho8l 3leha )

			/*if (pManager->GetClipboard() != NULL) {
				Previous = pManager->GetClipboard();
				delete Previous;
				Previous = NULL;
			}*/
			Pfig = pManager->GetSelectedFig(); //return selected figure
			
			pManager->SetIsCut(true);     //set that the figure in the clipboard is cut not copied (used again in Paste)
			
		}
	}
	else if (pManager->GetNumSelected() == 1 && pManager->GetIsCut()) //if the clipboard is from a cut 
	{
		for (int i = 0; i < pManager->GetFigureCount(); i++)
		{
			
			Pfig->ChngDrawClr(tempDraw);
			if (WasFill) {
				Pfig->ChngFillClr(tempFill);
				
			}
			Pfig = pManager->GetSelectedFig();


			//delete element from clipboard (bkml sho8l 3leha )

			/*if (pManager->GetClipboard() != NULL) {
				Previous = pManager->GetClipboard();
				delete Previous;
				Previous = NULL;
			}*/
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
		pManager->SetIsCut(true);
		CFigure* Temp = Pfig->CreateCopy(Pfig);
		pManager->AddClipBoard(Temp);
		pManager->SetIsCut(true);
		Pfig->ChngDrawClr(GRAY);
		if (Pfig->IsFilled()) {
			Pfig->ChngFillClr(GRAY);
		}
			pOut->PrintMessage("Cut");
		pManager->UpdateInterface();
		
		
		
	}

}

void CutAction::UnCut(){

	Pfig->SetSelected(true);
	pManager->Delete();
}

