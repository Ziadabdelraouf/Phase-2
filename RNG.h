#pragma once
#include <iostream>
#include "DEFS.h"
#include "Figures/CFigure.h"
#include "Actions/Action.h"
class RNG: public Action
{
protected:
    int rshape;
    int rcolor;
    Output* pOut;
    CFigure *R;
public:
    RNG();
   virtual void shapeRNG();
   virtual int colorRNG();
};
