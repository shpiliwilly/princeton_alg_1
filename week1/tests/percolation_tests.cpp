#include <gtest/gtest.h>
#include "../app/percolation.h"

TEST(Percolation, init) {
    Percolation perc(3);
    ASSERT_FALSE(perc.percolates());
    perc.open(1, 1);
    std::cout <<"1"<<std::endl;
    ASSERT_FALSE(perc.percolates());
    perc.open(2, 1);
    std::cout <<"2"<<std::endl;
    ASSERT_FALSE(perc.percolates());
    perc.open(3, 2);
    std::cout <<"3"<<std::endl;
    ASSERT_FALSE(perc.percolates());
    perc.open(3, 3);
    std::cout <<"4"<<std::endl;
    ASSERT_TRUE(perc.percolates());
}


