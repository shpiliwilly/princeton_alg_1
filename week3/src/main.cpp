#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "sort.h"


std::chrono::milliseconds testSort(unsigned size) {
    std::vector<int> arr(size);
    for(auto i = 0; i < size; i++) {
        arr[i] = std::rand() % 1000;
    }

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    my::insertion_sort(arr.begin(), arr.end());
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
}


int main() {
    std::srand(std::time(0));

    std::vector<unsigned> sizes = {10000, 20000, 40000, 80000, 160000, 320000};
        for(auto sizeIt = sizes.begin(); sizeIt != sizes.end(); sizeIt++) {
        auto durationMs = testSort(*sizeIt);
        std::cout << "size =     " << *sizeIt << std::endl;
        std::cout << "duration(ms) = " << durationMs.count() << std::endl;
        std::cout << "================================" << std::endl;
    }

    return 0;
}

