#include "SwitchToPlay.h"
#include "LoadAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"

#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "SaveAction.h"

#include "..\GUI\Output.h"
#include <fstream>

SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlay::ReadActionParameters()
{

}

void SwitchToPlay::Load()
{
	ifstream fin("playmodesave.txt");
	
	//clear drawing area before loading graph
	pManager->ClearAll();

	//extra measure to ensure figure count is correct
	pManager->SetFigCount(0);

	LoadAction* pAct = new LoadAction(pManager);

	pAct->LoadData(fin);
	
	delete pAct;
	pAct = NULL;
	
	pManager->UpdateInterface();
}

void SwitchToPlay::Save()
{
	ofstream fout("playmodesave.txt");

	SaveAction* pAct = new SaveAction(pManager);

	pAct->SaveFigures(fout);
	delete pAct;
	pAct = NULL;
}

void SwitchToPlay::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	Save();

	pManager->ClearAll();
	pOut->CreatePlayToolBar();
	pOut->ClearStatusBar();

	Load();
}
