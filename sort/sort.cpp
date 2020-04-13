#include <iostream>

#include "../util/util.h"
#include "../util/random_generator.h"
#include "../util/timer.h"

#include "./insertion/InsertionSort.h"
#include "./shell/ShellSort.h"

int main(int argc, char *argv[]) 
{
    std::vector<int> vec1 = generateRandomIntVector(0, 10, 100000);
    std::vector<int> vec2 = makeVectorCopy(vec1);

    Timer timer;

    // printVec(vec1);

    // 插入排序
    timer.start();

    insertionSort(vec1);
    
    timer.stop();
    timer.printTimeConsumed();

    // printVec(vec1);

    // printVec(vec2);

    // 希尔排序
    timer.start();

    shellSort(vec2);
    
    timer.stop();
    timer.printTimeConsumed();

    // printVec(vec2);

    return EXIT_SUCCESS;
}