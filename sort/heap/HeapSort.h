#include <vector>
#include <exception>
#include <cassert>

#ifndef Heap_Sort_H
#define Heap_Sort_H

#include "../../util/timer.h"

template<typename T>
class MaxHeap
{
private:
    std::vector<T> data;
public:
    MaxHeap() {
        data.push_back(0);
    }

    /**
     * up
     */
    void swim(int k)
    {
        int ancestor;
        while (k > 1)
        {
            ancestor = k / 2;
            if (data[k] > data[ancestor]) {
                std::swap(data[k], data[ancestor]);
                k = ancestor;
            } else {
                break;
            }
        }
    }

    /**
     * down
     */
    void sink(int k)
    {
        int size = data.size();
        int succesor = 2 * k;
        while (succesor < size) 
        {
            if (succesor + 1 < size) {
                if (data[succesor] < data[succesor + 1]) {
                    succesor = succesor + 1;
                }
            }

            if (data[k] < data[succesor]) {
                std::swap(data[k], data[succesor]);
                k = succesor;
                succesor = 2 * k;
            } else {
                break;
            }
        }
    }

    T delMax()
    {
        assert(size() > 1);

        T maxElement;
        if (size() > 1) {
            maxElement = data.back();
            data[1] = maxElement;
            data.pop_back();

            sink(1);
        } else {
            maxElement = data.back();
            data.pop_back();
        }

        return maxElement;
    }

    void insert(T item)
    {
        data.push_back(item);
        swim(data.size() - 1);
    }

    bool isEmpty()
    {
        return data.size() <= 1;
    }

    int size()
    {
        int size = data.size();
        if (size > 1) return size - 1;
        return 0;
    }
};

template <typename T>
void __heapSort(std::vector<T> &inVec)
{
    MaxHeap<T> maxHeap;
    for (auto item : inVec) {
        maxHeap.insert(item);
    }

    inVec.clear();
    inVec.resize(maxHeap.size());
    while (!maxHeap.isEmpty())
    {
        std::cout << maxHeap.delMax() << " " << std::endl;
        // inVec.insert(inVec.begin(), maxHeap.delMax());
    }
}

template <typename T>
void heapSort(std::vector<T> &inVec)
{
    Timer timer;

    __heapSort(inVec);

    timer.stop();
    timer.printTimeConsumed("heap sort:");
}

#endif