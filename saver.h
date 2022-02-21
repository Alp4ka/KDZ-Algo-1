//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include "calculations/calculations.h"
#include "sorts/sorts.h"

class Saver {
private:
    static const char kSeparator = ',';

    std::vector<CalculationRow> rows_;

    std::vector<std::string> sorts_ =
            {
                    SELECTION_SORT,
                    BUBBLE_SORT_SIMPLE,
                    BUBBLE_SORT_IVERSON_1,
                    BUBBLE_SORT_IVERSON_1_2,
                    INSERTION_SORT_SIMPLE,
                    INSERTION_SORT_BINARY,
                    COUNT_SORT,
                    RADIX_SORT,
                    MERGE_SORT,
                    QUICK_SORT_HOARE,
                    QUICK_SORT_LOMUTO,
                    HEAP_SORT,
            };

    std::map<ArrayType, std::string> types_ = {
            {RANDOM_VALUES_0_5,    " - 0 to 5"},
            {RANDOM_VALUES_0_4000, " - 0 to 4000"},
            {HALF_SORTED,          " - half sorted"},
            {REVERSED_SORTED,      " - reversed"}
    };

    std::vector<std::string> generateHeader() {
        std::vector<std::string> result;
        result.emplace_back("Array size");
        for (const auto &array_type_name: types_) {
            for (const auto &sort_name: sorts_) {
                result.push_back(sort_name + array_type_name.second);
            }
        }
        return result;
    }

    template<class T>
    static void saveLine(std::ofstream &fout, std::vector<T> data, bool endline = false) {
        for (int i = 0; i < data.size(); ++i) {
            fout << data[i] << (i == data.size() - 1 ? ' ' : kSeparator);
        }
        if (endline) {
            fout << "\n";
        }
    }

public:
    Saver() {
    }

    void add(const CalculationRow &calculation) {
        rows_.push_back(calculation);
    }

    void save(const std::string &path) {
        std::ofstream file_output(path);
        saveLine(file_output, generateHeader(), true);
        for (auto row: rows_) {
            file_output << row.size() << kSeparator;
            for (const auto &array_type: types_) {
                for (auto sort_name: sorts_) {
                    file_output << std::fixed << std::setprecision(6)
                                << row.getResults().at(sort_name).at(array_type.first)
                                << kSeparator;
                }
            }
            file_output << "\n";
        }
        file_output.close();
    }
};