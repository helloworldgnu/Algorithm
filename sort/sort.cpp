#include <iostream>

#include "../util/util.h"
#include "../util/random_generator.h"
#include "../util/timer.h"

#include "./insertion/InsertionSort.h"
#include "./shell/ShellSort.h"
#include "./merge/MergeSort.h"
#include "./quick/QuickSort.h"
#include "./heap/HeapSort.h"

int main(int argc, char *argv[]) 
{
    std::vector<int> vec1 = generateRandomIntVector(0, 100000, 100000);
    // std::vector<int> vec1 = generateBasicOrderIntVector(100000, 10);
    // std::vector<int> vec2 = makeVectorCopy(vec1);
    std::vector<int> mergeVec = makeVectorCopy(vec1);
    std::vector<int> mergeBUVector = makeVectorCopy(vec1);
    std::vector<int> quick2Vec = makeVectorCopy(vec1);
    std::vector<int> quick3Vec = makeVectorCopy(vec1);
    std::vector<int> heapVec = makeVectorCopy(vec1);

    // shellSort(vec2);

    mergeSort(mergeVec);

    mergeSortBU(mergeBUVector);

    quickSort2(quick2Vec);

    quickSort3(quick3Vec);

    heapSort(heapVec);

    return EXIT_SUCCESS;
}