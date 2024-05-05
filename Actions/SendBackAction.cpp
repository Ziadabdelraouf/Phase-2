#include "SendBackAction.h"
#include "Action.h"
#include "../ApplicationManager.h"
#include "SelectAction.h"

SendBackAction::SendBackAction(ApplicationManager* papp) :Action(papp) {
}

void SendBackAction::ReadActionParameters() {

}

void SendBackAction::Execute() {

		pManager->Swaping(2); //Sending the operrator number to the AppManager
		
}