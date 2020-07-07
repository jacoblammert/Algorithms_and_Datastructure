

#ifndef ALGORITHMS_AND_DATASTRUCTURE_CLOSESTPOINTS_H
#define ALGORITHMS_AND_DATASTRUCTURE_CLOSESTPOINTS_H


#include <vector>
#include "point.h"

class closestPoints {
public:
    std::vector<point> findClosestPoints(std::vector<point> X,std::vector<point> Y);
    std::vector<point> findClosestPointsNaive(std::vector<point> X);
    std::vector<point> combine( std::vector<point> & Y,float l_x,point p1,point p2,point p3, point p4);
    static void printClosestPoints(std::vector<point> points);

};



#endif //ALGORITHMS_AND_DATASTRUCTURE_CLOSESTPOINTS_H
