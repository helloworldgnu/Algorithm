#include <vector>

#ifndef Selection_Sort_H
#define Selection_Sort_H

#include "../../util/timer.h"

template <typename T>
void __selectionSort(std::vector<T> &inVec)
{
    if (inVec.size() <= 1) {
        return;
    }

    int length = inVec.size();
    int minIndex;
    for (int i = 0; i < length; ++i) {
        minIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (inVec[j] < inVec[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(inVec[i], inVec[minIndex]);
    }
}

template <typename T>
void selectionSort(std::vector<T> &inVec)
{
    Timer timer;

    __selectionSort(inVec);

    timer.stop();
    timer.printTimeConsumed("selection sort:");
}

#endif