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
void LoadAction::Execute() {
	ReadActionParameters(); //read input from user

	Output* pOut = pManager->GetOutput(); // get a pointer to output interface

	//prints info of the file the graph data was saved to
	pOut->PrintMessage("Filename: " + str);

	ifstream fin(str + ".txt");

	if (!fin.is_open()) {
		pOut->PrintMessage("Error! No file with this name.");
		return;
	}
	
	pManager->ClearAll();
	pOut->ClearDrawArea();
	pManager->SetFigCount(0);

	string var;

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

	int num;
	fin >> num;
	string Shape, Border, Fill;
	Point P1, P2, P3;
	int radius, ID;
	GfxInfo FigGfxInfo;

	for (int i = 0; i < num; i++)
	{
		fin >> Shape;
		if (Shape == "TRI")
		{
			fin >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> Border >> Fill;
			if (Border == "BL") {
				FigGfxInfo.DrawClr = BLUE;
			}
			else if (Border == "BK") {
				FigGfxInfo.DrawClr = BLACK;
			}
			else if (Border == "GN") {
				FigGfxInfo.DrawClr = GREEN;
			}
			else if (Border == "RD") {
				FigGfxInfo.DrawClr = RED;
			}
			else if (Border == "YL") {
				FigGfxInfo.DrawClr = YELLOW;
			}
			else if (Border == "OR") {
				FigGfxInfo.DrawClr = ORANGE;
			}
			FigGfxInfo.isFilled = true;
			if (Fill == "NF") {
				FigGfxInfo.isFilled = false;
			}
			else if (Fill == "BL") {
				FigGfxInfo.FillClr = BLUE;
			}
			else if (Fill == "BK") {
				FigGfxInfo.FillClr = BLACK;
			}
			else if (Fill == "GN") {
				FigGfxInfo.FillClr = GREEN;
			}
			else if (Fill == "RD") {
				FigGfxInfo.FillClr = RED;
			}
			else if (Fill == "YL") {
				FigGfxInfo.FillClr = YELLOW;
			}
			else if (Fill == "OR") {
				FigGfxInfo.FillClr = ORANGE;
			}

			CTriangle* T = new CTriangle(P1, P2, P3, FigGfxInfo, ID);
			pManager->AddFigure(T);
		}
		
		if (Shape == "REC")
		{
			fin >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> Border >> Fill;
			if (Border == "BL") {
				FigGfxInfo.DrawClr = BLUE;
			}
			else if (Border == "BK") {
				FigGfxInfo.DrawClr = BLACK;
			}
			else if (Border == "GN") {
				FigGfxInfo.DrawClr = GREEN;
			}
			else if (Border == "RD") {
				FigGfxInfo.DrawClr = RED;
			}
			else if (Border == "YL") {
				FigGfxInfo.DrawClr = YELLOW;
			}
			else if (Border == "OR") {
				FigGfxInfo.DrawClr = ORANGE;
			}
			FigGfxInfo.isFilled = true;
			if (Fill == "NF") {
				FigGfxInfo.isFilled = false;
			}
			else if (Fill == "BL") {
				FigGfxInfo.FillClr = BLUE;
			}
			else if (Fill == "BK") {
				FigGfxInfo.FillClr = BLACK;
			}
			else if (Fill == "GN") {
				FigGfxInfo.FillClr = GREEN;
			}
			else if (Fill == "RD") {
				FigGfxInfo.FillClr = RED;
			}
			else if (Fill == "YL") {
				FigGfxInfo.FillClr = YELLOW;
			}
			else if (Fill == "OR") {
				FigGfxInfo.FillClr = ORANGE;
			}

			CRectangle* R = new CRectangle(P1, P2, FigGfxInfo, ID);
			pManager->AddFigure(R);
		}
		if (Shape == "SQR")
		{
			fin >> ID >> P1.x >> P1.y >> Border >> Fill;
			if (Border == "BL") {
				FigGfxInfo.DrawClr = BLUE;
			}
			else if (Border == "BK") {
				FigGfxInfo.DrawClr = BLACK;
			}
			else if (Border == "GN") {
				FigGfxInfo.DrawClr = GREEN;
			}
			else if (Border == "RD") {
				FigGfxInfo.DrawClr = RED;
			}
			else if (Border == "YL") {
				FigGfxInfo.DrawClr = YELLOW;
			}
			else if (Border == "OR") {
				FigGfxInfo.DrawClr = ORANGE;
			}
			FigGfxInfo.isFilled = true;
			if (Fill == "NF") {
				FigGfxInfo.isFilled = false;
			}
			else if (Fill == "BL") {
				FigGfxInfo.FillClr = BLUE;
			}
			else if (Fill == "BK") {
				FigGfxInfo.FillClr = BLACK;
			}
			else if (Fill == "GN") {
				FigGfxInfo.FillClr = GREEN;
			}
			else if (Fill == "RD") {
				FigGfxInfo.FillClr = RED;
			}
			else if (Fill == "YL") {
				FigGfxInfo.FillClr = YELLOW;
			}
			else if (Fill == "OR") {
				FigGfxInfo.FillClr = ORANGE;
			}

			CSquare* S = new CSquare(P1, FigGfxInfo, ID);
			pManager->AddFigure(S);
		}
		if (Shape == "HEX")
		{
			fin >> ID >> P1.x >> P1.y >> Border >> Fill;
			if (Border == "BL") {
				FigGfxInfo.DrawClr = BLUE;
			}
			else if (Border == "BK") {
				FigGfxInfo.DrawClr = BLACK;
			}
			else if (Border == "GN") {
				FigGfxInfo.DrawClr = GREEN;
			}
			else if (Border == "RD") {
				FigGfxInfo.DrawClr = RED;
			}
			else if (Border == "YL") {
				FigGfxInfo.DrawClr = YELLOW;
			}
			else if (Border == "OR") {
				FigGfxInfo.DrawClr = ORANGE;
			}
			FigGfxInfo.isFilled = true;
			if (Fill == "NF") {
				FigGfxInfo.isFilled = false;
			}
			else if (Fill == "BL") {
				FigGfxInfo.FillClr = BLUE;
			}
			else if (Fill == "BK") {
				FigGfxInfo.FillClr = BLACK;
			}
			else if (Fill == "GN") {
				FigGfxInfo.FillClr = GREEN;
			}
			else if (Fill == "RD") {
				FigGfxInfo.FillClr = RED;
			}
			else if (Fill == "YL") {
				FigGfxInfo.FillClr = YELLOW;
			}
			else if (Fill == "OR") {
				FigGfxInfo.FillClr = ORANGE;
			}

			CHexagon* H = new CHexagon(P1, FigGfxInfo, ID);
			pManager->AddFigure(H);
		}
		if (Shape == "CIR")
		{
			fin >> ID >> P1.x >> P1.y >> radius >> Border >> Fill;
			if (Border == "BL") {
				FigGfxInfo.DrawClr = BLUE;
			}
			else if (Border == "BK") {
				FigGfxInfo.DrawClr = BLACK;
			}
			else if (Border == "GN") {
				FigGfxInfo.DrawClr = GREEN;
			}
			else if (Border == "RD") {
				FigGfxInfo.DrawClr = RED;
			}
			else if (Border == "YL") {
				FigGfxInfo.DrawClr = YELLOW;
			}
			else if (Border == "OR") {
				FigGfxInfo.DrawClr = ORANGE;
			}
			FigGfxInfo.isFilled = true;
			if (Fill == "NF") {
				FigGfxInfo.isFilled = false;
			}
			else if (Fill == "BL") {
				FigGfxInfo.FillClr = BLUE;
			}
			else if (Fill == "BK") {
				FigGfxInfo.FillClr = BLACK;
			}
			else if (Fill == "GN") {
				FigGfxInfo.FillClr = GREEN;
			}
			else if (Fill == "RD") {
				FigGfxInfo.FillClr = RED;
			}
			else if (Fill == "YL") {
				FigGfxInfo.FillClr = YELLOW;
			}
			else if (Fill == "OR") {
				FigGfxInfo.FillClr = ORANGE;
			}

			CCircle* CR = new CCircle(P1, radius, FigGfxInfo, ID);
			pManager->AddFigure(CR);
		}

	}
}
