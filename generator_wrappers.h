//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <vector>
#include <map>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include "generators.h"

// Создаем указатель на генераторы.
typedef std::vector<int> (*GeneratorWrapper)(int size);

// Типы генераторов.
enum ArrayType {
    RANDOM_VALUES_0_5 = 0,
    RANDOM_VALUES_0_4000 = 1,
    HALF_SORTED = 2,
    REVERSED_SORTED = 3,
};

/**
    Generates half sorted array.
    @param size - size of output array.
    @return array(vector) of specified size
*/
static std::vector<int> generateHalfSortedVectorWrapper(int size) {
    return generateHalfSortVector(size, 0, 1, 10);
}

/**
    Generates vector with random ints limited between 0 and 5.
    @param size - size of output array.
    @return array(vector) of specified size
*/
static std::vector<int> generateRandomVector0_5Wrapper(int size) {
    return generateRandomVector(size, 0, 5, true);
}

/**
    Generates vector with random ints limited between 0 and 4000.
    @param size - size of output array.
    @return array(vector) of specified size
*/
static std::vector<int> generateRandomVector0_4000Wrapper(int size) {
    return generateRandomVector(size, 0, 4000, true);
}

/**
    Generates vector with random ints sorted by descending.
    @param size - size of output array.
    @return array(vector) of specified size
*/
static std::vector<int> generateReversedVectorWrapper(int size) {
    return generateReversedVector(size);
}

// Mapping that links array type to its generator.
static std::map<ArrayType, GeneratorWrapper> generator_mapping = {
        {RANDOM_VALUES_0_5,    generateRandomVector0_5Wrapper},
        {RANDOM_VALUES_0_4000, generateRandomVector0_4000Wrapper},
        {HALF_SORTED,          generateHalfSortedVectorWrapper},
        {REVERSED_SORTED,      generateReversedVectorWrapper}
};