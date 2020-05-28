#include <iostream>
#include <vector>
#include "sort.h"

int main() {

    std::vector<int> list{9,8,7,4,66,4,42,58,32,1,4,5,7,6,454,241,24,57,91,23,45,11,2,0,1,3,2,7,5,6,4,7,8,9,1};
    //std::vector<int> list{2,8,7,1,3,5,6,4};

    std::cout<<std::endl << "quicksort: " << std::endl;

    print(list);
    print(quicksort(list,0,list.size()-1));


    std::cout<<std::endl << "counting sort: " << std::endl;
    list = {9,8,7,4,66,4,42,58,32,1,4,5,7,6,454,241,24,57,91,23,45,11,2,0,1,3,2,7,5,6,4,7,8,9,1};
    print(list);
    print(countingsort(list));
    std::cout<<std::endl << "counting sort: " << std::endl;
    list = {11,10,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11};
    print(list);
    print(countingsort(list));

    return 0;
}
