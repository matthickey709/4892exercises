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

#include <iostream>
#include "templates.h"
#include <string>
#include <vector>
using namespace std;


int main()
{
	double x = 1.0, y = 1.0;
	cout << "Double x + y = " << add(x, y) << "\n";

	int a = 1, b = 1;
	cout << "Integer a + b = " << add(a, b) << "\n";

	float c = 1.0, d = 1.0;
	cout << "Float c + d = " << add(c, d) << "\n";

	long e = 1, f = 1;
	cout << "Long e + f = " << add(e, f) << "\n";

	cout << "The average of doubles {1,2,3,4} is " << average<double>({1,2,3,4}) << "\n";
	cout << "The average of ints {1,2,3,4} is " << average<int>({1,2,3,4}) << "\n";
	// can't do this with strings because you cannot use the / operator with strings
	// cout << "The average of strings {1,2,3,4} is " << average<string>({"1","2","3","4"}) << "\n";


	GrowableArray<int> intArray;
	GrowableArray<string> stringArray;
	GrowableArray<double> doubleArray;

	intArray << 8;
	cout << intArray[0] << "\n";

	stringArray << "Hello There!!";
	cout << stringArray[0] << "\n";

	doubleArray << 555.5;
	cout << doubleArray[0] << "\n";






	return 0;
}
