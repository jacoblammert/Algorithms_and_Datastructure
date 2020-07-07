

#include <iostream>
#include <vector>
#include "point.h"
#include "closestPoints.h"


void ClosestPoint(){

    closestPoints cp;

    std::vector<point> points{{0,0},{1,0},{5,7}/*,{7,6}*/};
    std::vector<point> result = cp.findClosestPoints(points,{});

    cp.printClosestPoints(result);



}


int main(){

    ClosestPoint();


    return 0;
}