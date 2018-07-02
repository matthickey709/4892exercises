/*
 * Copyright 2018 Jonathan Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


/*
    Analysis of merge sort run-time performance.

    See my pseudocode from the module questions:

    MergeSort(arr, start, end):
        find the middle
        firstHalf = MergeSort(start to middle)
        secondHalf = MergeSort(middle to end)

        return Merge(firstHalf, secondHalf)


    Merge(firstHalf, secondHalf):
        bigArray = combine(firstHalf, secondHalf)
        finalArray = []
        for every element in bigArray:
            for i in range(0, bigArray.size()):
                see if original number is smallest in set
                if it is, put in finalArray
        return finalArray




    There are 3 main steps in the recursive merge sort:
        1. Divide the array into halves
        2. Recursively sort subarrays that are halves of the original
        3. Merge the elements

    The combine step is dependent on the number of elements, while the division of the
    array will take a constant time regardless of size, therefore the complexity
    will be O(n) for those two operations.

    For step 2, it will need to recursively sort subarrays which are halves of the
    original array. Because this is recursive, the amount of times this step occurs is
    dependent on how many elements are in the array. An 8 element array will be halved
    3 times before there are 8 arrays of 1 element each. The relationship between
    the number of elements and how many times step 2 will occurr is log(base 2)n.
    When combining the run-time complexity for steps 1&3 with step 2, it yields the
    run-time complexity of O(nlogn).
*/


#include <vector>
#include <math.h>
#include <iostream>

template<typename Iter, typename Comparator>
void bubbleSort(const Iter& begin, const Iter& end, Comparator compareFn)
{
    // Not required for exercise!!
}

template<typename Iter, typename Comparator>
void insertionSort(const Iter& begin, const Iter& end, Comparator compareFn)
{
    // mark first element as sorted
    for(auto i = begin + 1; i != end; i++) {
        // Take out the current element
        auto currElement = std::move(*i);

        auto j = i - 1;
        while(j >= begin && compareFn(currElement, *j)) {
            *(j+1) = std::move(*j);
            j--;
        }

        *(j+1) = std::move(currElement);
    }

}

template<typename Iter, typename Comparator>
void radixSort(const Iter& begin, const Iter& end, Comparator compareFn)
{
    auto largestVal = std::move(*begin);
    // find the largest value in array
    for (auto i = begin; i != end; i++) {
        if (largestVal < *i) {
            largestVal = std::move(*i);
        }
    }


    // find number of digits in largestVal
    int maxDigits = log10(largestVal) + 1;


    // for every digit in the largest number, do the thing
    for (int i = 0, modulator = 10; i < maxDigits; i++, modulator *= 10) {
        // create array of 10 vectors to hold results from digit by digit sort
        std::vector<int> bucket [10];
        // for every element in the array
        for (auto iter = begin; iter != end; iter++) {
            int digitVal = *iter % modulator;
            digitVal /= pow(10, i);
            bucket[digitVal].emplace_back(std::move(*iter));
        }

        auto replacer = begin;
        for (int digit = 0; digit < 10; digit++) {
            auto digitVector = bucket[digit];
            for (auto val : digitVector) {
                *replacer = std::move(val);
                replacer++;
            }
        }

    }

}
