#include "BringFrontAction.h"
#include "Action.h"
#include "../ApplicationManager.h"
#include "SelectAction.h"

BringFrontAction::BringFrontAction(ApplicationManager* papp) :Action(papp) {
}

void BringFrontAction::ReadActionParameters() {

}

void BringFrontAction::Execute() {
		pManager->Swaping(1); //Sending the operator number to the AppManager.
}