#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


ClearAllAction::ClearAllAction(ApplicationManager* pApp):Action(pApp){
}

void ClearAllAction::SelectAll(){
	Output* pOut = pManager->GetOutput();

	//loop to unselect all selected figures
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		pFig = pManager->GetFigure(i);
		if (pFig != NULL && !pFig->IsSelected()) {
			pFig->SetSelected(true);
			pFig->Draw(pOut);
		}
	}
}
void ClearAllAction::ReadActionParameters() {
}

void ClearAllAction::Execute() {
	for (int i = 0; i < pManager->GetFigureCount(); i++){
		pFig = pManager->GetFigure(i);
		pFig = NULL;
	}
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	pManager->SetFigCount(0);
}