//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

void bubbleSortIverson1_2(std::vector<int> *array) {
    bool swapped;
    for (int outer_iterator = 0; outer_iterator < array->size(); ++outer_iterator) {
        swapped = false;
        for (int inner_iterator = 0; inner_iterator < array->size() - outer_iterator - 1;
             ++inner_iterator) {
            if (array->at(inner_iterator) > array->at(inner_iterator + 1)) {
                std::swap(array->at(inner_iterator), array->at(inner_iterator + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}