//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void quickSortRecursiveLomuto(std::vector<int> *array, int from, int to) {
    if ((from < to) && (from > -1)) {
        int pivot_value = (*array)[to];
        int left = from - 1;
        for (int right = from; right < to; ++right) {
            if ((*array)[right] <= pivot_value) {
                std::swap((*array)[++left], (*array)[right]);
            }
        }
        std::swap((*array)[left + 1], (*array)[to]);
        int pivot_index = left + 1;
        quickSortRecursiveLomuto(array, from, pivot_index - 1);
        quickSortRecursiveLomuto(array, pivot_index + 1, to);
    }
}

void quickSortLomuto(std::vector<int> *array) {
    quickSortRecursiveLomuto(array, 0, array->size() - 1);
}
