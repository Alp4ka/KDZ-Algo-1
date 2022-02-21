//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void merge(std::vector<int> *array, int from, int to) {
    int64_t *temp_array = new int64_t[1 + to - from];
    int middle = (from + to) / 2;
    int left_iter = from;
    int right_iter = middle + 1;
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

void mergeSortRecursive(std::vector<int> *array, int from, int to) {
    if (from < to) {
        mergeSortRecursive(array, from, (from + to) / 2);
        mergeSortRecursive(array, (from + to) / 2 + 1, to);
        merge(array, from, to);
    }
}

void mergeSort(std::vector<int> *array) {
    mergeSortRecursive(array, 0, array->size() - 1);
}