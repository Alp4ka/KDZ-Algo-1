//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void bubbleSortIverson1(std::vector<int> *array) {
    for (int i = 0; i <= array->size() - 2; ++i) {
        for (int j = 0; j <= array->size() - 2 - i; ++j) {
            if ((*array)[j] > (*array)[j + 1]) {
                std::swap((*array)[j], (*array)[j + 1]);
            }
        }
    }
}