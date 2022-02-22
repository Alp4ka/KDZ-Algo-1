//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Merges the slice limited with "from", "to" parameters.
    @param array std::vector<int> pointer to array we want to sort.
    @param from indicates the start point for current iteration.
    @param to indicates the end point for current iteration.
*/
void merge(std::vector<int> *array, int from, int to) {
    int64_t *temp_array = new int64_t[1 + to - from];
    int middle = (from + to) / 2;
    int left_iter = from;
    int right_iter = middle + 1;
    // Merging.
    for (int i = from; i <= to; ++i) {
        if ((left_iter <= middle) &&
            (right_iter > to || (*array)[left_iter] < (*array)[right_iter])) {
            temp_array[i - from] = (*array)[left_iter++];
        } else {
            temp_array[i - from] = (*array)[right_iter++];
        }
    }
    for (int i = from; i <= to; ++i) {
        (*array)[i] = temp_array[i - from];
    }
    delete[] temp_array;
}

/**
    Recursive Merge Sort that uses the recursive algorithm.
    @param array std::vector<int> pointer to array we want to sort.
    @param from indicates the start point for current iteration.
    @param to indicates the end point for current iteration.
*/
void mergeSortRecursive(std::vector<int> *array, int from, int to) {
    if (from < to) {
        mergeSortRecursive(array, from, (from + to) / 2);
        mergeSortRecursive(array, (from + to) / 2 + 1, to);
        merge(array, from, to);
    }
}

/**
    Wrapper for Merge Sort that uses the recursive algorithm.
    @param array std::vector<int> pointer to array we want to sort.
*/
void mergeSort(std::vector<int> *array) {
    mergeSortRecursive(array, 0, array->size() - 1);
}