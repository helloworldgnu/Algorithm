#include <iostream>
#include <vector>

#ifndef Sort_Util_H
#define Sort_Util_H

template <typename T>
void printVec(std::vector<T> &vec)
{
    std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
}

#endif