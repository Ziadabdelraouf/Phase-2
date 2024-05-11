#pragma once
#include <iostream>
#include "../DEFS.h"
#include "../Figures/CFigure.h"
#include "Action.h"
#include "../ApplicationManager.h"

class ShapeRNG : public Action
{
protected:
    int rshape; //the integer that express the shape type based on the defs.h (RNGshape)
    CFigure* R; //pointer for using Cfigure functions
public:
  void Execute();
  ShapeRNG(ApplicationManager* pApp);
  void ReadActionParameters();
};

