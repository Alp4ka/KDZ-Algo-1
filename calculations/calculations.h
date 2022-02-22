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

/**
    Class representation of table row. Contains timestamps of all types of defined sort algorithms
    of all specified type of arrays.
*/
class CalculationRow {
public:
    typedef void (*SortFunction)(std::vector<int> *);

private:
    // Vector size.
    int vector_size;

    // Arrays we want to test our algorithms on.
    std::map<ArrayType, std::vector<int>> arrays_;

    // Stores the timestamps of algorithms.
    std::map<std::string, std::map<ArrayType, int64_t>> results_;

    // Mapping kind of sort_name -> pointer_to_a_function
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

    /**
        Checks whether the array is sorted.
        @param array - array to check.
        @return true in case the vector is sorted.
    */
    static bool isSorted(std::vector<int>* array) {
        for (int index = 0; index < array->size() - 1; ++index) {
            if ((*array)[index] > (*array)[index + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
        Runs sort with a specified type of array.
        @param sort - sort function to run with.
        @param array_type - array type we want to sort.
        @return seconds spent on a sort algorithm.
    */
    int64_t run(SortFunction sort, ArrayType array_type) {
        std::vector<int> vector_to_sort = std::vector<int>(arrays_[array_type]);
        auto start_time = std::chrono::high_resolution_clock::now();
        sort(&vector_to_sort);
        auto finish_time = std::chrono::high_resolution_clock::now();
        auto difference = finish_time - start_time;
        if (!isSorted(&vector_to_sort)) {
            throw std::exception("Failed to sort array!");
        }
        return std::chrono::duration_cast<std::chrono::nanoseconds>(difference).count();
    }

    /**
        Starts calculation algorithm. Runs sort algorithms on a different types of arrays and
        sets its time results in results_ mapping.
    */
    void start() {
        for (const auto &sorts_pair: sorts_) {
            for (int array_type = ArrayType::RANDOM_VALUES_0_5;
                 array_type != ArrayType::REVERSED_SORTED + 1; ++array_type) {
                results_[sorts_pair.first][static_cast<ArrayType>(array_type)] = run(
                        sorts_pair.second, static_cast<ArrayType>(array_type));
            }
        }
    }

    /**
        Clears array in purpose to save the memory.
    */
    void clear() {
        arrays_.clear();
    }

    /**
        Get results of calculation.
        @return mapping where keys are sorts names defined in sorts/sorts.h and values are
        another mapping kind of ArrayType.value -> double(time spent on a sort algorithm of
        the specified array).
    */
    const std::map<std::string, std::map<ArrayType, int64_t>> &getResults() const {
        return results_;
    }

    /**
        Get input arrays.
        @return mapping of ArrayType.value -> std::vector<int> type.
    */
    const std::map<ArrayType, std::vector<int>> &getArrays() const {
        return arrays_;
    }

    /**
        Returns vector size for the current calculation.
        @return vector size for the current calculation.
    */
    int size() const {
        return vector_size;
    }
};

