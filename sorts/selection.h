//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void selectionSort(std::vector<int> *array) {
    int local_minimum_index;
    for (int outer_index = 0; outer_index < array->size() - 1; ++outer_index) {
        local_minimum_index = outer_index;
        for (int inner_index = outer_index + 1; inner_index < array->size(); ++inner_index) {
            if ((*array)[inner_index] < (*array)[local_minimum_index]) {
                local_minimum_index = inner_index;
            }
        }
        if (local_minimum_index != outer_index) {
            std::swap((*array)[outer_index], (*array)[local_minimum_index]);
        }
    }
}
