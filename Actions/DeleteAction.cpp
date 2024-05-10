#include "DeleteAction.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "SelectAction.h"
#include "..\Figures\Cfigure.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{

}

void DeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//calls the delete function in application manager
	pManager->Delete();
	
	
	
}
void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->UpdateInterface();
	
	
	
}
void DeleteAction::Delete(CFigure*Temp) {
	
	
	Temp = NULL;
	
}


