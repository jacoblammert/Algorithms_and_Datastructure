#include <iostream>
#include <vector>
#include "sort.h"

int main() {

    std::vector<int> list{9,8,7,4,66,4,42,58,32,1,4,5,7,6,454,241,24,57,91,23,45,11,2,0,1,3,2,7,5,6,4,7,8,9,1};
    //std::vector<int> list{2,8,7,1,3,5,6,4};


    print(list);
    print(quicksort(list,0,list.size()-1));
    list = {9,8,7,4,66,4,42,58,32,1,4,5,7,6,454,241,24,57,91,23,45,11,2,0,1,3,2,7,5,6,4,7,8,9,1};
    print(list);
    print(countingsort(list));

    return 0;
}
