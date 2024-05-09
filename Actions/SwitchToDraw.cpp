#include "SwitchToDraw.h"
#include "..\Actions\SwitchToPlay.h"
#include "..\ApplicationManager.h"
SwitchToDraw::SwitchToDraw(ApplicationManager* pApp):Action(pApp)
{
}

void SwitchToDraw::ReadActionParameters()
{
}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();
	
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
	pManager->ClearAll();

	SwitchToPlay* pAct = new SwitchToPlay(pManager);
	pAct->Load();

	delete pAct;
	pAct = NULL;
}
