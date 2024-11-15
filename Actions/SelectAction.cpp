#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
}
void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on a figure

	pOut->PrintMessage("Select Tool: Click on a figure");
	pManager->PlayAudio("Audio\\Select.wav");
	pIn->GetPointClicked(P1.x, P1.y);


	

	pFig = pManager->GetFigure(P1.x, P1.y); //gets pointer to the figure clicked on
	pOut->ClearStatusBar();
}





void SelectAction::Execute()
{
	ReadActionParameters(); //sets pFig to point to the figure clicked on
	Output* pOut = pManager->GetOutput();

	if (pFig != NULL) {
		if (pFig->IsSelected()) {
			pFig->SetSelected(false); //unselects figure if selected
		}
		else {
			pFig->SetSelected(true);
			if(pManager->GetNumSelected() == 1)
				pFig->PrintInfo(pOut); //displays info if only one is selected
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
		pManager->UnselectAll();//unselects all if click is not on a figure (click is on empty space)
}
	

