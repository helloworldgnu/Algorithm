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
    if (heigh - low <= 15) {
        __insertionSort(inVec, low, heigh);
        return;
    }

    int p = partition(inVec, low, heigh);
    __quickSort2(inVec, low, p - 1);
    __quickSort2(inVec, p + 1, heigh);
}

template <typename T>
void __quickSort2(std::vector<T> &inVec)
{
    if (inVec.size() <= 1) {
        return;
    }

    __quickSort2(inVec, 0, inVec.size() - 1);
}

template <typename T>
void quickSort2(std::vector<T> &inVec)
{
    Timer timer;

    __quickSort2(inVec);

    timer.stop();
    timer.printTimeConsumed("quick sort2:");
}

template <typename T>
void __quickSort3(std::vector<T> &inVec, int low, int heigh)
{
    if (low >= heigh) {
        return;
    }

    if (heigh - low <= 15) {
        __insertionSort(inVec, low, heigh);
        return;
    }

    std::default_random_engine dre(time(NULL));
    std::uniform_int_distribution uid(low, heigh);
    
    int randIndex = uid(dre);

    T value = inVec[randIndex];
    std::swap(inVec[low], inVec[randIndex]);

    int i = low + 1;
    int lt = low;
    int gt = heigh;
    while (i <= gt) {
        if (inVec[i] < value) {
            std::swap(inVec[i++], inVec[++lt]);
        } else if (inVec[i] > value) {
            std::swap(inVec[i], inVec[gt--]);
        } else {
            ++i;
        }
    }

    std::swap(inVec[low], inVec[lt]);

    __quickSort3(inVec, low, lt - 1);
    __quickSort3(inVec, gt + 1, heigh);
}

template <typename T>
void __quickSort3(std::vector<T> &inVec)
{
    if (inVec.size() <= 1) {
        return;
    }

    __quickSort3(inVec, 0, inVec.size() - 1);
}

template <typename T>
void quickSort3(std::vector<T> &inVec)
{
    Timer timer;

    __quickSort3(inVec);

    timer.stop();
    timer.printTimeConsumed("quick sort3:");
}

#endif