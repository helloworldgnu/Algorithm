#include <vector>
#include <random>

#ifndef Quick_Sort_H
#define Quick_Sort_H

#include "../insertion/InsertionSort.h"

template <typename T>
int partition(std::vector<T> &inVec, int low, int heigh)
{
    std::default_random_engine dre(time(NULL));
    std::uniform_int_distribution uid(low, heigh);

    int randIndex = uid(dre);
    T value = inVec[randIndex];
    std::swap(inVec[low], inVec[randIndex]);

    int i = low + 1;
    int j = heigh;
    while (true) {
        while (inVec[i] < value && i <= heigh) ++i;
        while (inVec[j] > value && j >= low + 1) --j;

        if (i > j) {
            break;
        }

        std::swap(inVec[i], inVec[j]);
        ++i;
        --j;
    }

    std::swap(inVec[low], inVec[j]);

    return j;
}

template <typename T>
void __quickSort2(std::vector<T> &inVec, int low, int heigh)
{
    if (low >= heigh) {
        return;
    }

    if (heigh - low <= 15) {
        insertionSort(inVec, low, heigh);
        return;
    }

    int p = partition(inVec, low, heigh);
    __quickSort2(inVec, low, p - 1);
    __quickSort2(inVec, p + 1, heigh);
}

template <typename T>
void quickSort2(std::vector<T> &inVec)
{
    if (inVec.size() <= 1) {
        return;
    }

    __quickSort2(inVec, 0, inVec.size() - 1);
}

#endif