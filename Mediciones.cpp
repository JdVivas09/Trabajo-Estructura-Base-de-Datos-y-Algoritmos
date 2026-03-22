#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "Mediciones.h"

// Declaraciones de las funciones que ya tienes en tus otros .cpp
void quicksort(std::vector<std::string>& arr, int low, int high);
void heapSort(std::vector<std::string>& arr);
void avlSort(std::vector<std::string>& arr);

size_t calcularMemoria(const std::vector<std::string>& dataset) {
    size_t total = sizeof(dataset); // tamaño del objeto vector
    total += dataset.capacity() * sizeof(std::string); // memoria reservada para strings

    for (const auto& str : dataset) {
        total += str.capacity(); // memoria interna reservada por cada string
    }

    return total;
}

void ejecutarQuicksort(std::vector<std::string> dataset) {
    auto inicio = std::chrono::high_resolution_clock::now();

    if (!dataset.empty()) {
        quicksort(dataset, 0, static_cast<int>(dataset.size()) - 1);
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    size_t memoria = calcularMemoria(dataset);

    std::cout << "Resultado de Quicksort:" << std::endl;
    for (const auto& str : dataset) {
        std::cout << str << std::endl;
    }

    std::cout << "Tiempo de ejecucion de Quicksort: "
              << duracion.count() << " segundos" << std::endl;

    std::cout << "Memoria usada por Quicksort: "
              << memoria << " bytes" << std::endl;
}

void ejecutarHeapsort(std::vector<std::string> dataset) {
    auto inicio = std::chrono::high_resolution_clock::now();

    if (!dataset.empty()) {
        heapSort(dataset);
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    size_t memoria = calcularMemoria(dataset);

    std::cout << "Resultado de Heapsort:" << std::endl;
    for (const auto& str : dataset) {
        std::cout << str << std::endl;
    }

    std::cout << "Tiempo de ejecucion de Heapsort: "
              << duracion.count() << " segundos" << std::endl;

    std::cout << "Memoria usada por Heapsort: "
              << memoria << " bytes" << std::endl;
}

void ejecutarAVL(std::vector<std::string> dataset) {
    auto inicio = std::chrono::high_resolution_clock::now();

    if (!dataset.empty()) {
        avlSort(dataset);
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    size_t memoria = calcularMemoria(dataset);

    std::cout << "Resultado de AVL:" << std::endl;
    for (const auto& str : dataset) {
        std::cout << str << std::endl;
    }

    std::cout << "Tiempo de ejecucion de AVL: "
              << duracion.count() << " segundos" << std::endl;

    std::cout << "Memoria usada por AVL: "
              << memoria << " bytes" << std::endl;
}