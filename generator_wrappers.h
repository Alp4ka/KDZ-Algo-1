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

static std::vector<int> generateHalfSortedVectorWrapper(int size) {
    return generateHalfSortVector(size, 0, 1, 10);
}

static std::vector<int> generateRandomVector0_5Wrapper(int size) {
    return generateRandomVector(size, 0, 5, true);
}

static std::vector<int> generateRandomVector0_4000Wrapper(int size) {
    return generateRandomVector(size, 0, 4000, true);
}

static std::vector<int> generateReversedVectorWrapper(int size) {
    return generateReversedVector(size);
}

static std::map<ArrayType, GeneratorWrapper> generator_mapping = {
        {RANDOM_VALUES_0_5,    generateRandomVector0_5Wrapper},
        {RANDOM_VALUES_0_4000, generateRandomVector0_4000Wrapper},
        {HALF_SORTED,          generateHalfSortedVectorWrapper},
        {REVERSED_SORTED,      generateReversedVectorWrapper}
};