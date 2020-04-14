#include <iostream>

#include "../util/util.h"
#include "../util/random_generator.h"
#include "../util/timer.h"

#include "./insertion/InsertionSort.h"
#include "./shell/ShellSort.h"
#include "./merge/MergeSort.h"
#include "./quick/QuickSort.h"

int main(int argc, char *argv[]) 
{
    std::vector<int> vec1 = generateRandomIntVector(0, 1000000, 1000000);
    std::vector<int> vec2 = makeVectorCopy(vec1);
    std::vector<int> vec3 = makeVectorCopy(vec1);
    std::vector<int> vec4 = makeVectorCopy(vec1);
    std::vector<int> vec5 = makeVectorCopy(vec1);

    // shellSort(vec2);

    mergeSort(vec3);

    mergeSortBU(vec4);

    quickSort2(vec5);

    return EXIT_SUCCESS;
}