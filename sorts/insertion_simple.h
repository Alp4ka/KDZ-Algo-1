//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Insertion Sort that uses the Simple Insertions.
    @param array std::vector<int> pointer to array we want to sort.
*/
void insertionSortSimple(std::vector<int> *array) {
    int insertion_index;
    int current_item;
    for (int outer_index = 0; outer_index < array->size() - 1; ++outer_index) {
        insertion_index = outer_index + 1;
        current_item = (*array)[insertion_index];
        // Simple search algorithm.
        for (int inner_index = outer_index + 1; inner_index > 0; --inner_index) {
            if (current_item < (*array)[inner_index - 1]) {
                (*array)[inner_index] = (*array)[inner_index - 1];
                insertion_index = inner_index - 1;
            }
        }
        (*array)[insertion_index] = current_item;
    }
}
