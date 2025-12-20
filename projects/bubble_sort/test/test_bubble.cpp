#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "io.hpp"
#include "sortings.hpp"

TEST(ArraysEqual, AnyElementsCount) {
    int actual[] = {1, 8, 2, 5, 3, 11};
    int expected[] = {1, 2, 3, 5, 8, 11};
    const int size = sizeof(actual) / sizeof(actual[0]);

    dersw::sortings::bubble_sort(actual, size);

    for (int i = 0; i < size; i++) {
        ASSERT_EQ(expected[i], actual[i])
        << "Массивы отличаются в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
