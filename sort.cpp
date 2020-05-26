//
// Created by Jacob on 26.05.2020.
//

#include <iostream>
#include "sort.h"

void print(std::vector<int> const &input) {
    for (int i = 0; i < input.size(); ++i) {
        if (i != 0)
            std::cout << ", ";
        std::cout << input[i];
    }
    std::cout << std::endl;
}

std::vector<int> quicksort(std::vector<int> &input, int p, int r) {
    if (p < r) {
        int q = partition(input,p,r);
        quicksort(input,p,q-1);
        quicksort(input,q+1,r);
    }
    return input;
}

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
std::vector<int> countingsort(std::vector<int> & input) {

    int max = -INFINITY;
    
    for (int i = 0; i < input.size(); ++i) {
        if (max < input[i]){
            max = input[i];
        }
    }

    return countingsort(input,max);
}

std::vector<int> countingsort(std::vector<int> & input,int k) {
    std::vector<int> B;
    for (int i = 0; i < input.size(); ++i) {
        B.push_back(0);
    }
    std::vector<int> C;
    for (int i = 0; i <= k; ++i) {
        C.push_back(0);
    }

    for (int j = 0; j < input.size(); ++j) {
        C[input[j]]++;
    }

    for (int l = 2; l <= k; ++l) {
        C[l] += C[l-1];
    }

    for (int m = input.size()-1; 0 <= m ; --m) {
        B[C[input[m]]] = input[m];
        C[input[m]]--;
    }
    
    return B;
}