#include "FillAction.h"
#include <iostream>
#include "AddRectAction.h"
FillAction::FillAction() {
	IsFiled = false;
}
void FillAction::FilledFigue(AddRectAction R) {
	R.GetGfxInfo();
}