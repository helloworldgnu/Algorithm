#include <vector>

#ifndef Merge_Sort_H
#define Merge_Sort_H

#include "../insertion/InsertionSort.h"

static std::vector<int> aux;

template <typename T>
void __merge(std::vector<T> &inVec, int low, int mid, int heigh)
{
   for (int k = low; k <= heigh; k++) 
      aux[k] = inVec[k];

    int i = low, j = mid + 1;

   for (int k = low; k <= heigh; k++) {
      if (i > mid) {
          inVec[k] = aux[j++];
      } else if (j > heigh ) {
          inVec[k] = aux[i++];
      } else if (aux[j] < aux[i]) {
          inVec[k] = aux[j++];
      } else {
          inVec[k] = aux[i++];
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

    if (inVec[mid] < inVec[mid + 1]) {
        return;
    }
    
    __merge(inVec, low, mid, heigh);
}

template <typename T>
void mergeSort(std::vector<T> &inVec)
{
    aux.resize(inVec.size());
    __merge_sort(inVec, 0, inVec.size() - 1);
}

#endif