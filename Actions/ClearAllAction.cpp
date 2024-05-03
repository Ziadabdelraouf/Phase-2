#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
#include "SelectAction.h"
#include "..\Figures\CFigure.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"


ClearAllAction::ClearAllAction(ApplicationManager* pApp):Action(pApp){
}


void ClearAllAction::ReadActionParameters() {
}

void ClearAllAction::Execute() {
	
	Output* pOut = pManager->GetOutput();
	pManager->ClearAll();
	pOut->ClearDrawArea();
	pManager->SetFigCount(0);
}