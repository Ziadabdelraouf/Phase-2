#pragma once
#include <iostream>
#include "AddRectAction.h"
class FillAction: public AddRectAction {
private:
	bool IsFiled;
public:
	FillAction();
	void FilledFigue(AddRectAction R);
};

