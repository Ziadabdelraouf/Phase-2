#pragma once
#include <iostream>
#include "../DEFS.h"
#include "../Figures/CFigure.h"
#include "Action.h"
#include "../ApplicationManager.h"
class BothRNG:public Action
{
protected:
    int rcolor; //the integer that express the color based on the defs.h (RNGcolor)
    int rshape; //the integer that express the shape type based on the defs.h (RNGshape)
    int num;    //number of the figures to be clicked
    CFigure* R; //pointer that is used to access cfigure functions
    string s1; //string that is used at the first part of the text
    string s2; //string that is used at the second part of the text (after the numbers of the shape to be picked)
public:
    void Execute();
    BothRNG(ApplicationManager* pApp);
    void ReadActionParameters();
};

