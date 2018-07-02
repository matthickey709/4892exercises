#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
using namespace std;


/**
 * Time the execution of a factorial function.
 *
 * Students using g++ on Windows should modify this function as shown in
 * https://www.engr.mun.ca/~anderson/teaching/4892/exercises/0-intarray/windows-time.
 */
void timeFactorialFunction(std::function<long (int)>, int n);


//! Calculate the factorial of a number, recursively.
long recursive(int n);

//! Calculate the factorial of a number, iteratively.
long iterative(int n);


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cerr << "Usage:  " << argv[0] << " <n>\n";
		return 1;
	}

	char *end;
	int n = strtol(argv[1], &end, 10);
	if (*end != '\0')
	{
		cerr << "Invalid value of n: '" << argv[1] << "'\n";
		return 1;
	}

	cout << "Recursive: ";
	timeFactorialFunction(recursive, n);

	cout << "Iterative: ";
	timeFactorialFunction(iterative, n);

	return 0;
}


void timeFactorialFunction(std::function<long (int)> f, int n)
{
	long result;

	auto start = chrono::high_resolution_clock::now();
	result = f(n);
	auto end = chrono::high_resolution_clock::now();

	cout << "Calculated " << n << "! = " << result
		<< " in " << (end - start).count() << " ns\n";
}

long recursive(int n) {
	if(n <= 1) {
		return 1;
	} else {
		return n * recursive(n-1);
	}
}

long iterative(int n) {
	long answer = 1;
	for(int i = 0; i < n; i++) {
		answer *= (i + 1);
	}

	return answer;
}
