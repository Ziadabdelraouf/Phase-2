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
	pManager->PlayAudio("Audio\\CircleCenter.wav"); //circle center voice acting

	//Read the center of the circle
	pIn->GetPointClicked(C.x, C.y);

	pOut->PrintMessage("New Circle: Click at the end of radius");
	pManager->PlayAudio("Audio\\CircleRadius.wav");  //circel radius voice acting

	//Read the point on radius of the circle
	pIn->GetPointClicked(R.x, R.y);

	radius = sqrt((R.x - C.x) * (R.x - C.x) + (R.y - C.y) * (R.y - C.y)); //calculates radius of circle


	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar(); //To clean status bar after drawing finished

}

//Execute the action
void AddCrcAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle*CR = new CCircle(C, radius, CircleGfxInfo, pManager->GetFigureCount());

	//Add the Circle to the list of figures
	pManager->AddFigure(CR);
	delete CR;
}
