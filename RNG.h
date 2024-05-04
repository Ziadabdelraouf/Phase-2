#pragma once
#include <iostream>
#include "DEFS.h"
class RNG
{
protected:
    int rshape;
    int rcolor;
    
public:
    RNG();
    int shapeRNG();
    int colorRNG();
};
