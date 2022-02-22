//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Quick Sort that uses the Hoare partition.
    @param array std::vector<int> pointer to array we want to sort.
    @param from indicates the start point for current iteration.
    @param to indicates the end point for current iteration.
*/
void quickSortHoareRecursive(std::vector<int> *array, int from, int to) {
    int i = from;
    int j = to;
    int mid_elem = (*array)[(from + to) / 2];
    bool statement = true;
    // Partition.
    while (statement) {
        while ((*array)[i] < mid_elem) {
            ++i;
        }
        while ((*array)[j] > mid_elem) {
            --j;
        }
        if (i <= j) {
            if ((*array)[i] > (*array)[j]) {
                std::swap((*array)[i], (*array)[j]);
            }
            ++i;
            --j;
        }
        if (i > j) {
            statement = false;
        }
    }
    if (i < to) {
        quickSortHoareRecursive(array, i, to);
    }
    if (from < j) {
        quickSortHoareRecursive(array, from, j);
    }
}

/**
    Wrapper for Quick Sort that uses the Hoare partition.
    @param array std::vector<int> pointer to array we want to sort.
*/
void quickSortHoare(std::vector<int> *array) {
    quickSortHoareRecursive(array, 0, array->size() - 1);
}