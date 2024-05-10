#include "LoadAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"


#include "..\GUI\Output.h"
#include <fstream>

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{
}

void LoadAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Enter Filename: ");
	pManager->PlayAudio("Audio\\EnterFileName.wav");
	//Ask user to type the file name to save
	pOut->PrintMessage("Loading Graph... Enter Filename: ");
	str = pIn->GetString(pOut);
}

void LoadAction::LoadData(ifstream &fin)
{
	//string to temporarily store input
	string var;


	//reads the draw color and sets the default draw color to this value
	fin >> var;

	if (var == "BL") {
		UI.DrawColor = BLUE;
	}
	else if (var == "BK") {
		UI.DrawColor = BLACK;
	}
	else if (var == "GN") {
		UI.DrawColor = GREEN;
	}
	else if (var == "RD") {
		UI.DrawColor = RED;
	}
	else if (var == "YL") {
		UI.DrawColor = YELLOW;
	}
	else if (var == "OR") {
		UI.DrawColor = ORANGE;
	}


	//reads the fill color and sets the default fill color to this value
	fin >> var;

	if (var == "BL") {
		UI.FillColor = BLUE;
	}
	else if (var == "BK") {
		UI.FillColor = BLACK;
	}
	else if (var == "GN") {
		UI.FillColor = GREEN;
	}
	else if (var == "RD") {
		UI.FillColor = RED;
	}
	else if (var == "YL") {
		UI.FillColor = YELLOW;
	}
	else if (var == "OR") {
		UI.FillColor = ORANGE;
	}


	//reads number of figures
	int num;
	fin >> num;

	//some more temp variables to store information
	string Shape, Border, Fill;
	Point P1, P2, P3;
	int radius, ID;
	GfxInfo FigGfxInfo;


	//Loop through the lines including the figure information
	//Data is read differently depending on figure type
	//Figure is created and added to the figure list
	//A constructor is used to load data from file and initialise the data members of the figure
	CFigure::setAllStaticZero();
	for (int i = 0; i < num; i++)
	{
		fin >> Shape; //reads type of shape
		fin >> ID;
		if (Shape == "TRI")
		{
			CTriangle* T = new CTriangle(fin, ID);
			pManager->AddFigure(T);
			CFigure::incColorCount(T->getFillClr());
			CFigure::incShapeCount(T->getType());
		}
		else if (Shape == "REC")
		{
			CRectangle* R = new CRectangle(fin, ID);
			pManager->AddFigure(R);
			CFigure::incColorCount(R->getFillClr());
			CFigure::incShapeCount(R->getType());
		}
		else if (Shape == "SQR")
		{
			CSquare* S = new CSquare(fin, ID);
			pManager->AddFigure(S);
			CFigure::incColorCount(S->getFillClr());
			CFigure::incShapeCount(S->getType());
		}
		else if (Shape == "HEX")
		{
			CHexagon* H = new CHexagon(fin, ID);
			pManager->AddFigure(H);
			CFigure::incColorCount(H->getFillClr());
			CFigure::incShapeCount(H->getType());
		}
		else if (Shape == "CIR")
		{
			CCircle* CR = new CCircle(fin, ID);
			pManager->AddFigure(CR);
			CFigure::incColorCount(CR->getFillClr());
			CFigure::incShapeCount(CR->getType());
		}
	}
}


void LoadAction::Execute() {
	ReadActionParameters(); //read input from user

	Output* pOut = pManager->GetOutput(); // get a pointer to output interface

	//prints info of the file the graph data was loaded from
	pOut->PrintMessage("Loaded from: " + str + ".txt");


	//opens file for reading
	ifstream fin("SavedGraphs\\" + str + ".txt");


	//check whether file exists or not
	if (!fin.is_open()) {
		pOut->PrintMessage("Error! No file with this name. Please try again.");
		return;
	}

	//clear drawing area before loading graph
	pManager->ClearAll();
	pOut->ClearDrawArea();


	//extra measure to ensure figure count is correct
	pManager->SetFigCount(0);

	//calls function to load data from file
	LoadData(fin);

	//closes file after load
	fin.close();
}
