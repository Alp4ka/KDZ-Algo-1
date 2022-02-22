//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Binary Heap class.
*/
class BinaryHeap {
private:
    /**
        Array we would structure as heap.
    */
    std::vector<int> array_;

    /**
        Get parent of specified index.
        @param index - index we want to know a parent index of.
        @return Parent index of index specified as a parameter of a method.
    */
    static int parent(int index) {
        return (index - 1) / 2;
    }

    /**
        Get index of left child of specified index.
        @param index - index we want to know a left child index of.
        @return Left child index of index specified as a parameter of a method.
    */
    static int leftChild(int index) {
        return 2 * index + 1;
    }

    /**
        Get index of right child of specified index.
        @param index - index we want to know a right child index of.
        @return Right child index of index specified as a parameter of a method.
    */
    static int rightChild(int index) {
        return 2 * index + 2;
    }

public:
    /**
        Build heap out of specified array.
        @param data - array we want to organize as heap.
    */
    void build(const std::vector<int> &data) {
        array_ = data;
        for (int i = array_.size() / 2; i >= 0; --i) {
            siftDown(i, array_.size());
        }
    };

    /**
        Sift down the heap starting from specified index.
        @param index - index we want to start from to make a sift down algorithm.
        @param heap_size - current size of a heap array.
    */
    void siftDown(int index, int heap_size) {
        while (leftChild(index) < heap_size) {
            int left_child = leftChild(index);
            int right_child = rightChild(index);
            int bound = left_child;
            if (right_child < heap_size && array_.at(right_child) > array_.at(left_child)) {
                bound = right_child;
            }
            if (array_[index] >= array_[bound]) {
                break;
            }
            std::swap(array_[index], array_[bound]);
            index = bound;
        }
    }

    /**
        Heap sort algorithm.
        @param data - vector we want to sort.
    */
    void heapSort(const std::vector<int> &data) {
        build(data);
        int heap_size = array_.size();
        for (int i = 0; i < array_.size(); ++i) {
            std::swap(array_[0], array_[array_.size() - 1 - i]);
            siftDown(0, --heap_size);
        }
    }

    friend void heapSort(std::vector<int> *array);
};

/**
    Wrapper for heap sort using Heap structure.
    @param array std::vector<int> pointer to array we want to sort.
*/
void heapSort(std::vector<int> *array) {
    BinaryHeap heap;
    heap.heapSort(*array);
    *array = std::vector<int>(heap.array_.begin(), heap.array_.end());
}