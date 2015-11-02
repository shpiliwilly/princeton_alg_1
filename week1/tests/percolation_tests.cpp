#include <gtest/gtest.h>
#include "../app/percolation.h"

TEST(Percolation, init) {
    Percolation perc(3);
    ASSERT_FALSE(perc.percolates());
}

TEST(Percolation, trivial) {
    Percolation perc(1);
    perc.open(1, 1);
    ASSERT_TRUE(perc.percolates());
}

TEST(Percolation, size2) {
    Percolation perc(2);
    perc.open(1, 1);
    ASSERT_FALSE(perc.percolates());
    perc.open(2, 2);
    ASSERT_FALSE(perc.percolates());
    perc.open(1, 2);
    ASSERT_TRUE(perc.percolates());
}

TEST(Percolation, size3) {
    Percolation perc(3);
    ASSERT_FALSE(perc.percolates());
    perc.open(1, 1);
    perc.open(1, 2);
    ASSERT_FALSE(perc.percolates());
    perc.open(2, 1);
    ASSERT_FALSE(perc.percolates());
    perc.open(3, 2);
    perc.open(3, 3);
    ASSERT_FALSE(perc.percolates());
    perc.open(2, 2);
    ASSERT_TRUE(perc.percolates());
}

