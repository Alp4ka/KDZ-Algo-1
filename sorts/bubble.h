//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void bubbleSort(std::vector<int> *array) {
    for (int i = 0; i < array->size() - 1; ++i) {
        for (int j = i + 1; j < array->size(); ++j) {
            if ((*array)[i] > (*array)[j]) {
                std::swap((*array)[i], (*array)[j]);
            }
        }
    }
}