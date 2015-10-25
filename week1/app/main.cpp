#include <iostream>
#include "quick_union.h"

int main() {
    QuickUnion oUnion(10);

    std::cout << oUnion.connected(2, 3) << std::endl;
    return 0;
}
