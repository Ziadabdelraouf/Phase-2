#include "DeleteAction.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{

}

void DeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	

	

	Pfig = pManager->GetAllSelected();
	
	
	if (pManager->GetNumSelected() == 0) {
		pOut->PrintMessage("No figure selected");
	}
	

	if (pManager->GetNumSelected() != 0) {
	
		for (int i = 0; i < pManager->GetNumSelected()+1; i++)
		{
			if (Pfig[i]!=NULL) {
				 
					Pfig[i]->SetSelected(false);
					delete Pfig[i];
					Pfig[i] = NULL;
					pManager->SetFigCount(pManager->GetFigureCount() - 1);
					for (int j = i; j < pManager->GetFigureCount(); j++)
					{
						Pfig[j] = Pfig[j + 1];
					}
					
				}
			}
		
	}
	
}
void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->UpdateInterface();
	
	
}
void DeleteAction::Delete(CFigure*Temp) {
	
	
	Temp = NULL;
	
}


