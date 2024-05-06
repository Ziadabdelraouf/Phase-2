#pragma once
#include <iostream>
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
class BothRNG:public Action
{
protected:
    int rcolor;
    int rshape;
    int num;    //number of the figures to be clicked
    CFigure* R;
    string s1;
    string s2;
public:
    void Execute();
    BothRNG(ApplicationManager* pApp);
    void ReadActionParameters();
};

