
#include <cmath>
#include <iostream>
#include "point.h"

/**
 * returns the (float) distance from itself to point p
 * @param p point we want to get the distance from
 * @return distance as float
 */
float point::getDist(point p) {
    return sqrt(pow(x_-p.x_,2)+pow(y_-p.y_,2));
}

/**
 * Prints the x and y coordinate of a point
 */
void point::print() {
    std::cout<<"X: " << x_<<" Y: " << y_<<std::endl;
}
