//
// Created by Jacob on 26.05.2020.
//

#include <iostream>
#include "sort.h"

/**
 * a print function to see the array in the console
 * @param input array
 */
void print(std::vector<int> const &input) {
    for (int i = 0; i < input.size(); ++i) {
        if (i != 0)
            std::cout << ", ";
        std::cout << input[i];
    }
    std::cout << std::endl;
}

/**
 * Quicksort method which gets an input array and a p and r value
 * @param input array
 * @param p array beginning
 * @param r array end
 * @return sorted array
 */
std::vector<int> quicksort(std::vector<int> &input, int p, int r) {
    if (p < r) {
        int q = partition(input,p,r);
        quicksort(input,p,q-1);
        quicksort(input,q+1,r);
    }
    return input;
}

/**
 * sorts the sub array
 * @param input array
 * @param p pivot
 * @param r last item +1
 * @return
 */
int partition(std::vector<int> &input,int p,int r){
    int x = input[r];
    int i = p-1;
    for (int j = p; j < r; ++j) {
        if (input[j] < x){
            i++;
            iter_swap(input.begin() + i, input.begin() + j);
        }
    }
    i++;
    iter_swap(input.begin() + i,input.begin() + r);
    return i;
}

/**
 * It does only sort int arrays
 * This function gets the min and max value and starts the real sorting function
 * with min, max and the array.
 * @param input array
 * @return sorted array
 */
std::vector<int> countingsort(std::vector<int> & input) {

    int max = -INFINITY;
    int min = INFINITY;
    
    for (int i = 0; i < input.size(); ++i) {
        if (max < input[i]){
            max = input[i];
        }
        if (min > input[i]){
            min = input[i];
        }
    }



    return countingsort(input,max,min);
}

/**
 * Added the pseudo code from the pdf file
 * Added a min and max value of the array to be more efficient and to be able to sort negative numbers
 * @param input array
 * @param max value of array
 * @param min value of array
 * @return sorted array
 */
std::vector<int> countingsort(std::vector<int> & input,int max,int min) {
    std::vector<int> B;
    for (int i = 0; i < input.size(); ++i) {
        B.push_back(0);
        input[i] = input[i] - min;
    }

    std::vector<int> C;
    for (int i = 0; i <= (max - min); ++i) {
        C.push_back(0);
    }

    for (int j = 0; j < input.size(); ++j) {
        C[input[j]]++;
    }



    for (int l = 2; l <= (max - min); ++l) {
        C[l] += C[l-1];
    }


    for (int m = input.size()-1; 0 <= m ; --m) {
        B[C[input[m]]] = input[m];
        C[input[m]]--;
    }
    for (int k = 0; k < B.size(); ++k) {
        B[k] = B[k] + min;
    }


    return B;
}