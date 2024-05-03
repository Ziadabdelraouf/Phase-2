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

	pOut->PrintMessage("Delete Tool: Click on a figure");

	

	Pfig = pManager->getfiglist();
	int temp = pManager->GetFigureCount();
	
	if (pManager->GetNumSelected() == 0) {
		pOut->PrintMessage("No figure selected");
	}
	

	if (pManager->GetNumSelected() != 0) {
	
		for (int i = 0; i < pManager->GetFigureCount() ; i++)
		{
			if (Pfig[i]!=NULL) {
				if (Pfig[i]->IsSelected()) {
					Pfig[i]->SetSelected(false);
					Pfig[i] = NULL;
					Pfig[pManager->GetFigureCount() - 1] = NULL;
					/*for (int j = i; i < pManager->GetFigureCount(); i++)
					{
						Pfig[j] = Pfig[j + 1];
					}*/
					pManager->SetFigCount(pManager->GetFigureCount() - 1);
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


/*set <CFigure*>::iterator SelectedFigList = pManager->getFirstFigSelected();
	//CFigure ** listfig = pManager->getFigList();
	int nFigList = pManager->getFigCount();
	int nSelectedFig = pManager->getSelectedFigCount();
	int k=0;

	for (SelectedFigList; k < nSelectedFig; SelectedFigList++)
	{
		nFigList = pManager->getFigCount();
		for (int j=0; j < nFigList; j++)
		{
			if(*(SelectedFigList) == listfig[j])
			{
				delete listfig[j];
				listfig[j] = NULL;
				for (int i=j; i < nFigList-1; i++)
					listfig[i] = listfig[i+1];
				listfig[nFigList-1] = NULL;
				pManager->setfigcount(nFigList-1);
				break;
			}
		}
		k++;
	}
	pManager->ClearSelectedFigList();*/