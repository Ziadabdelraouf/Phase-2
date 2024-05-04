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
	if (UI.DrawColor == BLUE) {
		fout << "BL\t";
	}
	else if (UI.DrawColor == BLACK) {
		fout << "BK\t";
	}
	else if (UI.DrawColor == GREEN) {
		fout << "GN\t";
	}
	else if (UI.DrawColor == RED) {
		fout << "RD\t";
	}
	else if (UI.DrawColor == YELLOW) {
		fout << "YL\t";
	}
	else if (UI.DrawColor == ORANGE) {
		fout << "OR\t";
	}
	
	if (UI.FillColor == BLUE) {
		fout << "BL";
	}
	else if (UI.FillColor == BLACK) {
		fout << "BK";
	}
	else if (UI.FillColor == GREEN) {
		fout << "GN";
	}
	else if (UI.FillColor == RED) {
		fout << "RD";
	}
	else if (UI.FillColor == YELLOW) {
		fout << "YL";
	}
	else if (UI.FillColor == ORANGE) {
		fout << "OR";
	}

	fout << "\n";
	fout << to_string(pManager->GetFigureCount()) << "\n";

	pManager->SaveAll(fout);
}
