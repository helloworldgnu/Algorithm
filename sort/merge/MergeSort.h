#include <vector>

#ifndef Merge_Sort_H
#define Merge_Sort_H

#include "../insertion/InsertionSort.h"

template <typename T>
void __merge(std::vector<T> &inVec, int low, int mid, int heigh)
{
    T aux[heigh - low + 1];
    for (int i = low; i <= heigh; i++) 
      aux[i - low] = inVec[i];

    int i = low, j = mid + 1;

    for (int k = low; k <= heigh; k++) {
      if (i > mid) {
          inVec[k] = aux[j - low]; ++j;
      } else if (j > heigh ) {
          inVec[k] = aux[i - low]; ++i;
      } else if (aux[j - low] < aux[i - low]) {
          inVec[k] = aux[j- low]; ++j;
      } else {
          inVec[k] = aux[i - low]; ++i;
      }
    }
}

template <typename T>
void __merge_sort(std::vector<T> &inVec, int low, int heigh)
{
    if (low >= heigh) {
        return;
    }

    int count = heigh - low;
    if (count <= 15) {
        insertionSort(inVec, low, heigh);
        return;
    }

    int mid = low + count / 2;
    __merge_sort(inVec, low, mid);
    __merge_sort(inVec, mid + 1, heigh);

    if (inVec[mid] <= inVec[mid + 1]) {
        return;
    }
    
    __merge(inVec, low, mid, heigh);
}

template <typename T>
void mergeSort(std::vector<T> &inVec)
{
    __merge_sort(inVec, 0, inVec.size() - 1);
}

#endif