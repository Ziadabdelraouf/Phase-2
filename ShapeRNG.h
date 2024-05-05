#pragma once
#include <iostream>
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
class ShapeRNG : public Action
{
protected:
    int rshape;
    CFigure* R;
public:
  void Execute();
  ShapeRNG(ApplicationManager* pApp);
  void ReadActionParameters();
};

