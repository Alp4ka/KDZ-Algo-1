//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <vector>
#include <map>
#include <ctime>
#include <algorithm>

/**
    Generates vector with random ints.
    @param amount - size of output array.
    @param lower_bound - lower bound for random integer.
    @param upper_bound - upper bound for random integer.
    @param include_upper_bound - specifies whether the upper_bound should be included as
    a possible random integer value.
    @return array(vector) of specified size with random ints.
*/
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

/**
    Generates half sorted vector with random integers.
    @param amount - size of output array.
    @param lower_bound - lower bound for random integer.
    @param delta - step we go through integers starting with lower_bound.
    @param probability - natural value specifies the probability of swap action.
    @return array(vector) of specified amount with random ints.
*/
static std::vector<int> generateHalfSortVector(int amount, int lower_bound, int delta, int probability) {
    srand(time(nullptr));
    int chosen_probability;
    std::vector<int> array;
    for (int i = lower_bound; i < amount * delta; i += delta) {
        array.emplace_back(i);
    }
    for (int i = lower_bound; i < amount * delta; ++i) {
        // With specified probability swap random array element with i'th element.
        chosen_probability = rand() % 101;
        if (chosen_probability <= probability) {
            std::swap(array[i], array[rand() % amount]);
        }
    }
    return array;
}

/**
    Generates sorted by descending vector with random integers.
    @param size - size of output array.
    @return array(vector) of specified amount with random ints.
*/
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