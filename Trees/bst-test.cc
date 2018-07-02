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

#include "BST.h"

#include <iostream>


int main()
{
	BinarySearchTree<int> bst;

	bst.insert(6);
	bst.insert(4);
	bst.insert(2);
	bst.insert(7);
	bst.insert(9);
	bst.insert(1);
	bst.insert(3);
	bst.insert(3);

	std::cout << "min value: " << bst.min() << "\n";
	std::cout << "max value: " << bst.max() << "\n";



	bst.print();

	std::cout << "maxDepth is" << bst.maxDepth() <<  '\n';


	if (bst.contains(7))
		std::cout << "ya boiii" << '\n';
	if (!bst.contains(66))
		std::cout << "no boiiiii" << '\n';


	bst.printDot(std::cout);





	// attempt at an abstract data type in the tree, didn't work as planned...
	// bool heightCompare = [](int h1, int h2) {
	// 	return h1 < h2;
	// };
	//
	// BinarySearchTree<Bar, const heightCompare) > people;





	return 0;
}
