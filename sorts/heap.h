//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>


class BinaryHeap {
private:
    std::vector<int> array_;

    static int parent(int index) {
        return (index - 1) / 2;
    }

    static int leftChild(int index) {
        return 2 * index + 1;
    }

    static int rightChild(int index) {
        return 2 * index + 2;
    }

public:
    void buildHeap(const std::vector<int> &data) {
        array_ = data;
        for (int i = array_.size() / 2; i >= 0; --i) {
            siftDown(i, array_.size());
        }
    };

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

    void heapSort(const std::vector<int> &data) {
        buildHeap(data);
        int heap_size = array_.size();
        for (int i = 0; i < array_.size(); ++i) {
            std::swap(array_[0], array_[array_.size() - 1 - i]);
            siftDown(0, --heap_size);
        }
    }

    friend void heapSort(std::vector<int> *array);
};

void heapSort(std::vector<int> *array) {
    BinaryHeap heap;
    heap.heapSort(*array);
    *array = std::vector<int>(heap.array_.begin(), heap.array_.end());
}