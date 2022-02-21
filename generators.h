//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <vector>
#include <map>
#include <ctime>
#include <algorithm>

static std::vector<int> generateRandomVector(size_t amount,
                                             int64_t lower_bound,
                                             int64_t upper_bound,
                                             bool include_upper_bound = false) {
    srand(time(nullptr));
    std::vector<int> result;
    result.resize(amount);
    for (int i = 0; i < amount; ++i) {
        result[i] =
                rand() % (upper_bound - lower_bound) + lower_bound + (include_upper_bound ? 1 : 0);
    }
    return result;
}

static std::vector<int> generateHalfSortVector(int size, int start_value, int step, int prob_coef) {
    srand(time(nullptr));
    int prob, rand_index;
    double fraction;
    std::vector<int> array;
    for (int i = start_value; i < size * step; i += step) {
        array.emplace_back(i);
    }
    for (int i = start_value; i < size * step; ++i) {
        fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        prob = static_cast<int>(rand() * fraction * 100 + 1);
        if (prob <= prob_coef) {
            fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
            rand_index = static_cast<int>(rand() * fraction * ((size - 1) + 1));
            std::swap(array[i], array[rand_index]);
        }
    }
    return array;
}


static std::vector<int> generateReversedVector(int size) {
    srand(time(nullptr));
    std::vector<int> array;
    array.resize(size);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % size + 1;
    }
    std::sort(array.begin(), array.end());
    std::reverse(array.begin(), array.end());
    return array;
}