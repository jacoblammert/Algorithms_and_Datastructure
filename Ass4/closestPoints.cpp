
#include <iostream>
#include "closestPoints.h"

std::vector<point> closestPoints::findClosestPoints(std::vector<point> X, std::vector<point> Y) {
    if (X.size() == 2) {
        return {X[0], X[1]};
    } /**/else if (X.size() == 3) {
        return findClosestPointsNaive(X);
    }/**/

    float m = floor(X.size() / 2);
    float l_x = (X[m].x_ + X[m + 1].x_) / 2;

    std::vector<point> X_l = std::vector<point>(X.begin(), X.begin() + m);
    std::vector<point> X_r = std::vector<point>(X.begin() + m, X.end());

    std::vector<point> retPoints;
    if (!X_l.empty()) {
        retPoints = findClosestPoints(X_l, Y);
    }
    point p1 = retPoints[0];
    point p2 = retPoints[1];

    if (!X_r.empty()) {
        retPoints = findClosestPoints(X_r, Y);
    }
    point p3 = retPoints[0];
    point p4 = retPoints[1];

    retPoints = combine(Y, l_x, p1, p2, p3, p4);
    point p5 = retPoints[0];
    point p6 = retPoints[1];

    float d1 = p1.getDist(p2);
    float d2 = p3.getDist(p4);
    float d3 = p5.getDist(p6);

    if (d1 <= d2 && d1 <= d3) {
        return {p1, p2};
    } else if (d2 <= d1 && d2 <= d3) {
        return {p3, p4};
    }
    return {p5, p6};
}

std::vector<point> closestPoints::combine(std::vector<point> &Y, float l_x, point p1, point p2, point p3, point p4) {
    float d;
    float d1 = p1.getDist(p2);
    float d2 = p3.getDist(p4);
    point p5;
    point p6;

    if (d1 < d2) {
        p5 = p1;
        p6 = p2;
        d = d1;
    } else {
        (p5, p6) = (p3, p4);
        d = d2;
    }
    std::vector<point> Y1;
    for (point p: Y) {
        if ((l_x - d) <= (p.x_) <= (l_x + d)) {
            Y1.push_back(p);
        }
    }
    for (int i = 1; i < Y1.size(); ++i) {
        int j = 1;
        while (j <= 7 && i + j <= Y1.size()) {
            float d3 = Y1[i].getDist(Y1[i + j]);
            if (d3 < d) { // TODO CHECK IF d1 or d3
                p5 = Y1[i];
                p6 = Y1[i + j];
                d = d3; // TODO CHECK IF d1 or d3
            }
            j++;
        }
    }
    return {p5, p6};
}

void closestPoints::printClosestPoints(std::vector<point> points) {
    if (points.size() >= 2) {
        std::cout << "Point A: ";
        points[0].print();
        std::cout << "Point B: ";
        points[1].print();
        std::cout << "Distance: " << points[0].getDist(points[1]);
    }
}

std::vector<point> closestPoints::findClosestPointsNaive(std::vector<point> X) {

    std::vector<point> closest;
    float closedist = INFINITY;

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < X.size(); ++j) {
            if (i != j) {
                if (X[i].getDist(X[j]) < closedist) {
                    closest = {X[i], X[j]};
                    closedist = X[i].getDist(X[j]);
                }
            }
        }
    }
    return closest;


}
