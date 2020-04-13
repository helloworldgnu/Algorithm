#include <vector>

#ifndef Selection_Sort_H
#define Selection_Sort_H

template <typename T>
void selectionSort(std::vector<T> &inVec)
{
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

#endif