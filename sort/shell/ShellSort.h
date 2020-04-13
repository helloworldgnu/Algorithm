#include <vector>

#ifndef Shell_Sort_H
#define Shell_Sort_H

template <typename T>
void shellSort(std::vector<T> &inVec)
{
    int length = inVec.size();
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while(h >= 1) {
        for (int i = h; i < length; ++i) {
            for (int j = i; j >= h; j -= h) {
                if (inVec[j] < inVec[j - h]) {
                    std::swap(inVec[j], inVec[j - h]);
                }
            }
        }

        h = h / 3;
    }
}

#endif