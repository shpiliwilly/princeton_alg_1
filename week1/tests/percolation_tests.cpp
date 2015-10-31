#include <gtest/gtest.h>
#include "../app/percolation.h"

TEST(Percolation, init) {
    Percolation perc(3);
    ASSERT_FALSE(perc.percolates());
    perc.open(1, 1);
    ASSERT_FALSE(perc.percolates());
    perc.open(2, 1);
    ASSERT_FALSE(perc.percolates());
    perc.open(3, 2);
    ASSERT_FALSE(perc.percolates());
    perc.open(3, 3);
    ASSERT_TRUE(perc.percolates());
}


