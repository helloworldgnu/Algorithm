#include <vector>

#ifndef Insertion_Sort_H
#define Insertion_Sort_H

template <typename T>
void insertionSort(std::vector<T> &inVec)
{
    int length = inVec.size();
    T value;
    int j;
    for (int i = 1; i < length; ++i) {
        value = inVec[i];
        j = i;
        for (; j > 0; --j) {
            if (value < inVec[j - 1]) {
                std::swap(inVec[j - 1], inVec[j]);
            } else {
                break;
            }
        }
        inVec[j] = value;
    }
}

#endif