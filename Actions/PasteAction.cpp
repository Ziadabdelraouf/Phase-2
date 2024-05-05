#include "PasteAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTriangle.h"
PasteAction::PasteAction(ApplicationManager*pApp):Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Ask user to click on a figure

	pOut->PrintMessage("Paste Tool: Choose A center");
	pIn->GetPointClicked(P2.x, P2.y);
	Pfig = pManager->GetClipboard();
	
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	char temp = Pfig->FigType();
	pOut->PrintMessage("Ppp");
	switch (temp) {
	case 'H':
		CreateHex();
		break;
	case 'S':
		CreateSquare();
		break;
	case 'C':
		CreateCircle();
		break;
	case 'k':
		pOut->PrintMessage("Pas");
		break;
	pManager->UpdateInterface();
}
}
void PasteAction::CreateHex() {
	Output* pOut = pManager->GetOutput();
	GfxInfo tempinf = Pfig->GetGfxInfo();
	CHexagon* H = new CHexagon(P2, tempinf, pManager->GetFigureCount() + 1);
	pManager->AddFigure(H);
	pOut->PrintMessage("Pasted a hexagon");
}

void PasteAction::CreateSquare()
{
	Output* pOut = pManager->GetOutput();
	GfxInfo tempinf = Pfig->GetGfxInfo();
	CSquare* S = new CSquare(P2, tempinf, pManager->GetFigureCount() + 1);
	pManager->AddFigure(S);
	pOut->PrintMessage("Pasted a square");
}

void PasteAction::CreateCircle()
{
	Output* pOut = pManager->GetOutput();
	GfxInfo tempinf = Pfig->GetGfxInfo();
	float Rad=Pfig->GetRaduis();
	Point P3;
	P3.y = P2.y+Rad;
	CCircle* C = new CCircle(P2, P3,tempinf, pManager->GetFigureCount() + 1);
	pManager->AddFigure(C);
	pOut->PrintMessage("Pasted");
}

