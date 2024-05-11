#pragma once
#include <iostream>
#include "../DEFS.h"
#include "../Figures/CFigure.h"
#include "Action.h"
#include "../ApplicationManager.h"

class ColorRNG : public Action
{
protected:
    int rcolor; //the integer that express the color based on the defs.h (RNGcolor)
    CFigure* R; //pointer used to access the functions of Cfigure
public:
    void Execute();
    ColorRNG(ApplicationManager* pApp);
    void ReadActionParameters();
};

