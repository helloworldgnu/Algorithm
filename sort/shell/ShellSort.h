#include <vector>

#ifndef Shell_Sort_H
#define Shell_Sort_H

#include "../../util/timer.h"

template <typename T>
void __shell_sort(std::vector<T> &inVec)
{
    if (inVec.size() <= 1) {
        return;
    }

    int length = inVec.size();
    int h =  1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }

    T value;
    int j;
    while(h >= 1) {
        for (int i = h; i < length; ++i) {
            value = inVec[i];
            j = i;
            for (; j >= h; j -= h) {
                if (value < inVec[j - h]) {
                    inVec[j] = inVec[j - h];
                } else {
                    break;
                }
            }

            if (j != i) {
                inVec[j] = value;
            }
        }

        h = h / 3;
    }
}

template <typename T>
void shellSort(std::vector<T> &inVec)
{
    Timer timer;

    __shell_sort(inVec);

    timer.stop();
    timer.printTimeConsumed("shell sort:");
}

#endif