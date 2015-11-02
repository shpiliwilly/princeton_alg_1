#include <iostream>
#include <stdlib.h>
#include <time.h>   
#include "percolation.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        std::cerr << "invalid input" << std::endl;
        return 1;
    }

    srand (time(NULL));

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);
    PercolationStats stats(N, T);
    std::cout << "mean = " << stats.mean() << std::endl;

    return 0;
}
