#include <vector>

#ifndef Insertion_Sort_H
#define Insertion_Sort_H

#include "../../util/timer.h"

template <typename T>
void __insertionSort(std::vector<T> &inVec, int low, int heigh)
{
    if (low >= heigh || inVec.size() <= heigh) {
        return;
    }

    T value;
    int j;
    for (int i = low + 1; i <= heigh; ++i) {
        value = inVec[i];
        j = i;
        for (; j > low; --j) {
            if (value < inVec[j - 1]) {
                inVec[j] = inVec[j - 1];
            } else {
                break;
            }
        }
        inVec[j] = value;
    }
}

template <typename T>
void insertionSort(std::vector<T> &inVec, int low, int heigh)
{
    Timer timer;

    __insertionSort(inVec, low, heigh);

    timer.stop();
    timer.printTimeConsumed("insertion sort:");
}

#endif