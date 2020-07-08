

#include <iostream>
#include <vector>
#include "point.h"
#include "closestPoints.h"


/*
 * A function to generate a vector with random points inside a given rectangle
 */
void ClosestPoint() {

    std::cout << "\n\n\nTest:\n\n";

    closestPoints cp;

    float dist = 102; /// If we change the dist value, we can get a wide range of random outputs
    ///We can do so, if it takes to long to change the seed of the randomness function

    std::vector<point> points = cp.randomPoints(100, {-dist, -dist}, {dist, dist});


    std::vector<point> result = cp.findClosestPoints(points,points);


    std::cout << "Divide and Conquer: \n";
    cp.printClosestPoints(result);


    std::cout << "Naive: \n";
    result = cp.findClosestPointsNaive(points); /// O(n²/2)
    cp.printClosestPoints(result);


}


int main() {

    for (int i = 0; i <10; ++i) {
        ClosestPoint();

    }
    return 0;
}