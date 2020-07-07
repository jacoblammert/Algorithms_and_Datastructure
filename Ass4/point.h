

#ifndef ALGORITHMS_AND_DATASTRUCTURE_POINT_H
#define ALGORITHMS_AND_DATASTRUCTURE_POINT_H


struct point {
public:
    float x_ = INFINITY;
    float y_ = INFINITY;
    float getDist(point p);
    void print();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_POINT_H
