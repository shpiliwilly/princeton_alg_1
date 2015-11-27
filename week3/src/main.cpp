#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

#include "sort.h"


std::chrono::milliseconds testSort(unsigned size) {
//    std::vector<int> arr(size);
 //   for(auto i = 0; i < size; i++) {
  //      arr[i] = std::rand() % 1000;
   // }
    std::list<int> lst;
    for(auto i = 0; i < size; i++) {
        lst.push_back(std::rand() % 1000);
    }


    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    // my::insertion_sort(arr.begin(), arr.end());
    // my::merge_sort_recursive(arr.begin(), arr.end());
    // my::bottom_up_mergesort(arr.begin(), arr.end());
    my::list_mergesort(lst.begin(), lst.end());

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
}

template <typename RandomAccessIterator>
void printRange(const char* prefix, RandomAccessIterator first, RandomAccessIterator last) {
    std::cout << prefix;
    while(first != last)
        std::cout << *(first++) << ", ";
    std::cout << std::endl;
}

int main() {

    std::srand(std::time(0));


    std::list<int> test_list = { 127, -23, 8432, 0, 23, 45, 234, -15, -54, 32, 64, 234, 756, 67, 234, 0, 45, 765, 4, 65};
    printRange("before: ", test_list.begin(), test_list.end());
    my::list_mergesort(test_list.begin(), test_list.end());
    printRange("after:  ", test_list.begin(), test_list.end());
    return 0;

    std::vector<unsigned> sizes = {100000, 200000, 400000};
        for(auto sizeIt = sizes.begin(); sizeIt != sizes.end(); sizeIt++) {
        auto durationMs = testSort(*sizeIt);
        std::cout << "size =     " << *sizeIt << std::endl;
        std::cout << "duration(ms) = " << durationMs.count() << std::endl;
        std::cout << "================================" << std::endl;
    }

    return 0;
}

