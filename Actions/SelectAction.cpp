#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{
}
int  SelectAction::NumSelected = 0; //counter for selected figures
void SelectAction::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	//Ask user to click on a figure
	
	pOut->PrintMessage("Select Tool: Click on a figure");
	pIn->GetPointClicked(P1.x, P1.y);
	
	SelectAction::NumSelected = 0; //initialising of counter
	
	//loop to check the number of selected figure
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		pFig = pManager->GetFigure(i);
		if (pFig->IsSelected())
		{
			SelectAction::NumSelected++;
		}
	}
	pFig = pManager->GetFigure(P1.x, P1.y); //gets pointer to the figure clicked on
	pOut->ClearStatusBar();
}

void SelectAction::UnselectAll()
{
	Output* pOut = pManager->GetOutput();
	
	//loop to unselect all selected figures
	for (int i = 0; i < pManager->GetFigureCount(); i++)
	{
		pFig = pManager->GetFigure(i);
		if (pFig != NULL && pFig->IsSelected()) {
			pFig->SetSelected(false);
			pFig->Draw(pOut);
		}
	}
}

void SelectAction::Execute()
{
	ReadActionParameters(); //sets pFig to point to the figure clicked on
	Output* pOut = pManager->GetOutput();
	

	if (pFig != NULL) {
		if (pFig->IsSelected()) {
			pFig->SetSelected(false);
			pFig->Draw(pOut);
		}
		else {
			pFig->SetSelected(true);
			pFig->Draw(pOut);
			if(NumSelected == 0)
				pFig->PrintInfo(pOut); //displays rectangle info if only one is selected
			else {
				string str;
				str = "Selected: ";
				if (pFig->getRecSelectedCount()) {
					str += to_string(pFig->getRecSelectedCount());
					str += " Rectangle(s), ";
				}
				if (pFig->getSqrSelectedCount()) {
					str += to_string(pFig->getSqrSelectedCount());
					str += " Square(s), ";
				}
				if (pFig->getTriSelectedCount()) {
					str += to_string(pFig->getTriSelectedCount());
					str += " Triangles(s), ";
				}
				if (pFig->getHexSelectedCount()) {
					str += to_string(pFig->getHexSelectedCount());
					str += " Hexagon(s), ";
				}
				if (pFig->getCircleSelectedCount()) {
					str += to_string(pFig->getCircleSelectedCount());
					str += " Circle(s)";
				}
				pOut->PrintMessage(str); //displays number of each type of figure selected
			}
		}
	}
	else
		UnselectAll(); //unselects all if click is not on a figure (click is on empty space)
}
int SelectAction::GetNumSelect() {
	return NumSelected;
}

