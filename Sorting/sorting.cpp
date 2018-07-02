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


/* Exercise Answers Part 2

	Question 1:
		After analysis of the worst-case run-time for my implementation of
		insertionSort, I did discover that it is indeed O(n^2). This is due to
		a while loop that will iterate over every element nested inside a for
		loop that will iterate through every element. I tried this with different
		worst case array sizes (in opposite order) and the graph i plotted proved
		a quadratic relationship between elements and run time.

*/

#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include "sorting.h"

using namespace std;


template<typename T>
ostream& operator << (ostream& o, const vector<T>& v)
{
	o << "[";
	for (const auto& x : v)
	{
		o << " " << x;
	}
	o << " ]";

	return o;
}

template<typename T>
ostream& operator << (ostream& o, const vector<unique_ptr<T>>& v)
{
	o << "[";
	for (const auto& x : v)
	{
		o << " " << *x;
	}
	o << " ]";

	return o;
}




int main()
{
	// Initialize random number generator:
	srand(time(NULL));

	vector<int> numbers = { 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 4, 2, 1 };
	auto start = std::chrono::high_resolution_clock::now();
	radixSort(numbers.begin(), numbers.end(), std::less<int>());
	auto end = std::chrono::high_resolution_clock::now();

	cout << "Sorted: " << numbers << "\n";
	cout << " (took " << (end - start).count() << " µs)\n";

	vector<string> names = { "Zack", "Xi", "Victoria", "Ursula", "Uav", "Tom", "Timothy", "Steve", "Ryker", "Robin", "Olivia", "Nicola", "Nathaniel", "Matt", "Joe", "Jill", "Eve", "Bob", "Alice", "Alex" };
	start = std::chrono::high_resolution_clock::now();
	insertionSort(names.begin(), names.end(), std::less<string>());
	end = std::chrono::high_resolution_clock::now();


	cout << "Sorted: " << names << "\n";
	cout << " (took " << (end - start).count() << " µs)\n";

	vector<unique_ptr<string>> uniqueNames;
	uniqueNames.emplace_back(new string("Beorn"));
	uniqueNames.emplace_back(new string("Aiken"));

	insertionSort(uniqueNames.begin(), uniqueNames.end(),
		//
		// std::less<unique_ptr<string>>() will end up comparing pointer
		// values rather than string characters, so let's implement our
		// own comparison function:
		//
		[](const unique_ptr<string> &a, const unique_ptr<string>& b)
		{
			return (*a < *b);
		});

	cout << "Sorted: " << uniqueNames << "\n";


	return 0;
}
