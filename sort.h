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

/**
 * Impoirtant function which calls the other function with min and max
 * @param input unsorted array
 * @return sorted array
 */
std::vector<int> countingsort(std::vector<int> &input);

/**
 *
 * @param input unsorted array
 * @param max value of array
 * @param min value of array
 * @return sorted array
 */
std::vector<int> countingsort(std::vector<int> &input,int max,int min);

#endif //ALGORITHMS_AND_DATASTRUCTURE_SORT_H
