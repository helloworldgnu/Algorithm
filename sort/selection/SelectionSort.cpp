#include <iostream>

#include "../../util/util.h"
#include "../../util/random_generator.h"
#include "../../util/timer.h"

#include "SelectionSort.h"

int main(int argc, char *argv[]) 
{
    std::vector<int> vec = generateRandomIntVector(0, 10, 10000);
    // std::vector<int> vec = gernerateBasicOrderIntVector(10000, 100);

    Timer timer;

    timer.start();

    selectionSort(vec);
    
    timer.stop();
    timer.printTimeConsumed("selection sort:");

    return EXIT_SUCCESS;
}