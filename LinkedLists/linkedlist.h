// Matthew Hickey exercise implementing my algorithim for removing elements that
// are divisible by 10 from linked lists and vectors.

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

template<typename T>
void deleteMultiplesof10(T& dataSet) {
    auto i = dataSet.begin();
    while(i != dataSet.end()) {
        if (!(*i % 10)) {
            auto temp = i;
            i = dataSet.erase(temp);
        }
        else {
            i++;
        }
    }
}


template<typename Iter>
void quickSort(Iter& begin, Iter& end) {
    // naively assume pivot is the last element in the list
    auto pivot = std::move(*end);

    // create lists for greater than and less than pivot
    std::list<int> less;
    std::list<int> greater;

    // loop through the whole array
    for(auto i = begin; i != end; i++) {
        if (*i < pivot) {
            less.emplace_back(std::move(*i));
        } else {
            greater.emplace_back(std::move(*i));
        }
    }

    quickSort(less.begin(), less.end());
    quickSort(greater.begin(), greater.end());

    // combine the two lists
    less.splice(less.end(), greater);

    // update iterators passed by reference
    begin = less.begin();
    end = less.end();


}
