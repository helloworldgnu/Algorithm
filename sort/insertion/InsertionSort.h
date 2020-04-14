#include <vector>

#ifndef Insertion_Sort_H
#define Insertion_Sort_H

template <typename T>
void insertionSort(std::vector<T> &inVec, int low, int heigh)
{
    int length = inVec.size();
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

#endif