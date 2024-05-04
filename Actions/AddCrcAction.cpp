#include "AddCrcAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCrcAction::AddCrcAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCrcAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center of circle");
	pManager->PlayAudio("Audio\\CircleCenter.wav");

	//Read the center of the circle
	pIn->GetPointClicked(C.x, C.y);

	pOut->PrintMessage("New Circle: Click at the end of radius");
	pManager->PlayAudio("Audio\\CircleRadius.wav");

	//Read the radius of the circle
	pIn->GetPointClicked(R.x, R.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCrcAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle*CR = new CCircle(C,R, CircleGfxInfo, pManager->GetFigureCount());

	//Add the Circle to the list of figures
	pManager->AddFigure(CR);
}
