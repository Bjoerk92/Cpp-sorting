#pragma once

#include <cstddef>
#include <utility>

template <typename T>
class Sorting {

private:

    /**
     * @brief Quikc sort range function
     * 
     * @param buf   pointer to the buffer that need sorting
     * @param low   Lowest index in range
     * @param high  highest index in range
     */
    void QuickSortRange(T* buf, std::size_t low, std::size_t high) const
    {
        if (high - low < 2)
        {
            return;
        }

        const T pivot = buf[low + (high - low) / 2];
        std::size_t less = low;
        std::size_t current = low;
        std::size_t greater = high;
        using std::swap;

        while (current < greater)
        {
            if (buf[current] < pivot)
            {
                swap(buf[less], buf[current]);
                ++less;
                ++current;
            }
            else if (pivot < buf[current])
            {
                --greater;
                swap(buf[current], buf[greater]);
            }
            else
            {
                ++current;
            }
        }

        // sort the left side
        QuickSortRange(buf, low, less);
        // sort the right side
        QuickSortRange(buf, greater, high);
    }

public:
    /**
     * @brief Bubble sort
     * 
     * @param buf pointer to any buffer of type T
     * @param num_elm number of element in buffer to be sorted.
     */
    void BubbleSort(T* buf, std::size_t num_elm) const
    {
        for (std::size_t end = num_elm; end > 1; --end)
        {
            for (std::size_t i = 0; i + 1 < end; ++i)
            {
                if (buf[i] > buf[i + 1])
                {
                    T temp = buf[i];
                    buf[i] = buf[i + 1];
                    buf[i + 1] = temp;
                }
            }
        }
    }

    /**
     * @brief Selection sort
     *  
     * @param buf pointer to the buffer needed sorting
     * @param num_elm number of element in buffer.
     */
    void SelectionSort(T* buf, std::size_t num_elm) const
    {
        for (std::size_t i = 0; i + 1 < num_elm; ++i)
        {
            std::size_t lowest_index = i;

            for (std::size_t j = i + 1; j < num_elm; ++j)
            {
                if (buf[j] < buf[lowest_index])
                {
                    lowest_index = j;
                }
            }

            if (lowest_index != i)
            {
                T temp = buf[i];
                buf[i] = buf[lowest_index];
                buf[lowest_index] = temp;
            }
        }
    }

    /**
     * @brief Insertion sort
     * 
     * @param buf pointer to buffer that need sorting
     * @param num_elm number of element in buffer
     */
    void InsertionSort(T* buf, std::size_t num_elm) const 
    {
        for (std::size_t i = 1; i < num_elm; ++i)
        {
            T key = buf[i];
            std::size_t j = i;

            while (j > 0 && buf[j - 1] > key)
            {
                buf[j] = buf[j - 1];
                --j;
            }

            buf[j] = key;
        }
    }

    /**
     * @brief Quick sort
     * 
     * @param buf pointer to the buffer that need sorting
     * @param low  Lowest index in the buffer
     * @param high highest index in the buffer
     */
    void QuickSort(T* buf, std::size_t low, std::size_t high) const
    {
        // The range is half-open: [low, high).
        if (low >= high)
        {
            return;
        }

        QuickSortRange(buf, low, high);
    }
    


};
