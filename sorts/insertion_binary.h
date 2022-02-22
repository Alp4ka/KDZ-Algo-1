//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Insertion Sort that uses the Binary Insertions.
    @param array std::vector<int> pointer to array we want to sort.
*/
void insertionSortBinary(std::vector<int> *array) {
    int current_item;
    int left, right, mid;
    for (int outer_index = 1; outer_index < array->size(); ++outer_index) {
        if ((*array)[outer_index - 1] > (*array)[outer_index]) {
            current_item = (*array)[outer_index];
            left = -1;
            right = outer_index - 1;
            // Binary search algorithm.
            while (right - left > 1) {
                mid = (left + right) / 2;
                if ((*array)[mid] <= current_item) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            for (int inner_index = outer_index - 1; inner_index >= right; --inner_index) {
                (*array)[inner_index + 1] = (*array)[inner_index];
            }
            (*array)[right] = current_item;
        }
    }
}