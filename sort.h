//
// Created by Jacob on 26.05.2020.
//

#ifndef ALGORITHMS_AND_DATASTRUCTURE_SORT_H
#define ALGORITHMS_AND_DATASTRUCTURE_SORT_H


#include <vector>

class sort {




};

void print(std::vector<int> const& input);

std::vector<int> quicksort(std::vector<int> &input,int p,int r);
int partition(std::vector<int> &input,int p,int r);

std::vector<int> countingsort(std::vector<int> &input);

std::vector<int> countingsort(std::vector<int> &input,int k);

#endif //ALGORITHMS_AND_DATASTRUCTURE_SORT_H
