#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Mediciones.h"

int main() {
    std::vector<std::string> dataset;
    std::ifstream file("dataset.txt");
    std::string data;

    while (std::getline(file, data)) {
        dataset.push_back(data);
    }

    file.close();

    /*ejecutarQuicksort(dataset);
    std::cout << std::endl;*/

    //ejecutarHeapsort(dataset);

    ejecutarAVL(dataset);

    return 0;
}