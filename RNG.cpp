#include "RNG.h"
int RNG::shapeRNG() {
    srand(time(nullptr));
    rshape = rand() % 5;
    return rshape;
}
int RNG::colorRNG() {
    srand(time(nullptr));
    rcolor = rand() % 6;
    return rcolor;
}
RNG::RNG() {
    rshape = -1;
    rcolor = -1;
}
