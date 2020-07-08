
#include <iostream>
#include <algorithm>
#include "closestPoints.h"

/**
 * Takes a vector of points and returns the pair with the smallest dist inside as a vector
 * @param X Input vector
 * @param Y Copy of the Original Input vector
 * @return the two points with the closest Distance between them
 */
std::vector<point> closestPoints::findClosestPoints(std::vector<point> X,std::vector<point> Y) {

    if (X.size() == 2) {
        return {X[0], X[1]};
    } else
    if (X.size() <= 3) {
        return findClosestPointsNaive(X);
    }


    X = mergeSort(X, 1, X.size());


    int m = floor(X.size() / 2);
    float l_x = (X[m].x_ + X[m + 1].x_) / 2;

    std::vector<point> X_l = std::vector<point>(X.begin(), X.begin() + m);
    std::vector<point> X_r = std::vector<point>(X.begin() + m, X.end());


    std::vector<point> retPoints;
    retPoints = findClosestPoints(X_l,Y);

    point p1 = retPoints[0];
    point p2 = retPoints[1];
    float d1 = p1.getDist(p2);

    retPoints = findClosestPoints(X_r,Y);

    point p3 = retPoints[0];
    point p4 = retPoints[1];
    float d2 = p3.getDist(p4);



    retPoints = combine(Y, l_x, p1, p2, p3, p4);
    point p5 = retPoints[0];
    point p6 = retPoints[1];
    float d3 = p5.getDist(p6);


    if (d1 <= d2 && d1 <= d3) {
        return {p1, p2};
    } else if (d2 <= d1 && d2 <= d3) {
        return {p3, p4};
    }
    return {p5, p6};
}

/**
 * Returns a vector of 2 points with the closest distance out of the input points and the existing points
 * @param Y vector with the original points, to check for close points nearby
 * @param l_x middle
 * @param p1 pair 1
 * @param p2 pair 1
 * @param p3 pair 2
 * @param p4 pair 2
 * @return Two Points with the shortest distance
 */
std::vector<point> closestPoints::combine(std::vector<point> Y, float l_x, point p1, point p2, point p3, point p4) {
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
        p5 = p3;
        p6 = p4;
        d = d2;
    }
    std::vector<point> Y1;


    for (point p: Y) {
        if ((l_x - d) <= p.y_&& p.y_ <= (l_x + d)) {
            Y1.push_back(p);
        }
    }


/**/
    for (int i = 1; i < Y1.size(); ++i) {
        int j = 1;
        while (j <= 7 && (i + j) < Y1.size()) {
            d1 = Y1[i].getDist(Y1[i + j]);
            if (d1 < d) {
                p5 = Y1[i];
                p6 = Y1[i + j];
                d = d1;
            }
            j++;
        }
    }/**/
    return {p5, p6};
}

/**
 * Prints the two Closest Points found by the Algorithm
 * @param points inside a vector with a size of 2
 */
void closestPoints::printClosestPoints(std::vector<point> points) {
    if (points.size() >= 2) {
        std::cout << "Point A: ";
        points[0].print();
        std::cout << "Point B: ";
        points[1].print();
        std::cout << "Distance: " << points[0].getDist(points[1]);
        std::cout << std::endl;
    }
}


/**
 * Sorts a vector according to x values
 * @param A vector with all the points
 * @param p first Element of the area to sort
 * @param r last Element of the area to sort
 * @return sorted vector
 */
std::vector<point> closestPoints::mergeSort(std::vector<point> A, int p, int r) {
    if (p < r) {
        int q = floor((p + r) / 2);
        A = mergeSort(A, p, q);
        A = mergeSort(A, q + 1, r);
        A = merge(A, p, r, q);
    }
    return A;
}

/**
 * Merges a Vector according to the x values of the points
 * @param A vector with all the points
 * @param p starting sorting position
 * @param r last sorting position
 * @param q pivot point
 * @return partially sorted vector
 */
std::vector<point> closestPoints::merge(std::vector<point> A, int p, int r, int q) {



    int n1 = q - p + 2; /// Nr. of Elements before splitting
    int n2 = r - q + 1; /// Nr. of Elements after splitting

    std::vector<point> L(n1);
    std::vector<point> R(n2);

    for (int i = 1; i < n1-1; ++i) {
        L[i] = A[p + i-1];
    }
    for (int j = 1; j < n2-1; ++j) {
        R[j] = A[q + j-1];
    }


    int i = 1;
    int j = 1;

    for (int k = p; k < r-1; ++k) {
        if (L[i].x_ <= R[j].x_) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return A;
}

/**
 * Slow Algorithm o(n²)
 * gets a vector of points and checks every point with every other point
 * @param X vector with points
 * @return vector with the smallest distance between one another
 */
std::vector<point> closestPoints::findClosestPointsNaive(std::vector<point> X) {

    std::vector<point> closest;
    float closedist = INFINITY;

    for (int i = 0; i < X.size(); ++i) {
        for (int j = i+1; j < X.size(); ++j) { /// we can start at i+1 since all the previous points have checked themselves against the j point already
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



/**
 * Generates a vector with a certain Number of random points inside a given rectangle
 * @param numberPoints of points to be generated
 * @param min values of the rectangle
 * @param max values of the rectangle
 * @return a vector with points
 */
std::vector<point> closestPoints::randomPoints(int numberPoints, point min, point max) {

    std::vector<point> points(numberPoints);

    for (int i = 0; i < points.size(); ++i) {

        float x = (rand() % (int) (max.x_ - 1 - min.x_)) + min.x_ + 1;
        float y = (rand() % (int) (max.y_ - 1 - min.y_)) + min.y_ + 1;
        ///The strange addition and subtraction of one has to do with the float values I wanted to add, since I can only get int values with rand()


        x += (((float) (rand() % 1000)) / 500.0f) - 1.0f;
        y += (((float) (rand() % 1000)) / 500.0f) - 1.0f;

        ///looks a bit weird, but I wanted float values

        points[i] = {x, y};
    }

    return points;
}

/**
 * Prints all the x positions of the points inside a vector to check, whether they are sorted or not
 * @param points vector with points
 */
void closestPoints::print(const std::vector<point> points) {
    std::cout<<"X of Points: ";
    for (int i = 0; i < points.size(); ++i) {
        std::cout<<points[i].x_<<", ";
    }
    std::cout<<std::endl;
}



