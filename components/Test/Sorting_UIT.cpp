/**
 * @file Sorting_UIT.cpp
 * @author Anders (anders.bjoerk.unf@gmail.com)
 * @brief Unit testing the sorting algorithms.
 * @version 0.1
 * @date 2026-10-17
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <gtest/gtest.h>
#include <algorithm>
#include <array>
#include <cstdint>

#include "Sorting.hpp"

/**
 * @brief Construct a Test buble sort with a simple array.
 * 
 */
TEST(BubbleSort, SimpleTest)
{
    std::array<uint8_t, 10> arr = {10, 8, 9, 1, 3, 2, 4, 5, 6, 7};

    Sorting<uint8_t> sort;
    sort.BubbleSort(arr.data(), arr.size());

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

/**
 * @brief Construct a Test bubblesort for dublicates and subranges in the array
 * 
 */
TEST(BubbleSort, duplicates_and_subrange)
{
    std::array<uint32_t, 8> arr = {99, 4, 2, 4, 1, 2, 4, 88};

    Sorting<uint32_t> sort;
    sort.BubbleSort(arr.data(), 1, 7);

    EXPECT_EQ(arr.front(), 99);
    EXPECT_EQ(arr.back(), 88);
    EXPECT_TRUE(std::is_sorted(arr.begin() + 1, arr.end() - 1));
    EXPECT_EQ(arr, (std::array<uint32_t, 8>{99, 1, 2, 2, 4, 4, 4, 88}));
}

/**
 * @brief Construct a Test that test Quick Sort with a simple array
 * 
 */
TEST(QuickSort, SimpleTest)
{
    std::array<uint8_t, 10> arr = {10, 8, 9, 1, 3, 2, 4, 5, 6, 7};

    Sorting<uint8_t> sort;
    sort.QuickSort(arr.data(), 0, arr.size());

    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

/**
 * @brief Construct a Test that test Quick sort for dublicates and subrange.
 * 
 */
TEST(QuickSort, duplicates_and_subrange)
{
    std::array<uint32_t, 8> arr = {99, 4, 2, 4, 1, 2, 4, 88};

    Sorting<uint32_t> sort;
    sort.QuickSort(arr.data(), 1, 7);

    EXPECT_EQ(arr.front(), 99);
    EXPECT_EQ(arr.back(), 88);
    EXPECT_TRUE(std::is_sorted(arr.begin() + 1, arr.end() - 1));
}