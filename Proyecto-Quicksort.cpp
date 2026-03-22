#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int partition(std::vector<std::string>& vec, int low, int high) {
    std::string pivot = vec[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quicksort(std::vector<std::string>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quicksort(vec, low, pi - 1);
        quicksort(vec, pi + 1, high);
    }
}