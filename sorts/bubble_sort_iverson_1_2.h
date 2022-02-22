//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <utility>

/**
    Bubble sort with the 1st and the 2nd Iverson's criteria.
    @param array std::vector<int> pointer to array we want to sort.
*/
void bubbleSortIverson1_2(std::vector<int> *array) {
    bool swapped; // Flag indicates whether some elements were swapped during the cycle.
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
            break; // If there were no swaps during the cycle - consider the array was sorted.
        }
    }
}