#include <gtest/gtest.h>
#include "../app/quick_union.h"

TEST(QuickUnion, init) {
    unsigned size = 10;
    QuickUnion un(size);
    for(unsigned i = 0; i < size - 1; i++)
        for(unsigned j = i + 1; j < size; j++)
            ASSERT_FALSE(un.connected(i,j));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
