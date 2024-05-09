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
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	

	pManager->PlayAudio("Audio\\EnterFileName.wav");

	//Ask user to type the file name to save
	pOut->PrintMessage("Saving Graph..., Enter Filename: ");
	str = pIn->GetString(pOut);
}

void SaveAction::SaveFigures(ofstream& fout)
{
	//saves default draw color
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


	//saves default fill color
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


	//new line
	fout << "\n";


	//saves number of figures
	fout << to_string(pManager->GetFigureCount()) << "\n";


	//calls function to save the information of all figures
	pManager->SaveAll(fout);
}

void SaveAction::Execute() {
	ReadActionParameters(); //read input from user


	Output* pOut = pManager->GetOutput(); // get a pointer to output interface


	
	//opens file for writing
	ofstream fout(str + ".txt");

	SaveFigures(fout);


	//prints info of the file the graph data was saved to
	pOut->PrintMessage("Filename: " + str + ".txt, File has been saved successfully.");
	pManager->PlayAudio("Audio\\FileSaved.wav");

}
