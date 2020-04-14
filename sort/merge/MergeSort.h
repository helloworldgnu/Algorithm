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

template <typename T>
void mergeSortBU(std::vector<T> &inVec)
{
    int length = inVec.size();

    for( int i = 0 ; i < length ; i += 16 )
        insertionSort(inVec, i, std::min(i + 15, length - 1));
    
    int subLength;
    for (int sz = 16; sz < length; sz += sz) {
        subLength = length - sz;
        for (int i = 0; i < subLength; i += sz + sz) {
            __merge(inVec, i, i + sz - 1, std::min(i + sz + sz - 1, length - 1));
        }
    }
}

#endif