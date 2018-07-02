/* *****************************************************************************
 * Student: Matthew Hickey - 201548278
 * Prof: Jon Anderson
 * Due Date: May 14, 2018
 * Submission Type: Exercise
 * ****************************************************************************/


/* Question 1

Values used for investigation:
100, 500, 1000, 5000, 10000, 50000, 100000, 5000000, 1000000, 1000000000
These values were chosen as they cover a large range of data, all the way from
one hundred to one billion.

Graphing the results illustrates the linear relation of WorkingSize to processing
time. This was expected, as it would make sense for processing time to increase
at around the same rate as the amount of data to process.

*/

/*
Question 2

See the plot for results for processing time with various WorkingSize values.
The results remained consistent with Question 1, as the plot was linear. However,
it was somewhat unexpected that it would take longer to insert a value at the same
position in different sized arrays, as the position remains the same each time. Upon
further reflection, it makes sense - as it needs to retreive larger amounts of data from
memory, even though it isn't "working" on the entire array.
*/

#include <chrono>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


class IntegerArray
{
public:
	IntegerArray()
	{
	}

	IntegerArray(std::initializer_list<int> init)
		: values_(init)
	{
	}

	IntegerArray(std::vector<int>&& v)
		: values_(std::move(v))
	{
	}

	std::vector<int>::const_iterator begin() const
	{
		return values_.begin();
	}

	std::vector<int>::const_iterator end() const
	{
		return values_.end();
	}

	std::vector<int>::iterator insert(int v, size_t pos) {
		auto position = values_.begin() + pos;
		return values_.insert(position, v);
	}

	IntegerArray& operator << (int n)
	{
		values_.push_back(n);
		return *this;
	}

	size_t size() const
	{
		return values_.size();
	}


private:
	std::vector<int> values_;
};

std::ostream& operator << (std::ostream&, const IntegerArray&);



int main()
{
	cout << "Hello, world!\n";

	IntegerArray a = { 1, 2, 3 };
	cout << a;

	IntegerArray b;
	constexpr size_t WorkingSize = 1000000000;

	// Initialize random number generator:
	srand(time(NULL));

	for (int i = 0; i < WorkingSize; i++)
	{
		b << (rand() % WorkingSize);
	}

	//
	// Find an arbitrary number:
	//
	bool foundIt = false;
	int index = 0;

	auto start = std::chrono::high_resolution_clock::now();
	for (int value : b)
	{
		if (value == 42)
		{
			foundIt = true;
			break;
		}

		index++;
	}
	auto end = std::chrono::high_resolution_clock::now();

	if (foundIt)
	{
		cout << "found the value 42 at index " << index;
	}
	else
	{
		cout << "42 is not in the IntegerArray b";
	}

	cout << " (took " << (end - start).count() << " µs)\n";

	//
	// Find the largest number:
	//
	start = std::chrono::high_resolution_clock::now();
	int largest = 0;
	for (auto i = b.begin(); i != b.end(); i++)
	{
		if (*i > largest)
		{
			largest = *i;
		}
	}

	end = std::chrono::high_resolution_clock::now();

	cout << "the largest value is: " << largest
	     << " (took " << (end - start).count() << " µs)\n";

	int insertVal = 26709;
	start = std::chrono::high_resolution_clock::now();
	b.insert(insertVal, 50);
	end = std::chrono::high_resolution_clock::now();
	cout << "added value " << insertVal << " to IntegerArray "
		 << " (took " << (end - start).count() << " µs)\n";

	return 0;
}


std::ostream& operator << (std::ostream& o, const IntegerArray& a)
{
	o << "[";
	for (int i : a)
	{
		o << " " << i;
	}
	o << " ]\n";

	return o;
}
