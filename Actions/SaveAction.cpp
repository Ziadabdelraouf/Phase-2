#include "SaveAction.h"
#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Enter Filename: ");
	str = pIn->GetString(pOut);
}

void SaveAction::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Filename: " + str);
	ofstream fout(str + ".txt");
	pManager->SaveAll(fout);
}
