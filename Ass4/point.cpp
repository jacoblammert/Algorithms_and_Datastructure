
#include <cmath>
#include <iostream>
#include "point.h"

float point::getDist(point p) {
    return sqrt(pow(x_-p.x_,2)+pow(y_-p.y_,2));
}

void point::print() {
    std::cout<<"X: " << x_<<" Y: " << y_<<std::endl;
}
