//
// Created by kisam on 21.02.2022.
//
#pragma once

#include <iostream>
#include <vector>


void countingSort(std::vector<int> *list) {
    if (list->size() <= 1) {
        return;
    }
    // Ищем макс. и мин. элементы.
    int max_element = (*list)[0];
    int min_element = (*list)[0];
    for (int i = 1; i < list->size(); ++i) {
        if ((*list)[i] > max_element) {
            max_element = (*list)[i];
        }
        if ((*list)[i] < min_element) {
            min_element = (*list)[i];
        }
    }
    // Сортируем.
    int storage_size = std::abs(max_element - min_element) + 1;
    int *count_storage = new int[storage_size]{};
    for (int i = 0; i < list->size(); ++i) {
        ++count_storage[(*list)[i] - min_element];
    }
    int current_index = 0;
    for (int i = 0; i < storage_size; ++i) {
        for (int j = 0; j < count_storage[i]; ++j) {
            (*list)[current_index++] = i + min_element;
        }
    }
    delete[] count_storage;
}



