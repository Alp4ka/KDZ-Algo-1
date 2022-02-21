//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "../generators.h"
#include "../generator_wrappers.h"
#include "sorts/sorts.h"
#include "definitions.h"

class CalculationRow {
public:
    typedef void (*SortFunction)(std::vector<int> *);

private:
    int vector_size;
    std::map<ArrayType, std::vector<int>> arrays_;
    std::map<std::string, std::map<ArrayType, double>> results_;
    std::map<std::string, CalculationRow::SortFunction> sorts_
            {
                    {SELECTION_SORT,          selectionSort},
                    {BUBBLE_SORT_SIMPLE,      bubbleSort},
                    {BUBBLE_SORT_IVERSON_1,   bubbleSortIverson1},
                    {BUBBLE_SORT_IVERSON_1_2, bubbleSortIverson1_2},
                    {INSERTION_SORT_SIMPLE,   insertionSortSimple},
                    {INSERTION_SORT_BINARY,   insertionSortBinary},
                    {COUNT_SORT,              countingSort},
                    {RADIX_SORT,              radixSort},
                    {MERGE_SORT,              mergeSort},
                    {QUICK_SORT_HOARE,        quickSortHoare},
                    {QUICK_SORT_LOMUTO,       quickSortLomuto},
                    {HEAP_SORT,               heapSort},
            };

public:
    CalculationRow() {
    }

    explicit CalculationRow(int size) {
        vector_size = size;
        for (const auto &generator_pair: generator_mapping) {
            arrays_[generator_pair.first] = generator_pair.second(size);
        }
    }

    double run(SortFunction sort, ArrayType array_type) {
        std::vector<int> vector_to_sort = std::vector<int>(arrays_[array_type]);
        auto start_time = std::chrono::system_clock::now();
        sort(&vector_to_sort);
        auto finish_time = std::chrono::system_clock::now();
        std::chrono::duration<double> difference = finish_time - start_time;
        if (!std::is_sorted(vector_to_sort.begin(), vector_to_sort.end())) {
            throw std::exception("Failed to sort array!");
        }
        return difference.count();
    }

    void start() {
        for (const auto &sorts_pair: sorts_) {
            for (int array_type = ArrayType::RANDOM_VALUES_0_5;
                 array_type != ArrayType::REVERSED_SORTED + 1; ++array_type) {
                results_[sorts_pair.first][static_cast<ArrayType>(array_type)] = run(
                        sorts_pair.second, static_cast<ArrayType>(array_type));
            }
        }
    }

    void clear() {
        arrays_.clear();
    }

    const std::map<std::string, std::map<ArrayType, double>> &getResults() const {
        return results_;
    }

    int size() const {
        return vector_size;
    }
};

