//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

int64_t getMax(std::vector<int> *array) {
    int temp_max = (*array)[0];
    for (int i = 0; i < array->size(); ++i) {
        if ((*array)[i] > temp_max) {
            temp_max = (*array)[i];
        }
    }
    return temp_max;
}

void radixSort(std::vector<int> *array) {
    int *temp_array = new int[array->size()];
    int del = 1;
    int64_t max = getMax(array);
    while (max > del) {
        std::vector<int> counter(256);
        for (int i = 0; i < array->size(); ++i) {
            counter[(*array)[i] / del % 256]++;
        }
        for (int i = 1; i < 256; ++i) {
            counter[i] += counter[i - 1];
        }
        for (int64_t i = array->size() - 1; i >= 0; --i) {
            temp_array[counter[(*array)[i] / del % 256] - 1] = (*array)[i];
            counter[(*array)[i] / del % 256]--;
        }
        for (int64_t i = 0; i < array->size(); ++i) {
            (*array)[i] = temp_array[i];
        }
        del *= 256;
    }
    delete[] temp_array;
}
