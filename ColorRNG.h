#pragma once
#include <iostream>
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
class ColorRNG : public Action
{
protected:
    int rcolor;
    CFigure* R;
public:
    void Execute();
    ColorRNG(ApplicationManager* pApp);
    void ReadActionParameters();
};

