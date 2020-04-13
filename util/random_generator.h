#include <random>
#include <vector>
#include <algorithm>

#ifndef Random_Generator_H
#define Random_Generator_H

std::vector<int> generateRandomIntVector(int start, int end, int size)
{
    std::default_random_engine dre(time(NULL));
    std::uniform_int_distribution uid(start, end);

    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.emplace_back(uid(dre));
    }
    return vec;
}

std::vector<int> generateBasicOrderIntVector(int size, int adjustments)
{
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
        vec.emplace_back(i);
    }

    std::default_random_engine dre;
    std::uniform_int_distribution uid(0, size);
    for (int i = 0; i < adjustments; ++i) {
        std::swap(vec[uid(dre)], vec[uid(dre)]);
    }

    return vec;
}

template <typename T>
std::vector<T> makeVectorCopy(std::vector<T> &inVec)
{
    std::vector<T> outVec(inVec.size());
    std::copy(inVec.begin(), inVec.end(), outVec.begin());
    return outVec;
}

#endif