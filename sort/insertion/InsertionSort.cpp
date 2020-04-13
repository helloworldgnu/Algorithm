#include <iostream>

#include "../../util/util.h"
#include "../../util/random_generator.h"
#include "../../util/timer.h"

#include "InsertionSort.h"

int main(int argc, char *argv[]) 
{
    std::vector<int> vec = generateRandomIntVector(0, 10, 10000);
    // std::vector<int> vec = gernerateBasicOrderIntVector(10000, 100);

    Timer timer;

    timer.start();

    insertionSort(vec);

    timer.stop();
    timer.printTimeConsumed();

    return EXIT_SUCCESS;
}